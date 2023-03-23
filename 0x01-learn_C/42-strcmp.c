#include <stdio.h>

void main(int argc, int *argv[]){
    if(argc!=3){
        printf("Usage: ./42-strcmp <string s> <string t>\n");
        return;
    }
    printf("%d", str_cmp(argv[1], argv[2]));
}

int str_cmp(s, t) /*return <0 if s<t, 0 if s==t else >0*/
char s[], t[];
{
    int i = 0;

    while(s[i]==t[i])
        if(s[i++]=='\0')
            return(0);
    return(s[i] - t[i]);
}