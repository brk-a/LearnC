#include <stdio.h>

void main(int argc, char *argv[]){
    if(argc!=3){
        printf("Usage: ./18-squeeze <string> <char_to_squeeze_out>");
        return;
    }
    printf("Input string: %s\nOutput string: %s", argv[1], squeeze(argv[1], argv[2]));
}

int squeeze(s, c)
char s[];
int c;
{
    int i, j;

    for(i=j=0; s[i]!='\0'; i++)
        if(s[i]!=c)
            s[j++] = s[i];
    s[j] = '\0';
}