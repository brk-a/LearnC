#include <stdio.h>

/**
*ptr to struct var in C
*/

/**
* Example
 typedef struct abc {
     int x;
     int y;
 }type_abc;

 int main(void){
     type_abc i = {0, 1};
     type_abc *ptr = &i;

     printf("%d, %d", ptr->x, ptr->y);
     return 0;
 }
*/

/**
* Another way...
 typedef struct abc {
     int x;
     int y;
 }type_abc;

 int main(void){
     type_abc i = {0, 1};
     type_abc *ptr = &i;

     printf("%d, %d", (*ptr).x, (*ptr).y);
     return 0;
 }
*/

/**
*How?
*Eaasy...
*You see, ptr = &i, no?
* so ptr->x, for example, is the same as (*ptr).x
*dereference the pointer first, then access the attr `x`, sawa?
*(*ptr).x is the same as (*&i).x
* `*` and `&` cancel out; so i.x which is the value `0`
*see? easy!
*/

typedef struct car {
    //char *engine;
    //char *fuel_type;
    int fuel_capacity;
    int seating_capacity;
    float city_mileage;
}car;

int main(void){
    car car1;
    car *ptr = &car1;
    /**
   car c[2];
    int i;
    for(i = 0; i < 2; i++){
        printf("Enter car_%d fuel tank capacity...\n", i+1);
        scanf("%d", &c[i].fuel_capacity);
        printf("Enter car_%d seating capacity...\n", i+1);
        scanf("%d", &c[i].seating_capacity);
        printf("Enter car_%d fuel type...\n", i+1);
        scanf("%s", &c[i].fuel_type);
        printf("Enter car_%d engine...\n", i+1);
        scanf("%s", &c[i].engine);
        printf("Enter car_%d city mileage...\n", i+1);
        scanf("%f", &c[i].city_mileage);
    }
    
    printf("\n");
    for(i = 0; i < 2; i++){
        printf("\nPrinting car_%d details...\n", i+1);
        printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
        printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
        printf("\nEngine: %s\nFuel type: %s\nFuel capacity: %d\nSeating capacity: %d\nCity mileage: %0.2f\n", c[i].engine, c[i].fuel_type,c[i].fuel_capacity,c[i].seating_capacity,c[i].city_mileage);
        printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
        printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    }
    */

    printf("Enter fuel tank cap for car...\n");
    scanf("%d", &car1.fuel_capacity);
    printf("Enter seating cap for car...\n");
    scanf("%d", &car1.seating_capacity);
    printf("Enter seating mileage for car...\n");
    scanf("%f", &car1.city_mileage);
    printf("\nPrinting car1 details...\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("\nFuel capacity: %d\nSeating capacity: %d\nCity mileage: %0.2f\n", ptr->fuel_capacity, ptr->seating_capacity, ptr->city_mileage);
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");

    return 0;
}