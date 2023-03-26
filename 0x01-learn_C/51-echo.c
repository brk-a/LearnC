#include <stdio.h>
#include <string.h>

void main(argc, argv)/*echo args; 3rd version*/
int argc;
char *argv[];
{
    while(--argc>0)
        printf((argc>1) ? "%s " : "%s\n", *++argv);
}