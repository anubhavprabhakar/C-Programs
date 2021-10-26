//read data from CUSTOMER.DAT
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;

    struct customer//to store reading from CUSTOMER.DAT
    {
        int accno;
        char name[30];
        float balance;
    };
    struct customer c;

    s=fopen("CUSTOMER.DAT", "rb");//opening CUSTOMER.DAT
    if(s==NULL)
    {
        printf("\n\tCannot open CUSTOMER.DAT file");
        exit(1);
    }

    while(fread(&c, sizeof(c), 1, s)!=NULL)//loop read from CUSTOMER.DAT until the file is over
    {
        printf("\n\nAcc NO: %d\nName: %s\nBalance: %.2f", c.accno, c.name, c.balance);
    }

    fclose(s);
    printf("\n\n\tPress any key to close.");
    _getch();

    return 0;
}
