//customer data for file transactions.dat
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
    struct trans t;

    s=fopen("TRANSACTIONS.DAT", "wb");
    if(s==NULL)
        exit(1);

    while(an=='y'||an=='Y')
    {
        printf("\n\nEnter acc no: ");
        scanf("%d", &t.accno);
        fflush(stdin);
        printf("\nEnter transaction type(D/W): ");
        scanf("%c", &t.trans_type);
        printf("\nEnter balance: ");
        scanf("%f", &t.amount);
        printf("\n\n\tWant to enter another record?(Y/N)");
        an=_getch();
        fwrite(&t, sizeof(t), 1, s);
    }

    printf("\n\n\tAll data recorded.\n\tTask successful!\n");

    return 0;
}
