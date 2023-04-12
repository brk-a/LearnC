#include <stdio.h>
#include <ctype.h>

void main(){/* convert output to lowercase*/
    
    // if(argc!=2){
    //     printf("Usage: ./61-lower <string>");
    //     return;
    // }

    // int c = (int) *argv[1];
    int c;

    while((c=getchar())!=EOF)
        putchar(isupper(c) ? tolower(c) : c);
}