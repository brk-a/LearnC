#include <stdio.h>

void main(){}

str_cpy(s, t) /*copy t to s*/
char s[], t[];
{
    int i;

    i = 0;
    while((s[i]=t[i]) != '\0')
        i++;
}

/**
 * ALT way to write the `while`
 * 
 * while((s[i++] = t[i++]) != '\0')
 *  ;
 */


/**
 * ALT way to write the `while`
 * 
 * while(s[i++] == t[i++])
 *  ;
 */