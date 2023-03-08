#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: ./26-reverse <string-w/o-quotes>\n");
        return;
    }
    printf("%s", reverse(argv[1]));
}

char reverse(s)
char s[];
{
    int c, i, j;

    for(i=0, j=strlen(s)-1; i<j; i++, j){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

    return(s);
}
