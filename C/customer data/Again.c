//record data for file TRANSACTION.dat
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;
    char an='y';
    struct trans
    {
        int accno;
        char trans_type;
        float amount;
    };
    struct trans c;

    s=fopen("TRANSACTIONS.DAT", "wb");
    if(s==NULL)
        exit(1);

    while(an=='y'||an=='Y')
    {
        printf("\n\nEnter acc no: ");
        scanf("%d", &c.accno);

        marker1:
        printf("\nEnter transaction type(D for deposit, or W for withdrawal: ");
        fflush(stdin);
        c.trans_type=getche();

        if(c.trans_type=='D'||c.trans_type=='d'||c.trans_type=='w'||c.trans_type=='W');
        else
        {
            printf("\n\tPlease enter correct option");
            goto marker1;
        }

        printf("\n\nEnter amount: ");
        scanf("%f", &c.amount);

        fwrite(&c, sizeof(c), 1, s);

        printf("\n\n\tWant to enter another record?(Y/N)");
        an=_getch();
    }

    printf("\n\n\tAll data recorded!\n\tTask successful!\n");

    return 0;
}
