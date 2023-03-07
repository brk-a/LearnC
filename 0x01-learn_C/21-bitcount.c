#include <stdio.h>

int main(int argc, int argv[]){
    if(argc!=2){
        printf("Usage: ./21-bitcount <binary_digit>");
        return 0;
    }

    printf("%d\n", bitcount(argv[1]));
}

int bitcount(n)
unsigned n;
{
    int b;
    for(b=0; n!=0; n>>=1)
        if(n&01)
            b++;
    return(b);
}