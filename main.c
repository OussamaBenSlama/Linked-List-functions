#include <stdio.h>
#include <stdlib.h>
#include"list.h"
#include<assert.h>

int main()
{


    Liste l1 ;
    create(&l1) ;
    if(isEmpty(l1)) printf("bonjour \n") ;
    addInHead(&l1,5) ;
    printf("first element :%d\n",firstElement(l1)) ;
    addInTail(&l1 , 10) ;
    printf("last element :%d\n",lastElement(l1)) ;
    addInPos(&l1, 7 , 2) ;
    printElements(l1) ;
    deleteInHead(&l1) ;
    printElements(l1) ;
    deleteInTail(&l1) ;
    printElements(l1) ;
    deleteInPos(&l1,4) ;
    printElements(l1) ;
    return 0;
}
