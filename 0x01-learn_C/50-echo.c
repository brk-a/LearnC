#include <stdio.h>
#include <string.h>

void main(argc, argv) /*echo args, 2nd version*/
int argc;
char *argv[];
{
    while(--argc>0)
        printf("%s%c", *++argv, (argc>1) ? ' ' : '\n');
}