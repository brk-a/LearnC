#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void main(argc, argv)/*find pattern from first arg*/
int argc;
char *argv[];
{
    char line[MAXLINE];

    if(argc!=2)
        print("Usage: ./52-grep <pattern>\n");
    else
        while(getline(line, MAXLINE)>0)
            if(index(line, argv[1])>=0)
                print("%s", line);
}

/*grep -> generalised regex parser*/