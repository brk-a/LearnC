#include <stdio.h>

/**
*Array of struct in C
*/

//each elem of the arr rep's a
//var of struct type

typedef struct car {
    //char *engine;
    //char *fuel_type;
    int fuel_capacity;
    int seating_capacity;
    float city_mileage;
}car;

int main(void) {
    car c[2]; //arr of type `car` that has 2 elems
    int i;
    for(i = 0; i < 2; i++){
        printf("Enter car_%d fuel tank capacity...\n", i+1);
        scanf("%d", &c[i].fuel_capacity);
        printf("Enter car_%d seating capacity...\n", i+1);
        scanf("%d", &c[i].seating_capacity);
        //printf("Enter car_%d fuel type...\n", i+1);
        //scanf("%s", &c[i].fuel_type);
        //printf("Enter car_%d engine...\n", i+1);
        //scanf("%s", &c[i].engine);
        printf("Enter car_%d city mileage...\n", i+1);
        scanf("%f", &c[i].city_mileage);
    }
    printf("\n");
    for(i = 0; i < 2; i++){
        printf("\nPrinting car_%d details...\n", i+1);
        printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
        printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
        printf("\nFuel capacity: %d\nSeating capacity: %d\nCity mileage: %0.2f\n", c[i].fuel_capacity,c[i].seating_capacity,c[i].city_mileage);
        printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
        printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    }

    return 0;
}