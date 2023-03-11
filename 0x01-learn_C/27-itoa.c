#include <stdio.h>
#include <string.h>

void main(int argc, int argv[]){
    if(argc!=2){
        printf("Usage: ./27-itoa <int>");
        return;
    }
    printf("%s", itoa(10, argv[1]));
}

itoa(n, s)
char s[];
int n;
{
    int i, sign;

    if((sign=n)<0) /*record sign*/
        n = -n; /*make sign +ve*/
    i = 0;
    do
    {
        s[i++] = n % 10 + '0'; /*get next digit*/
    } while ((n/=10)>0); /*delete it*/

    if(sign<0)
        s[i++] = '-';
    s[i] = '\0';
    return(reverse(s));
    
}