#include <stdio.h>
#define NULL 0 /* ptr val for error report*/
#define ALLOCSIZE 1000 /* size of available space*/

static char allocbuf[ALLOCSIZE]; /*storage for alloc_bootleg*/
static char *alloccp_bootleg = allocbuf; /*next free posn*/

char *alloc_bootleg(n) /*return ptr to n chars*/
int n;
{
    if(alloccp_bootleg+n <= allocbuf+ALLOCSIZE){/*fits*/
        alloccp_bootleg += n;
        return(alloccp_bootleg - n); /*old p*/
    } else /*not enough room*/
        return(NULL);
}

free_bootleg(p) /*free storage pointed to by p*/
char *p;
{
    if(p>=allocbuf && p<allocbuf+ALLOCSIZE)
        alloccp_bootleg = p;
}
