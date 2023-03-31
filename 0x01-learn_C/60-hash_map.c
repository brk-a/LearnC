#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 100

struct nlist{ /*base table entry*/
    char *name;
    char *def;
    struct nlist *next; //next entry in chain
};

static struct nlist *hashtab[HASHSIZE]; //pointer table

hash(s) /*form hash value from string*/
char *s;
{
    int hashval;

    for(hashval=0; *s!='\0';)
        hashval += *s++;
    return(hashval % HASHSIZE);
}

struct nlist *lookup(s)/*look for s in hashtab*/
char *s;
{
    struct nlist *np;

    for(np=hashtab[hash(s)]; np!=NULL; np=np->next)
        if(strcmp(s, np->name)==0)
            return(np); //found s
        return(NULL); // not found
}

struct nlist *install(name, def)/*put (name, def) in hashtab*/
char *name, *def;
{
    struct nlist *np, *lookup();
    char *strsave(), *alloc();
    int hashval;

    if((np=lookup(name))==NULL){//not found
        np = (struct nlist *) alloc(sizeof(*np));
        if(np==NULL)
            return(NULL);

        if((np->name=strsave(name))==NULL)
            return(NULL);
        hashval = hash(np->name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /*already there*/
        free(np->def); // free previous definition
    
    if((np->def=strsave(def))==NULL)
        return(NULL);
    return(np);
}