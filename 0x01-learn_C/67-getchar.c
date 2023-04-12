#include <stdio.h>
#define CMASK 0377 /* to make chars > 0 (ASCII and PDP-11 standards in 1978)*/

get_char()/*unbuffered single char input*/
{
    char c;

    return((read(0, &c, 1) > 0) ? c & CMASK : EOF);
}