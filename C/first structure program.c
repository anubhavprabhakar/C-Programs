//Usage of array of structures
#include<stdio.h>
int main()
{
    struct book
    {
        char name;
        float price;
        int pages;
    };
    struct book b[100];
    int i;

    for(i=0; i<=3; ++i)
    {
        printf("Enter name, price and pages");
        fflush(stdin);
        scanf("%s %f %d", &b[i].name, &b[i].price, &b[i].pages);
    }
    printf("\n\n");


    for(i=0; i<=3; ++i)
        printf("%c %f %d\n", b[i].name, b[i].price, b[i].pages);

    return 0;
}
