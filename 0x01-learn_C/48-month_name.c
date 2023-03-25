#include <stdio.h>

void main(int argc, int *argv[]){
    if(argc!=2){
        printf("Usage: 48-month_name <number>\n");
        return;
    }
    printf("%s", month_name(argv[1]));
}

char *month_name(n)/*return name of n-th month*/
int n;
{
    static char *name[] = {
        "illegal month",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    return((n < 1 || n > 12) ? name[0] : name[n]);
}