#include <stdio.h>

/**
*initialising struc vars
*and accessing members
*/

/**
*incorrect way to initialise a struct
struct abc {
    int p = 23;
    int q = 45;
}; //the `p` and `q` should not be set to any value
*/

/**
*one correct way to initialise a struct
struct abc {
    int p;
    int q;
}; //the `p` and `q` are not set to any value

int main(void) {
    struct abc x = {23, 45} // p = 23 and q = 45
}
*/

//apply to the car example...
typedef struct car {
    char *engine;
    char *fuel_type;
    int fuel_capacity;
    int seating_capacity;
    float city_mileage;
}car;

int main (void) {
    car car1 = {"2500cc VVTi V6 24V", "Petrol", 37, 5, 19.74};
    car car2 = {"2500cc CDi AMG", "Diesel", 22, 4, 21.38};
    //2 cars: same properties/attributes, different values
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("Car_1 specs:\nEngine: %s\nFuel type: %s\nFuel capacity: %d\nSeating capacity: %d\nCity mileage: %0.2f\n", car1.engine, car1.fuel_type,car1.fuel_capacity,car1.seating_capacity,car1.city_mileage);
    printf("=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_\n");
    printf("Car_2 specs:\nEngine: %s\nFuel type: %s\nFuel capacity: %d\nSeating capacity: %d\nCity mileage: %0.2f\n", car2.engine, car2.fuel_type,car2.fuel_capacity,car2.seating_capacity,car2.city_mileage);
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    car1.fuel_capacity = 53;
    car2.fuel_capacity = 60;
    printf("Specs after using the dot operator to access attributes...\n");
    printf("Car_1 specs:\nEngine: %s\nFuel type: %s\nFuel capacity: %d\nSeating capacity: %d\nCity mileage: %0.2f\n", car1.engine, car1.fuel_type,car1.fuel_capacity,car1.seating_capacity,car1.city_mileage);
    printf("=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_-=_\n");
    printf("Car_2 specs:\nEngine: %s\nFuel type: %s\nFuel capacity: %d\nSeating capacity: %d\nCity mileage: %0.2f\n", car2.engine, car2.fuel_type,car2.fuel_capacity,car2.seating_capacity,car2.city_mileage);
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");

}