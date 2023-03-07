#include <stdio.h>

int main(int argc, int argv[]){
    if(argc!=4){
        printf("Usage: ./22-three-way-decision <x> <v> <n>\n");
        return(1);
    }
    printf("%d", bin_search(argv[1], argv[2], argv[3]));
}

int bin_search(x, v, n)
int x, v[], n;
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    while(low<=high){
        mid = (low + high) / 2;
        if(x<v[mid])
            high = mid - 1;
        else if(x>v[mid])
            low = mid + 1;
        else
            return(mid);
    }
    return(-1);
}