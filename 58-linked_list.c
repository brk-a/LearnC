#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000

struct lnode{ /*a line of text*/
    char *text; //points to text
    struct lnode *prev; //previous line
    struct lnode *next; //next line
};

int main(){/*print lines in reverse*/
    struct lnode *head = NULL;
    struct lnode *tail = NULL;
    char line[MAXLINE];

    while (fgets(line, MAXLINE, stdin)!=NULL){
        char *save = (char *) malloc(strlen(line)+1);
        strcpy(save, line);

        struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));
        new->text = save;
        new->next = NULL;
        new->prev = tail;
        tail = new;

        if(head==NULL) head = new;
    }

    for(struct lnode *current=tail; current!=NULL; current=current->prev){
        printf("%s", current->text);
    }
    
}