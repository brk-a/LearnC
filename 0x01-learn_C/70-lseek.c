#include <stdio.h>
#include <stdlib.h>

get(fd, pos, buf, n) /*read n bytes from position pos*/
int fd, n;
long pos;
char *buf;
{
    lseek(fd, pos, 0); /* get to pos*/

    return(read(fd, buf, n));
}