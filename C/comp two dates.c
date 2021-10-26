/*linked list for the first time*/
#include<stdio.h>

int main()
{
    int i;
    /*i know structure is not a good way to show linked list
    cz structure elemsnts are contiguously stored
    But i'm just trying to understand linked list*/
    struct data
    {
        int a;
    };

    struct LL
    {
        struct data d;//nesting struct
        int *p;
    };
    struct LL node[3];

    for(i=0; i<3; i++)//entering data in the list
    {
        printf("\nEnter a number: ");
        scanf("%d", &node[i].d.a);//main element

        node[i].p=&node[i+1].d.a;//pointer to the successive element in the list
    }
    for(i=0; i<3; ++i)
    {
        printf("\n\n%dth element of the list is: %d", i+1, node[i].d.a);
        printf("\nAddress of %dth element of list is %d", i+2, node[i].p);
    }
    printf("\n\nAddress of 2th element of the list is : %u", &node[1].d.a);/*to demonstrate that pointer of first node stores
    address of second element in the node*/

    return 0;
}
