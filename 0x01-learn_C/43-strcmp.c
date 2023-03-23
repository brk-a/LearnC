#include <stdio.h>

void main(int argc, int *argv[]){
    if(argc!=3){
        printf("Usage: ./43-strcmp <string s> <string t>\n");
        return;
    }
    printf("%d", str_cmp(argv[1], argv[2]));
}

int str_cmp(s, t)/*return <0 if s<t, 0 if s==t else >0*/
char *s, *t;
{
    for(; *s==*t; s++, t++)
        if(*s=='\0')
            return(0);
    return(*s - *t);
}