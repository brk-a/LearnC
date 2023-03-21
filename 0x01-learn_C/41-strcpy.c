#include <stdio.h>

void main(){}

str_cpy(s, t) /*copy t to s*/
char *s, *t;
{
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

/**
 * ALT way to write the `while`
 * 
 * while((*s++ = *t++) != '\0')
 *  ;
 */


/**
 * ALT way to write the `while`
 * 
 * while(*s++ == *t++)
 *  ;
 */