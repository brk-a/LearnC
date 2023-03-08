#include <stdio.h>

void main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: ./24-atoi <string-without-quotes>\n");
        return;
    }
    printf("%d", atoi(argv[1]));
}

int atoi(s)
char s[];
{
    int i, n, sign;

    for(i=0; s[i]==' ' || s[i]=='\n' || s[i]=='\t'; i++)
        ; /* skip white space*/
    sign = 1;
    if(s[i]=='+' || s[i]=='-') /*sign*/
        sign = (s[i++]='+') ? 1 : -1;
    for(n=0; s[i]>='0' && s[i]<='9'; i++)
        n = 10 * n + s[i] - '0';
    return(sign * n);
}