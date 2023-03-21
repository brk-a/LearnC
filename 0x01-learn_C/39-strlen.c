#include <stdio.h>

void main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: ./39-strlen <string>\n");
        return;
    }
    printf("String %s has length %d\n", argv[1], str_len(argv[1]));
}

int str_len(s)/*return length of string s*/
char *s;
{
    char *p = s;

    while(*p)
        p++;
    return(p - s);
}