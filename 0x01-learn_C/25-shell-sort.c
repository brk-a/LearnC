#include <stdio.h>

void main(int argc, int *argv[]){
    if(argc!=2){
        printf("Usage: ./25-shell-sort <array>");
        return;
    }
    printf("%d", shell(argv[1]));
}

int shell(v, n)
int v[], n;
{
    int gap, i, j, temp;

    for(gap=n/2; gap>0; gap/=2)
        for(i=gap; i<n; i++)
            for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
    return(*v);
}