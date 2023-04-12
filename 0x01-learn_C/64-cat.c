#include <stdio.h>
#include <stdlib.h>

main(argc, argv)/*cat: concatenate files*/
int argc;
char *argv[];
{
    FILE *fp, *fopen();

    if(argc==1)/*no args; copy stdin*/
        filecopy(stdin);
    else
        while(--argc>0)
            if((fp=fopen(*++argv, "r"))==NULL){
                fprintf(stderr, "cat: cannot open %s\n", *argv);
                exit(1);
            } else {
                filecopy(fp);
                fclose(fp);
            }
    exit(0);
}

filecopy(fp)/*copy file fp to stdout*/
FILE *fp;
{
    int c;

    while((c=getc(fp))!=EOF)
        putc(c, stdout);
}