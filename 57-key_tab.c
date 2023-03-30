#include <stdio.h>
#define MAXWORD 20
#define LETTER 'a'
#define DIGIT '0'
#define NKEYS (sizeof(keytab) /  sizeof(struct key))

struct key{
    int keycount;
    char *keyword;
} *keytab;

main()/*count C keywords; pointer version*/
{
    int t;
    char word[MAXWORD];
    struct key *binary(), *p;

    while((t=getword(word, MAXWORD))!=EOF)
        if(t==LETTER)
            if((p=binary(word, keytab, NKEYS))!=NULL)
                p->keycount++;
    
    for(p=keytab; p<keytab+NKEYS; p++)
        if(p->keycount>0)
            printf("%4d %s\n", p->keycount, p->keyword);
}

struct key *binary(word, tab, n)/*find word in tab[0]...tab[n-1]*/
char *word;
struct key tab[];
int n;
{
    int cond;
    struct key *low = &tab[0];
    struct key *mid;
    struct key *high = &tab[n-1];

    while(low<high){
        mid = low + (high - low) / 2;
        if((cond=strcmp(word, mid->keyword))<0)
            high = mid - 1;
        else if (cond>0)
            low = mid + 1;
        else
            return(mid);
    }
    return(NULL);
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
