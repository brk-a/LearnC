#include <stdio.h>
#include <string.h>
#include "47-line_sort.c"
#define LINES 100 /*max number of lines to be sorted*/

main(argc, argv)/*sort input lines*/
int argc;
char *argv[];
{
    char *lineptr[LINES]; /*ptrs to text lines*/
    int nlines; /*number of input lines read*/
    int strcmp(), numcmp(); /*comparison functions*/
    int swap(); /*exchange function*/
    int numeric = 0; /*1 if numeric sort*/

    if(argc>1 && argv[1][0]=='-' && argv[1][1]=='n')
        numeric = 1;
    if((nlines=readlines(lineptr, LINES))>=0){
        if(numeric)
            sort(lineptr, nlines, numcmp, swap);
        else
            sort(lineptr,nlines, strcmp, swap);
            writelines(lineptr, nlines);
    } else
        printf("input too big to sort\n");
}

sort(v, n, comp, exch)/*sort strings v[0]...v[n-1] by increasing order*/
char *v[];
int n;
int (*comp)(), (*exch)();
{
    int gap, i, j;

    for(gap=n/2; gap>0; gap/=2)
        for(i=gap; i<n; i++)
            for(j=i-gap; j>=0; j-=gap){
                if((*comp)(v[j+gap])<=0)
                    break;
                (*exch)(&v[j], &v[j+gap]);
            }
}

numcmp(s1, s2)/*compare s1 and s2 numerically*/
char *s1, *s2;
{
    double atof(), v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if(v1<v2)
        return(-1);
    else if(v1>v2)
        return(1);
    else
        return(0);
}

swap(px, py) /*interchange *px and *py */
char *px[], *py[];
{
    char *temp;

    temp = *px;
    *px = *py;
    *py = temp;
}