#include <stdio.h>
#include <string.h>
#include "38-alloc_and_free.c"
#define LINES 100 /*max lines to be sorted*/
#define MAXLEN 1000 

main(){/*sort input lines*/
    char *lineptr[LINES]; /*ptrs to text lines*/
    int nlines; /*no. of input lines read*/

    if((nlines=readlines(lineptr, LINES))>=0){
        sort(lineptr, nlines);
        writelines(lineptr, nlines);
    } else
        printf("input too big to sort\n");
}

readlines(lineptr, maxlines)/*read input lines*/
char *lineptr[]; /*for sorting*/
int maxlines;
{
    int len, nlines;
    char *p, *alloc_bootleg(), line[MAXLEN];

    nlines = 0;
    while((len=get_line(line, MAXLEN))>0)
        if(nlines>=maxlines)
            return(-1);
        else if((p=alloc_bootleg(len))==NULL)
            return(-1);
        else{
            line[len-1] = '\0'; /*zap newline*/
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return(nlines);
}

writelines(lineptr, nlines)/*write output lines*/
char *lineptr[];
int nlines;
{
    int i;

    for(i=0; i<nlines; i++)
        printf("%s\n", lineptr[i]);
}

/**
 * ALT way to write `writelines`
 * 
 * writelines(lineptr, nlines)//write output lines
 * char *lineptr[];
 * int nlines;
 * {
    while(--nlines>=0)
        printf("%s\n", *lineptr++);
 * }
 */

sort(v, n)/*sort strings v[0] v[n-1] by increasing order*/
char *v[];
int n;
{
    int gap, i, j;
    char *temp;

    for(gap=n/2; gap>0; gap/=2)
        for(i=gap; i<n; i++)
            for(j=i-gap; j>=0; j-=gap){
                if(strcmp(v[j], v[j+gap])<=0)
                    break;
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }

}