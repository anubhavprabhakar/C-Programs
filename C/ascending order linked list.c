/*maintaining ascending order in the linked list*/
#include<stdio.h>
#include<malloc.h>

struct node
{
    int num;
    struct node *link;
};
struct node *top=NULL;

int add(int item);
void display();

int main()
{
    printf("\n");
    printf("Adding items:\t%d\t%d\t%d\t%d\t%d\t%d", add(45), add(420), add(60), add(55), add(90), add(69));
    printf("\nStack in ascending order:");
    display();
}

int add(int item)
{
    struct node *q=(struct node *)malloc(sizeof(struct node));
    struct node *w, *e=top;
    q->num=item;
    q->link=NULL;

    if(top==NULL)
        top=q;

    else
    {
        if(q->num <= top->num)
        {
            q->link=top;
            top=q;
        }
        else
        {
            while(e->link!=NULL && q->num > e->link->num)
                e=e->link;
            if(e->link!=NULL)
            {
                w=e->link;
                q->link=w;
                e->link=q;
            }
            else
                e->link=q;
        }
    }
    return q->num;
}

void display()
{
    struct node *q;
    q=top;
    while(q!=NULL)
    {
        printf("\t%d", q->num);
        q=q->link;
    }
}
