#include <stdio.h>

/**
*declaring struct type using structure tags
*/

//struct in global scope
//has attrs: name, age and salary
struct {
    char *name;
    int age;
    int salary;
} emp1, emp2;

int manager(void){
    //struct declared in local scope
    //exactly the same as the one in the global scope
    //waste of resources by duplication
    //what's next? bureaucracy?
    struct{
        char *name;
        int age;
        int salary;
    } manager;

    manager.age = 29;

    if (manager.age > 30) {
        manager.salary = 205000;
    } else {
        manager.salary = 195000;
    }
    return manager.salary;
}

//There's a fix; use a structure tag
 /**
 struct employee { //notice the `employee` tag
    char *name;
    int age;
    int salary; 
 };

 int manager(void){
     struct employee manager;
     //notice how `struct employee` type is invoked
     ...
 }

 int main(void){
     struct employee emp_1;
     struct employee emp_2;
     ...
 }
 */

 //demo...
 struct employee {
    char *name;
    int age;
    int salary;
};

int manager1(void) {
    struct employee manager1;

    manager1.age = 31;

    if (manager1.age > 30) {
        manager1.salary = 205000;
    } else {
        manager1.salary = 195000;
    }
    return manager1.salary;
}

int main(void){

    struct employee emp3, emp4;
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("Enter the salary of Emp_1...\n");
    scanf("%d", &emp1.salary);
    printf("Enter the salary of Emp_2...\n");
    scanf("%d", &emp2.salary);
    printf("Enter the salary of Emp_3...\n");
    scanf("%d", &emp3.salary);
    printf("Enter the salary of Emp_4...\n");
    scanf("%d", &emp4.salary);
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("Emp_1's salary is: %d\n", emp1.salary);
    printf("Emp_2's salary is: %d\n", emp2.salary);
    printf("Manager's salary is: %d\n", manager());
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("Emp_3's salary is: %d\n", emp3.salary);
    printf("Emp_4's salary is: %d\n", emp4.salary);
    printf("Manager1's salary is: %d\n", manager1());
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");
    printf("*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#-*#\n");

}