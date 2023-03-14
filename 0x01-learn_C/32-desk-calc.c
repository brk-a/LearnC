#include <stdio.h>
#define MAXOP 20 /*max size of operand, operator*/
#define NUMBER '0' /* signal that number found*/
#define TOOBIG '9' /*signal that string is too big*/
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch*/
int bufp = 0; /*next free position in buf*/

main(){ /*reverse polish desk calc*/
    int type;
    char s[MAXOP];
    double op2, atof(), pop(), push();

    while((type=getop(s, MAXOP))!=EOF)
        switch (type){
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2  = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if(op2!=0.0)
                push(pop() / op2);
            else
                printf("zero divisor popped\n");
            break;
        case '=':
            printf("\t%f\n", push(pop()));
            break;
        case 'c':
            clear();
            break;
        case TOOBIG:
            printf("%.20s ... is too long\n", s);
            break;
        default:
            printf("unknown command %c\n", type);
            break;
        }
}

getop(s, lim) /*get next operator or operand*/
char s[];
int lim;
{
    int i, c;

    while((c=getch())==' ' || c=='\t' || c=='\n')
        ;
    if(c!='.' && (c<'0' || c>'9'))
        return(c);
    s[0] = c;
    for(i=1; (c=getchar())>='0' && c<='9'; i++)
        if(i<lim)
            s[i] = c;
    if(c=='.'){ /*collect fraction*/
        if(i<lim)
            s[i] = c;
        for(i++; (c=getchar())>='0' && c<='9'; i++)
            if(i<lim)
                s[i] = c;
    }
    if(i<lim){/*number is OK*/
        ungetch(c);
        s[i] = '\0';
        return(NUMBER);
    } else {
        while(c!='\n' && c!=EOF)
            c = getchar();
        s[lim-1] = '\0';
        return(TOOBIG);
    }
}

getch(){/*get a possibly pushed back character*/
return((bufp > 0 ? buf[--bufp] : getchar()));
}

ungetch(c) /* push character back on input*/
int c;
{
    if(bufp>BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
