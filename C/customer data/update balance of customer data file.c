//update customer.dat file, from the data by transactions.dat
#include<stdio.h>
#include<stdlib.h>
struct customer//to store reading from CUSTOMER.DAT
    {
        int accno;
        char name[30];
        float balance;
    };
    struct trans//to store readings from TRANSACTIONS.DAT
    {
        int accno;
        char trans_type;
        float amount;
    };
int main()
{
    FILE *s, *t;
    struct customer c;
    struct trans tr;
    int slen=sizeof(c);

    printf("\n\tUpdating customer data records(in file CUSTOMER.DAT file)\n");

    s=fopen("CUSTOMER.DAT", "rb+");//opening CUSTOMER.DAT
    if(s==NULL)
    {
        printf("\n\tCannot open CUSTOMER.DAT file");
        exit(1);
    }

    t=fopen("TRANSACTIONS.dat", "rb");//opening TRANSACTIONS.DAT
    if(t==NULL)
    {
        printf("\n\tCannot open TRANSACTIONS.DAT file");
        exit(2);
    }

    while(fread(&tr, sizeof(tr), 1, t)!=NULL)//loop read from CUSTOMER.DAT until the file is over
    {
        fseek(s, 0, SEEK_SET);
        while(fread(&c , slen, 1, s)!=NULL)//loop read from TRANSACTIONS.DAT until the file is over
        {
            if(c.accno==tr.accno)//match every acc no in TRANSACTIONS.DAT to the acc no from TRANSACTIONS.DAT
            {
                if(tr.trans_type=='D'||tr.trans_type=='d')
                    c.balance+=tr.amount;

                if((tr.trans_type=='w'||tr.trans_type=='W')&&(c.balance-tr.amount>=100))
                    c.balance-=tr.amount;
                else
                    c.balance==100;

                fseek(s, -slen, SEEK_CUR);
                fwrite(&c, slen, 1, s);
                break;
            }
        }
    }

    fclose(s);
    fclose(t);

    printf("\n\n\tUpdating task completed!");

    return 0;
}
