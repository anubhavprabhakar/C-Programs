/*getfloat() converts numeric string to integers*/
#include<stdio.h>
#include<conio.h>

float getfloat();

int main()
{
    float floatresult=0.0f;

    floatresult=getfloat();
    printf("After converting string to float, result is: ");
    printf("%0.2f\n", floatresult);

    return 0;
}

float getfloat()
{
    char str[20];
    printf("Enter a float number in string format\n");
    scanf("%s", str);
    float temp=0.0f, result=0.0f;
    int i, j, decimal;

    for(i=0; str[i]!='.'; i++)
        result=(result*10)+str[i]-'0';

    decimal=1;

    for(j=i+1; str[j]!='\0'; j++)
    {
        temp=str[j]-'0';
        decimal*=10;
        temp=temp/decimal;
        result+=temp;
    }
    return result;
}
