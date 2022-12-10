#include<malloc.h>
#include<assert.h>
#include"list.h"

void create ( Liste *l) /* el fonction elli t5allik ta3mel creation lel liste mte3ek */
{
    l->head = NULL ;
    l->tail = NULL ;
}

int isEmpty( Liste l) /* el fonction tchouf biha est que el liste vide ou non */
{
    return (l.head == NULL && l.tail == NULL) ;
}

int firstElement (Liste l) /* hedhi traje3 awel element fel liste */
{
    assert(!isEmpty(l)) ;
    return l.head->data ;
}
int lastElement(Liste l) /* hedhi traje3 a5er element fel liste  */
{
    assert(!isEmpty(l)) ;
    return l.tail->data ;
}

/* ------------------------------------------------------------------------- */

void addInHead (Liste *l , int x) /* fct bech tzid elet mel louel */
{
    Node *tmp ;
    tmp = (Node *)malloc(sizeof(Node)) ; /* allocation dynamique */
    tmp->data = x ;
    if(isEmpty(*l)) /* si el liste fer8a donc head w tail yepointou 3la nafs el element */
    {
        l->head = tmp ;
        l->tail = tmp ;
        l->tail->next = NULL ;
    }
    else
    {
        tmp->next = l->head ;
        l->head = tmp ;
    }
}
void addInTail(Liste *l , int x) /* fct bech tzid elet lel liste mel e5er */
{
    Node *tmp ;
    tmp = (Node *)malloc(sizeof(Node)) ; /* allocation dynamique */
    tmp->data = x ;
    if(isEmpty(*l)) /* si el liste fer8a donc head w tail yepointou 3la nafs el element */
    {
        l->head = tmp ;
        l->tail = tmp ;

    }
    else
    {
        l->tail->next = tmp;
        l->tail = tmp ;

    }
    l->tail->next = NULL ;
}

void addInPos(Liste *l, int x , unsigned pos) /* fct bech nzid element fi position donnée */
{
    int i = 1 ;
    Node *tmp = l->head ; /* variable pour parcourir la liste */
    Node *newElement = (Node *)malloc(sizeof(Node)) ;
    if (pos == 1) addInHead(l,x) ; /* si pos = 1 yaani bech n7otou fel head hedheka 3leh 3mel appel lel addInhead */
    else
    {
        while (tmp && i != pos-1)
        {
            tmp = tmp->next ;
            i++ ;
        } /* hedhi s3ib nfaserha bel klem */
        if(tmp)
        {
             newElement->data = x ;
             newElement->next = tmp->next ;
             tmp->next = newElement ;
        }
        else
        {
            addInTail(l,x) ;
        }

    }

}


/*--------------------------------------------------------*/


void deleteInHead(Liste *l) /* fct bech tremovi awel element */
{
    assert(!isEmpty(*l)) ;
    Node *tmp ;
    tmp = l->head ;
    if(l->head== l->tail) /* hedhi ta3ni si el liste fiha elemnt wa7ed donc be3d manfas5ouh el liste tarja3 vide */
    {
        l->head = NULL ;
        l->tail = NULL ;
    }
    else {
        l->head = tmp->next ;

    }
    free(tmp ) ; /* free opposite ol malloc lezem na7i el objet mel memoirre */

}

void deleteInTail (Liste *l) /* bech nremouvi a5er element */
{
    assert(!isEmpty(*l)) ;
   Node *tmp ;
   tmp = l->head ;
   if(l->head== l->tail) /* hedhi ta3ni si el liste fiha elemnt wa7ed donc be3d manfas5ouh el liste tarja3 vide */
    {
        l->head = NULL ;
        l->tail = NULL ;
    }
   else
   {
       while(tmp->next != l->tail) tmp = tmp->next ;
       l->tail = tmp ;
       tmp=tmp->next ;
       l->tail->next = NULL ;

   }
   free(tmp) ;

}

void deleteInPos(Liste *l , unsigned pos)
{
    assert(!isEmpty(*l)) ;
    int i = 1 ;
    Node *tmp = l->head , *tmp1;
    if(pos == 1) deleteInHead(l) ;
    if(l->tail == l->head) deleteInHead(l) ; // hedhi zedtha
    else
    {
        while(tmp->next != l->tail && i != pos-1)
        {
            tmp = tmp->next ;
            i++ ;
        }
        if(tmp->next != l->tail)
        {
            tmp1 = tmp->next ;
            tmp->next = tmp->next->next ;
            free(tmp1) ;
        }
        else deleteInTail(l) ;
    }
}


/*--------------------------------------------------------------------*/

unsigned searchElement(Liste l , int x)
{
    Node *tmp = l.head ;
    while(tmp && tmp->data != x) tmp = tmp->next ;
    if(tmp) return 1 ;
    return 0 ;
}


void printElements (Liste l)
{
    Node *tmp = l.head ;
    if(!tmp) printf("la liste est vide") ;
    while(tmp)
    {
        printf("%d \t",tmp->data) ;
        tmp = tmp->next ;

    }
    printf("\n") ;
}

Liste mergeList(Liste l1 , Liste l2)
{
    Liste l3 ;
    if(isEmpty(l1)) return l2 ;
    if (isEmpty(l2)) return l1 ;
    create(&l3) ;
    if(l1.head->data >= l2.head->data)
    {
        l3.head = l2.head ;
        l2.head = l2.head ->next ;
    }
    else
    {
        l3.head = l1.head ;
        l1.head = l1.head ->next ;
    }
    l3.tail = l3.head ;

    while (l1.head && l2.head)
    {
        if(l1.head->data >= l2.head->data)
        {
            l3.tail->next = l2.head ;
            l3.tail = l2.head ;
            l2.head = l2.head ->next ;
        }
        else
        {
            l3.tail->next = l1.head ;
            l3.tail = l1.head ;
            l1.head = l1.head ->next ;
        }
        l3.tail->next = NULL ;
    }
    if(l1.head)
    {

        l3.tail ->next = l1.head ;
        l3.tail = l1.tail ;
    }
    if(l2.head)
    {

        l3.tail ->next = l2.head ;
        l3.tail = l2.tail ;
    }
    return l3 ;

}






