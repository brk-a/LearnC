#include "70-lseek.c"
#include "71-stdio_exerpt.c"

FILE _iob[_NFILE] = {
    {NULL, 0, NULL, _READ, 0}, /*stdin*/
    {NULL, 0, NULL, _WRITE, 1}, /*stdout*/
    {NULL, 0, NULL, _WRITE | _UNBUF, 2}, /*stdee*/
};

#define PMODE 0644

FILE *fopen(name, mode)/*open filee, return file ptr*/
register char *name, *mode;
{
    register int fd;
    register FILE *fp;

    if(*mode!='r' && *mode!='w' && *mode!='a'){
        fprintf(stderr, "illegal mode %s opening %s\n", mode, name);
        exit(1);
    }
    for(fp=_iob; fp<_iob+_NFILE; fp++)
        if((fp->_flag & (_READ | _WRITE))==0)
            break; /*found free slot*/
    if(fp>=_iob+_NFILE) /*no free slots*/
        return(NULL);

    if(*mode=='w')/*access file*/
        fd = creat(name, PMODE);
    else if(*mode=='a'){
        if((fd=open(name, 1))==-1)
            fd = creat(name, PMODE);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, 0);
    if(fd==-1)/*could not access name*/
        return(NULL);
    fp->_fd = fd;
    fp->_cnt = 0;
    fp->_base = NULL;
    fp->_flag &= ~(_READ | _WRITE);
    fp->_flag |= (*mode == 'r') ? _READ : _WRITE;
    return(fp);
}

_fillbuf(fp) /*allocate and fill input buffer*/
register FILE *fp;
{
    static char smallbuf[_NFILE]; /*for unbuffred I/O*/
    char *_calloc();
    
    if((fp->_flag & _READ)==0 || (fp->_flag & (_EOF | _ERR))!=0)
        return(EOF);
    while(fp->_base==NULL)/*find buffer space*/
        if(fp->_flag&_UNBUF)/*unbuffered*/
            fp->_base = &smallbuf[fp->_fd];
        else if((fp->_base=_calloc(_BUFSIZE, 1))==NULL)
            fp->_flag |= _UNBUF; /*cannot get big buf*/
        else
            fp->_flag |= _BIGBUF; /*got big one*/
    fp->_ptr = fp->_base;
    fp->_cnt = read(fp->_fd, fp->_ptr, fp->_flag & _UNBUF ? 1 : _BUFSIZE);

    if(--fp->_cnt<0){
        if(fp->_cnt==-1)
            fp->_flag |= EOF;
        else
            fp->_flag |= _ERR;
        fp->_cnt = 0;
        return(EOF);
    }
    return(*fp->_ptr++ & 0377); /*make char positive*/
}