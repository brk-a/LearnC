#include <stdio.h>

/**
 * @brief call by value: demo
 */

void main(){
    for(int i=0; i<10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
}

int power(x, n)
    int x, n;
{
    int i, p;

    for(p=1; n>0; --n)
        p = p * x;
    return (p);
}