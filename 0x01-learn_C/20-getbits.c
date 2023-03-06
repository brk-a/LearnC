#include <stdio.h>

int main(int argc, int argv[]){
    if(argc!=4){
        printf("Usage: ./20-getbits <x> <p> <n>");
        return 0;
    }
    // int x, p, n = argv[1], argv[2], argv[3];
    printf("%d", getbits(argv[1], argv[2], argv[3]));
}

int getbits(x, p, n)
unsigned int x, p, n;
{
    return((x>>(p+1-n)) & ~(~0<<n));
}