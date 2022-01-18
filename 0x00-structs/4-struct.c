#include <stdio.h>

/**
*designated initialisation of structs in C
*/

//This type of initialisation allows a struct member to be initialised in any order

//par example...

/**
struct abc {
    int x;
    int y;
    int z;
};

int main(void) {
    struct abc a = {.y = 20, .z = 30, .x = 10}; //any order
    printf("%d,%d,%d\n",a.x, a.y, a.z);
}
*/

typedef struct car {
    char *engine;
    char *fuel_type;
    int fuel_capacity;
    int seating_capacity;
    float city_mileage;
}car;

int main (void) {
    car car1 = {.engine = "2500cc VVTi V6 24V", .fuel_type = "Petrol", .fuel_capacity = 37, .seating_capacity = 5, .city_mileage = 19.74};
    car car2 = {.seating_capacity = 4, .fuel_type = "Diesel", .fuel_capacity = 22, .city_mileage = 21.38, .engine = "2500cc CDi AMG"};
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("Car_1 specs:\nEngine: %s\nFuel type: %s\nFuel capacity: %d\nSeating capacity: %d\nCity mileage: %0.2f\n", car1.engine, car1.fuel_type,car1.fuel_capacity,car1.seating_capacity,car1.city_mileage);
    printf("=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_\n");
    printf("Car_2 specs:\nEngine: %s\nFuel type: %s\nFuel capacity: %d\nSeating capacity: %d\nCity mileage: %0.2f\n", car2.engine, car2.fuel_type,car2.fuel_capacity,car2.seating_capacity,car2.city_mileage);
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
}