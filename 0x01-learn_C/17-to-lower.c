#include <stdio.h>

void main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage ./17-to-lower <string>\n");
        return;
    }
    printf("Input str: %s\nOutput str: %d", argv[1], lower(argv[1]));
}

int lower(c)
int c;
{
    if(c>='A' && c<='Z')
        return(c + 'a' - 'A');
    else
        return(c);
}