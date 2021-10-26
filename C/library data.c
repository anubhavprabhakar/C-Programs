/*menu driven program using structure*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXBOOKS 3 /*change this number to change number of maximum books*/

struct library
{
    int anum;
    char title[10];
    char name[10];
    float price;
    int flag;
};
int n=0;
struct library data[3];

void input();/*to input data*/
void display();/*to display the books data*/
void auth();/*to display the books by author*/
int sort(const void *f, const void *ff);/*comparator func*/
void acorder();/*display books by accession order*/

int main()
{
    int i;
    printf("\n\tPlease select an option from the menu-");
    printf("\n\t\t1)Add book\n\t\t2)Display books information\n\t\t3)List of all books of given author\n\t\t4)List the count of books in the library\n\t\t5)List the books the order of accession number\n\t\t6)Exit");

    while(1)
    {
        printf("\n\tEnter your choice: ");
        scanf("%d", &i);

        switch(i)
        {
            case 1:
            if(n==MAXBOOKS)
                break;
            printf("\n\tYou chose to add book-");
            input();/*to input book data*/
            break;
            case 2:
            printf("\n\tBooks information are as follows-");
            display();/*to display book data*/
            break;
            case 3:
            auth();
            break;
            case 4:
            printf("\n\tNumber of books in the library is %d", n);
            break;
            case 5:
            printf("\n\tBooks in order of accession number-");
            acorder();
            break;
            case 6:
            exit(1);
            default:
            printf("\nPlease enter correct option from the menu. Try again");
        }
        if(n==MAXBOOKS)
        {
            printf("\n\tBook slots full, cannot add more books");
        }
    }
    return 0;
}

void input()
{
        printf("\n\n\t\t\tEnter accession number of the book: ");
        scanf("%d", &data[n].anum);

        printf("\n\t\t\tEnter the title of the book: ");
        scanf("%s", data[n].title);

        fflush(stdin);
        printf("\n\t\t\tEnter the name of the author: ");
        scanf("%s", data[n].name);
        n++;
}

void display()
{
    int i;
    for(i=0; i<n; ++i)
    {
        printf("\n\n\t\t\tAccession number of book: %d", data[i].anum);
        printf("\n\t\t\tTitle of the book: %s", data[i].title);
        printf("\n\t\t\tName of the author: %s", data[i].name);
    }
}

void auth()
{
    int i, j=0;
    char author[10];
    printf("\n\n\n\tEnter author name: ");
    scanf("%s", &author);
    fflush(stdin);
    printf("\n\tTitles by the Author are-");
    for(i=0;i<3;++i)
    {
        if(stricmp(data[i].name, author)==0)
        {
            printf("\n\t\t%s", data[i].title);
            j++;
        }
    }
    if(j==0)
        printf("\n\t\tNo record of any title by '%s' found", author);
}

void acorder()
{
    qsort((struct library *) data, n, sizeof(data[0]), sort);
    printf("\n\tTitles in order of accession number is as follows-");
    display();
}

int sort(const void *f, const void *ff)
{
    return(((struct library *)f)->anum - ((struct library *)ff)->anum);
}
