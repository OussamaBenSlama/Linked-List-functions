#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node /* structure te3 node (element) elli composé menou list */
{
    int data ;
    struct Node *next ;
} Node ;

typedef struct liste
{
    Node *head ; /* head w tail sont des pointeurs sur le premier element et le dernier */
    Node *tail ;
} Liste ;
/* 3melt list fiha head w tail bech nsehel 3la rou7i l5edma */

void create(Liste *) ;

int isEmpty(Liste) ;

void addInHead (Liste * , int ) ;


int firstElement (Liste) ;

void addInTail (Liste * , int) ;

int lastElement (Liste) ;

void addInPos (Liste * , int , unsigned) ;

void printElements(Liste ) ;

void deleteInHead ( Liste * ) ;

void deleteInTail (Liste * ) ;

void deleteInPos (Liste * , unsigned) ;

unsigned searchElement (Liste , int) ;


/* high level problems */

Liste mergeList(Liste , Liste) ;

#endif // LIST_H_INCLUDED
