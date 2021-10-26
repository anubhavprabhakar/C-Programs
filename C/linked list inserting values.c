/*Build a linked list*/
#include<stdio.h>
#include<malloc.h>

/*structure element*/
struct linklist
{
    int item;
    struct linklist *link;
};
struct linklist *p;

void add_item_at_loca(int item, int loca);
void add_end(int item);
void display();
void add(int item);

int main()
{
    p=NULL; /*last node location is always null*/

    /*add items at beginning of the linked list*/
    add(10);
    add(20);
    add(30);
    add(40);
    printf("Items added at the beginning of the linked list:\n");

    /*display all the items in the linked list*/
    display();
    /*add item at the end of the linked list*/
    printf("\n\nItem added at the end of the list:\n");
    add_end(50);
    display();

    /*add item at a given location in the linked list*/
    printf("\n\nItem added in the midddle of the linked list:\n");
    add_item_at_loca(60, 4);
    display();

    return 0;
}

void add_item_at_loca(int item, int loca)
{
    struct linklist *q=(struct linklist *)malloc(sizeof(struct linklist));
    struct linklist *r, *w=p;
    int i=1;

    q->item=item;
    q->link=NULL;
    if(p==NULL)
        p=q;
    else
    {
        while((w->link!=NULL)&&(i!=loca))
        {
            i++;
            w=w->link;
        }
        if(i==loca)
        {
            r=w->link;
            w->link=q;
            q->link=r;
        }
        else
            w->link=q;
    }
}

void add_end(int item)
{
    struct linklist *q=(struct linklist *)malloc(sizeof(struct linklist));
    struct linklist *w=p;

    q->item=item;
    q->link=NULL;
    if(p==NULL)
        p=q;
    else
    {
        while(w->link!=NULL)
            w=w->link;
        w->link=q;
    }
}

void display()
{
    struct linklist *q=p;
    int i=0;

    while(q!=NULL)
    {
        i++;
        printf("\nItem number %d=%d", i, q->item);
        q=q->link;
    }
}
void add(int item)
{
    struct linklist *q=(struct linklist *)malloc(sizeof(struct linklist));

    q->item=item;
    q->link=NULL;
    if(p==NULL)
        p=q;
    else
    {
        q->link=p;
        p=q;
    }
}
