#include <stdio.h>

void main(int argc, int argv[]){
    if(argc!=3){
        printf("Usage ./35-swap_wrong <x> <y>");
        return;
    }
    printf("%d", swap(argv[1], argv[2]));
}

int swap(x, y) /*WRONG*/
int x, y;
{
    int temp;

    temp = x;
    x = y;
    y = temp;

    return(x, y);
}

/**
 * ALT swap method
 * 
 * x = x + y;
 * y = x - y;
 * x = x - y;
 * 
 */