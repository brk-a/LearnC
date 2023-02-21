#include <stdio.h>
/*  print Far-Celsius table
for f = 0, 20 ... 300*/

void main() {
    int lower, upper, step;
    float fahr, celsius;
    lower = 0; //lower limit of temp table
    upper = 300; //upper limit of temp table
    step = 20; //step size
    fahr = lower;

    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%4.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    
}