#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
    int yearday;
    char mon_name[];
};

static int day_tab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

day_of_year(pd)/* set day of year from month, day*/
struct  date *pd;
{
    int i, day, leap;

    day = pd->day;
    leap = pd->year % 4 == 0 && pd->year % 100 != 0 || pd->year % 400 == 0;

    for(i=1; i<pd->month; i++)
        day += day_tab[leap][i];
    return(day);
};

month_day(pd)/*set month and day from day of year*/
struct  date *pd;
{
    int i, leap;

    leap = pd->year % 4 == 0 && pd->year % 100 != 0 || pd->year % 400 == 0;
    pd->day = pd->yearday;

    for(i=1; pd->day>day_tab[leap][i]; i++)
        pd->day -= day_tab[leap][i];
    pd->month = i;
}

