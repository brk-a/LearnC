#include <stdio.h>

void main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage ./16-atoi <string>\n");
        return;
    }
    printf("String %s has value %d", argv[1], atoi(argv[1]));
}

int atoi(s)
char s[];
{
    int i, n;

    n = 0;
    for(i=0; s[i]>='0' && s[i]<='9'; ++i)
        n = 10 * n + s[i] - '0';
    return(n);
}