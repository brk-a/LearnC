#include <stdio.h>

void main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage ./15-strlen <string>\n");
        return;
    }
    printf("String %s has length %d", argv[1], strlen(argv[1]));
}

int strlen(s)
char s[];
{
    int i;
    
    i = 0;
    while(s[i]!='\0')
        ++i;
    return(i);
}