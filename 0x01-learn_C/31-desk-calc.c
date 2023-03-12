#include <stdio.h>
#define MAXLINE 100

void main(){
    double sum, atof();
    char line[MAXLINE];

    sum = 0;
    while(get_line(line, MAXLINE)>0)
    printf("\t%.2f\n", sum += atof(line));
}

double atof(s)
char s[];
{
    double val, power;
    int i, sign;

    for(i=0; s[i==' '] || s[i]=='\n' || s[i]=='\t'; i++)
        ; /*skip whitespace*/
    sign = 1;
    if(s[i]=='+' || s[i]=='-')
        sign = (s[i++]=='+') ? 1 : -1;
    for(val=0; s[i]>='0' && s[i]<='9'; i++)
        val = 10 * val + s[i] - '0';
    if(s[i]=='.')
        i++;
    for(power=1; s[i]>='0' && s[i]<='9'; i++){
        val = 10 * val + s[i] - '0';
        power *= 10;
    }
    return(sign * val / power);
}