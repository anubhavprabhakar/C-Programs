/*implementation of queue using linked list*/
#include<stdio.h>
#include<malloc.h>

/*self linked list structure*/
struct node
{
    int data;
    struct node *link;
};
/*ends of a queue data structure*/
struct node *head, *rear;

void add(int item);//to add an item at the rear end
void del();//to delete an item from the head end
void display();//to display the queue
int count();//to count the number of items in the queue

int main()
{

    head=rear=NULL;//initializing the pointers

    add(45);
    add(55);
    add(90);
    add(66);
    printf("\nQueue:\t");
    display();

    printf("\nTotal items: %d", count()/*to return the count directly here*/);

    printf("\nDeleted top item: ");
    del();

    printf("\n\tQueue:\t");
    display();

    printf("\nTotal items: %d", count()/*to return the count directly here*/);

    return 0;
}

void add(int item)
{
    struct node *q=(struct node *)malloc(sizeof(struct node));

    q->data=item;
    q->link=NULL;
    if(head==NULL)
    {//naming both ends of the queue
        head=q;
        rear=q;
    }
    else
    {//adding items to the rear end
        q->link=rear;
        rear=q;
    }

}

void del()
{
    struct node *q;
    q=rear;
    /*checking if second last box is reached*/
    while(q->link->link!=NULL)
        q=q->link;

    printf("%d", head->data);//printing what will be deleted

    q->link=NULL;//deleting link of the head end from the second last box
    free(head);//freeing the head box
    head=q;//making the second last box as head end, technically, naming current first box as head
}

void display()
{
    struct node *q;
    q=rear;
    /*loop till no more boxes left*/
    while(q!=NULL)
    {
        printf("\t%d", q->data);
        q=q->link;
    }
}

int count()
{
    int i=0;
    struct node *q;
    q=rear;
    /*loop till no more boxes left*/
    while(q!=NULL)
    {
        i++;
        q=q->link;
    }
    return i;
}
