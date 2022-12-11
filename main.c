#include <stdio.h>
#include <stdlib.h>
#include"list.h"
#include<assert.h>

int main()
{


    Liste l ;
    create(&l) ;
    if(isEmpty(l)) printf("bonjour \n") ; // la liste est initialement vide
    addInHead(&l,5) ;
    printf("first element :%d\n",firstElement(l)) ; // first element : 5
    addInTail(&l , 10) ;
    printf("last element :%d\n",lastElement(l)) ; // last element :  10
    addInPos(&l, 7 , 2) ;
    printElements(l) ;   // 5 7 10
    deleteInHead(&l) ;
    printElements(l) ; // 7 10
    deleteInTail(&l) ;
    printElements(l) ; // 7
    deleteInPos(&l,4) ;
    printElements(l) ; // la liste est vide*/
    return 0;
}
