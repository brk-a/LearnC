#include <stdio.h>

/**
*typical struct
*/

/**
struct {
    type atrribute_1;
    type atrribute_2;
    ...
    type atrribute_N
} var_1, var_2, ..., var_N;
*/

struct {
    char *engine;
    char *fuel_type;
    int fuel_capacity;
    int seating_capacity;
    float city_mileage;
}car1, car2;

int main(void){
    car1.engine = "2500cc VVTi V6 24V";
    car2.engine = "2500cc CDi AMG";
    printf("Car_1 engine is: %s\n", car1.engine);
    printf("Car_2 engine is: %s\n", car2.engine);
}