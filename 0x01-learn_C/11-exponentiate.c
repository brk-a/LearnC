#include <stdio.h>

/**
 * @brief perform exponentiation ops
 * on small, +ve numbers
 * ex. power(2,5) = 32
 * @x base
 * @n exponent
 * return: x raised to n
 */

void main(){
    int i;

    for (i=0; i<10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    
}

int power(x, n)
    int x, n; // same as `int power(int x, int n);`
{
    int i, p;
    p = 1;

    for (i=0; i<=n; ++i)
        p = p * x;
    return p;
    
}