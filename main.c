#include <stdio.h>
#include <stdlib.h>
#include"list.h"

int main()
{
    Liste l ;
    create(&l) ;
    if(isEmpty(l)) printf("el lise vide initialement \n") ;
    addInHead(&l,1) ;
    addInTail(&l,3) ;
    addInPos(&l,2,2) ;
    addInHead(&l,0) ;
    addInTail(&l,5) ;
    addInPos(&l,4,5) ;
    printElements(l) ; // 0  1  2  3  4  5
   /* deleteInHead(&l) ;
    deleteInHead(&l) ;
    deleteInHead(&l) ;
    deleteInHead(&l) ;
    deleteInHead(&l) ;
    deleteInHead(&l) ;
    printElements(l) ; // la liste est vide */

    /*deleteInTail(&l) ;
    deleteInTail(&l) ;
    deleteInTail(&l) ;
    deleteInTail(&l) ;
    deleteInTail(&l) ;
    deleteInTail(&l) ;
    printElements(l) ; // la liste est vide */

    deleteInPos(&l, 2) ;
    printElements(l) ;
    return 0;
}
