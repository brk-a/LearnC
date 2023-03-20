#include <stdio.h>

void main(int argc, int argv[]){
    if(argc!=3){
        printf("Usage ./35-swap <x> <y>");
        return;
    }
    printf("%d", swap(&argv[1], &argv[2]));
}

int swap(px, py) /*interchange *px and *py*/
int *px, *py;
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;

    return(*px, *py);
}

/**
 * ALT swap method:
 * px = px + py;
 * py = px - py
 * px = px - py;
 * 
 */