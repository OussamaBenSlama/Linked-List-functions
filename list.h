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
int firstElement (Liste) ;
int lastElement (Liste) ;

void addInHead ( Liste * , int ) ;
void addInTail (Liste * , int) ;
void addInPos (Liste * , int , unsigned) ;

void deleteInHead ( Liste * ) ;
void deleteInTail (Liste * ) ;
void deleteInPos (Liste * , unsigned) ;

unsigned searchElement (Liste , int) ;

void printElements(Liste l) ;

#endif // LIST_H_INCLUDED
