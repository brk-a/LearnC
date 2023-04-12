#include <stdio.h>

void main(){/*snip of code for a rudimentary calculator*/
    double sum, v;

    sum = 0;
    while(scanf("%lf", &v)!=EOF)
        printf("\t%.2f\n", sum += v);
}