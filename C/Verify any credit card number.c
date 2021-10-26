//Verifying credit card number
//using strings
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char ccn[20];//credit card number will be assigned to ccn
    int i, j, num, inum=0, jnum=0;//declaring variables
    printf("Enter a 16 digit credit number: ");
    scanf("%s", ccn);//taking credit card number
    for(j=0, i=1; j<16; i+=2, j+=2)
    {
        if(ccn[i]<48||ccn[i]>57||ccn[j]<48||ccn[j]>57)
        {//if any character other than digits is entered
            printf("\nWrong Input");
            return 0;
        }
        num=(ccn[j]-48);//converting digit character into integer
        if((num*2)>9)//multiplying first and every other digit by 2
            num=(num*2)-9;//reducing the multiple to below 10
        else
            num*=2;//when multiple is below 10 already
        jnum+=num;//adding those multiples
        inum+=(ccn[i]-48);//adding secong and every other digit
    }
    if((jnum+inum)%10==0)//checking if adding both sums gives a multiple of 10 or not
        printf("\nValid Credit Card", ccn);
    else printf("\nInvalid Credit Card", ccn);
    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
