#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top=NULL;

void push(int item);
void display();
void pop();
int count();

int main()
{
    int c;
    push(88);
    push(69);
    push(420);
    printf("\nStack is as follows-\n");
    display();
    c=count();
    printf("\nNumber of elements in stack is = %d", c);
    pop();
    printf("\n\nTop popped off\nStack is as follows-\n");
    display();
    c=count();
    printf("\nNumber of elements in stack is = %d", c);
    return 0;
}

void push(int item)
{
    struct node *q=(struct node *)malloc(sizeof(struct node));
    q->data=item;
    q->link=top;
    top=q;
}

void display()
{
    struct node *q;
    q=top;
    while(q!=NULL)
    {
        printf("\t%d", q->data);
        q=q->link;
    }
}

void pop()
{
    struct node *temp;
    temp=top;
    top=top->link;
    printf("\n\nHeres what temp stored:%d", *temp);
    free(temp);
    printf("\n\nHeres what temp stores now: %d", *temp);
}

int count()
{
    int i=0;
    struct node *q;
    q=top;
    while(q!=NULL)
    {
        i++;
        q=q->link;
    }
    return i;
}
