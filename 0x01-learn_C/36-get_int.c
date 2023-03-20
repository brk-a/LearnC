#include <stdio.h>
#include "32-desk-calc.c" /*contains `getch` and `ungetch`*/

void main(){

}

int get_int(pn) /*get the next int from input*/
int *pn;
{
    int c, sign;

    while((c=getch())==' ' || c=='\n' || c=='\t')
        ; /*skip white space*/
    sign = 1;
    if(c=='+' || c=='-') {/*record sign*/
        sign = (c=='+') ? 1 : -1;
        c = getch();
    }
    for(*pn=0; c>='0' && c<='9'; c=getch())
        *pn = 10 * *pn + c - '0';
    *pn *= sign;
    if(c!=EOF)
        ungetch();
    return(c);
}