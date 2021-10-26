//read data from//read data from CUSTOMER.DAT
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;

    struct trans//to store reading from CUSTOMER.DAT
    {
        int accno;
        char trans_type;
        float amount;
    };
    struct trans c;

    s=fopen("TRANSACTIONS.DAT", "rb");//opening CUSTOMER.DAT
    if(s==NULL)
    {
        printf("\n\tCannot open TRANSACTIONS.DAT file");
        exit(1);
    }

    while(fread(&c, sizeof(c), 1, s)!=NULL)//loop read from CUSTOMER.DAT until the file is over
    {
        if(c.trans_type=='d'||c.trans_type=='D')
        {
            printf("\n\nAcc NO: %d\nTransaction type: Deposit\nAmount: %.2f", c.accno, c.amount);

        }
        else
        {
            printf("\n\nAcc NO: %d\nTransaction type: Withdraw\nAmount: %.2f", c.accno, c.amount);

        }
    }

    fclose(s);
    printf("\n\n\tPress any key to close.");
    _getch();

    return 0;
}
