#include <stdio.h>
#define CMASK 0377 /* to make chars > 0 (ASCII and PDP-11 standards in 1978)*/
#define BUFSIZE 512 /*best size for PDP-11 UNIX as at 1978*/

get_char()/*buffered version of 67-getchar*/
{
    static char buf[BUFSIZE];
    static char *bufp = buf;
    static int n = 0;

    if(n==0){/*buffer is empty*/
        n = read(0, buf, BUFSIZE);
        bufp = buf;
    }

    return((--n >= 0) ? *bufp++ & CMASK : EOF);
}