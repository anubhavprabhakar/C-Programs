//customer data for file customer.dat
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;
    char an='y';
    struct customer
    {
        int accno;
        char name[30];
        float balance;
    };
    struct customer c;

    s=fopen("CUSTOMER.DAT", "wb");
    if(s==NULL)
        exit(1);

    while(an=='y'||an=='Y')
    {
        printf("\n\nEnter acc no: ");
        scanf("%d", &c.accno);
        fflush(stdin);
        printf("\nEnter customer's name: ");
        gets(c.name);
        printf("\nEnter balance: ");
        scanf("%f", &c.balance);

        fwrite(&c, sizeof(c), 1, s);s

        printf("\n\n\tWant to enter another record?(Y/N)");
        an=_getch();
    }

    printf("\n\n\tAll data recorded!\n\tTask successful!\n");

    return 0;
}
