//structure for storing customer bank details
#include<stdio.h>
struct data
{
    int acc;
    char name[10];
    float bal;
};
struct data d[2];

void main_data();
void wd(int, float, int);
void lowbal();
void update(int, int);

int main()
{
    char req;
    int ac, code;
    float wdamt;

    printf("\nEnter the details of the customers-\n\n");

    /*function to input data*/
    main_data();
    /*function to check for low balance account holders*/
    lowbal();

    printf("\n\nPress Y to request withdrawal or diposit\n");
    fflush(stdin);
    scanf("%c", &req);

    if(req=='Y'||req=='y')
    {
        /*format for witdrawal or deposit*/
        fflush(stdin);
        printf("\n\tEnter acc no: ");
        scanf("%d", &ac);
        fflush(stdin);
        printf("\n\tEnter amount: ");
        scanf("%f", &wdamt);
        fflush(stdin);
        printf("\n\tEnter 0 for withdrawal, 1 for deposit- ");
        scanf("%d", &code);

        /*function for withdrawal or deposit*/
        wd(ac, wdamt, code);
    }
    return 0;
}

void main_data()
{
    int i;
    for(i=0; i<2; ++i)
    {
        fflush(stdin);
        printf("\n\n\n\tEnter account number: \n\t");
        scanf("%d", &d[i].acc);
        fflush(stdin);
        printf("\n\tEnter name of the customer:\n\t");
        scanf("\t%s", d[i].name);
        fflush(stdin);
        printf("\n\tEnter balance:\n\t");
        scanf("\t%f", &d[i].bal);
    }
}

void lowbal()
{
    int i, j=0;
    printf("\n\nAccount holders whose balance is less than Rs. 100 -\n");
    for(i=0;i<2;i++)
    {
        if(d[i].bal<=100)
        {
            printf("\n\tName: %s \tAcc no. %d\tBalance: %f", d[i].name, d[i].acc, d[i].bal);
            j=1;
        }
    }
    if(j==0)
        printf("No account holders below min balance found");
}

void wd(int ac, float wdamt, int code)
{
    int i, j=0;
    for(i=0; i<2; ++i)
    {
        if(ac==d[i].acc)
        {
            if(code==0)
            {
                if(d[i].bal-wdamt<=100)
                {
                    printf("\nThe withdrawal bal is insuff- message\n");
                    break;
                }
                d[i].bal-=wdamt;
            }
            else if(code==1)
                d[i].bal+=wdamt;
            else
            printf("\nPlease enter correct choice");
            j=1;
            break;
        }
    }
    if(j==0)
        printf("\nNo account with acc no. %d found in database", ac);
    else
    {
        printf("Updated details of account number %d is-", ac);
        /*function to view updated details of the acc*/
        update(ac, i);
    }
}

void update(int ac, int i)
{
    printf("\n\n\tAccount number: %d\n\tName: %s\n\tBalance: %f", ac, d[i].name, d[i].bal);
}
