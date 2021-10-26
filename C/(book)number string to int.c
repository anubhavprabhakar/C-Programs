/*getint() converts numeric string to integers*/
#include<stdio.h>
#include<conio.h>

int getint();

int main()
{
    int a;
    a=getint();
    printf("\nYou entered %d\n", a);
    return 0;
}

int getint()
{
    int i, j, k, val;
    char str[6];
    printf("enter a number(string formatted)");

    i=0;
    while(i<=5)
    {
        str[i]=getche();/*string input from keyboard*/
        if(str[i]=='\r')
        {
            str[i]=='\0';
            break;
        }
        if(str[i]=='\b')
        {
            i--;
            printf(" \b");
        }
        else;
            i++;
    }
    val=0;
    k=1;
    for(j=i-1; j>=0; j--)
    {
        val+=((str[j]-48)*k); /*convert to numeric value*/
        k*=10;
    }
    return val;
}
