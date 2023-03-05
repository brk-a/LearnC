#include <stdio.h>

void main(int argc, char *argv[]){
    if(argc!=3){
        printf("Usage: ./19-str_cat <string> <str_to_concat>");
        return;
    }
    printf("Input string: %s\nOutput string: %s", argv[1], str_cat(argv[1], argv[2]));
}

int str_cat(s,t)
char s[], t[];
{
    int i, j;
    i = j = 0;

    while(s[i]!='\0')
        i++;
    while((s[i++]=t[j++])!='\0')
        ;  
}