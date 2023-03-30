#include <stdio.h>
#define MAXWORD 20
#define LETTER 'a'

struct tnode /*the base node*/
{
    char *word; //points to the text
    int count; //number of occurrences
    struct tnode *left; //points to left child
    struct tnode *right; //points to right child
};

main(){ /*word frequency count*/
 struct tnode *root, *tree();
 char word[MAXWORD];
 int t;

 root = NULL;
 while((t=get_word(word, MAXWORD))!=EOF)
    if(t==LETTER)
        root = tree(root, word);
    treeprint(root);
}

struct tnode *tree(p, w)/*install w at or below p*/
struct tnode *p;
char *w;
{
    struct tnode *talloc();
    char *strsave();
    int cond;

    if(p==NULL){/*new word que a chegar; make a new node*/
        p = talloc();
        p->word = strsave(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond=strcmp(w, p->word))==0)
        p->count++; /*repeated word*/
    else if(cond<0)/*lower goes to left sub-tree*/
        p->left = tree(p->left, w);
    else  /*greater into right sub-tree*/
        p->right = tree(p->right, w);
    return(p);
}

treeprint(r)/**/
struct tnode r;
{

}