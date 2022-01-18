#include <stdio.h>

/**
*declaring struct type using `typedef`
*/

//syntax: typedef existing_data_type new_data_type

/** 
*Valid struct declarations
* #1
struct {
    char *engine;
    char *fuel_type;
    int fuel_capacity;
    int seating_capacity;
    float city_mileage;
}car1, car2;

* #2
struct car {
    char *engine;
    char *fuel_type;
    int fuel_capacity;
    int seating_capacity;
    float city_mileage;
}car1, car2;

* #3
struct car {
    char *engine;
    char *fuel_type;
    int fuel_capacity;
    int seating_capacity;
    float city_mileage;
};

int main (void) {
    struct car car1;
    ...
}
*/

//Each has its downsides
//There's a fix for them all...typedef

typedef struct car { // old type is the  `struct car` tag
    char *engine;
    char *fuel_type;
    int fuel_capacity;
    int seating_capacity;
    float city_mileage;
}car; //new type is `car`

int main(void) {
    car car1, car2; //notice how I use `car` as a type; same way 
    //I'd use `int` or `char` etc
    car1.engine = "2500cc VVTi V6 24V";
    car2.engine = "2500cc CDi AMG";
    printf("Car_1 engine is: %s\n", car1.engine);
    printf("Car_2 engine is: %s\n", car2.engine);
}