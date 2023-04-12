#define _BUFSIZE 512
#define _NFILE 20 /*files that can be handled*/

typedef struct _iobuf{
    char *_ptr; /*next character posn*/
    int _cnt; /*numbe rof chars left*/
    char *_base; /*location of buffer*/
    int _flag; /*mode of file access*/
    int _fd; /*file descriptor*/
} FILE; /*the FILE "type" in stdlib*/
extern FILE _iob[_NFILE];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2]) /*stdin, stdout and stderr, as exists in C and UNIX*/

#define _READ 01 /*file open for reading*/
#define _WRITE 02 /*file open for writing*/
#define _UNBUF 04 /*file is unbuffered*/
#define _BIGBUF 010 /*big buffer allocated*/
#define _EOF 020 /*EOF has occurred on this file*/
#define _ERR 040 /*error has occurred on this file*/
#define NULL 0
#define EOF (-1)

#define getc(p) (--(p)->_cnt >=0 ? *(p)->_ptr++ & 0377 : _fillbuf(p))
#define getchar() getc(stdin)

#define putc(x, p) (--(p)->_cnt >=0 ? *(p)->_ptr++ = (x) : flushbuf((x), p))
#define putchar(x) putc(, stdout)