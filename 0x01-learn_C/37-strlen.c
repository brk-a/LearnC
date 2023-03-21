#include <stdio.h>

void main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: ./37-strlen <string>\n");
        return;
    }
    printf("String %s has length %d\n", argv[1], str_len(argv[1]));
}

int str_len(s) /*return length of a str*/
char *s;
{
    int n;

    for(n=0; *s!='\0'; s++)
        n++;
    return(n);
}