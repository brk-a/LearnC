#include <stdio.h>
#include <stdlib.h>
#include "38-alloc_and_free.c"

void main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: ./45-strsave <string s>\n");
        return;
    }
    printf("String %s has been saved at address %p", argv[1], str_save(argv[1]));
}

str_save(s){ /*incorrect use of pointers in str_save. declarations are missing*/
    char *p;

    if((p=alloc_bootleg(strlen(s)+1))!=NULL)
        strcpy(p, s);
    return(p);
}
