#include <stdio.h>
#define MAXWORD 20
#define LETTER 'a'
#define DIGIT '0'
#define NKEYS (sizeof(keytab) /  sizeof(struct key))

struct key{
    int keycount;
    char *keyword;
} *keytab;

main() /*count C keywords*/
{
    int n, t;
    char word[MAXWORD];

    while((t=getword(word, MAXWORD))!=EOF)
        if(t==LETTER)
            if((n=binary(word, keytab, NKEYS))>=0)
                keytab[n].keycount++;

    for(n=0; n<NKEYS; n++)
        if(keytab[n].keycount>0)
            printf("%4d %s\n", keytab[n].keycount, keytab[n].keyword);
}

binary(word, tab, n)/*find word in tab[0]...tab[n-1]*/
char *word;
struct key tab[];
int n;
{
    int low, mid, high, cond;

    low = 0;
    high = n - 1;
    while(low<=high){
        mid = (low + high) / 2;
        if((cond=strcmp(word, tab[mid].keyword))<0)
            high = mid - 1;
        else if(cond>0)
            low = mid + 1;
        else
            return(mid);
    }
    return(-1);
}

getword(w, lim)/*get next word from input*/
char *w;
int lim;
{
    int c, t;

    if(type(c=*w++=getch())!=LETTER){
        *w = '\0';
        return(c);
    }

    while(--lim>0){
        t = type(c=*w++=getch());

        if(t!=LETTER && t!=DIGIT){
            ungetch(c);
            break;
        }
        *(w - 1) = '\0';
        return(LETTER);
    }
}

type(c)/*return type of ASCII chars only*/
int c;
{
    if(c>='a' && c<='z' || c>='A' && c<='Z')
        return(LETTER);
    else if(c>='0' && c<='9')
        return(DIGIT);
    else
        return(c);
}