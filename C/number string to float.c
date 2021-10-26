/*getfloat() converts numeric string to integers*/
#include<stdio.h>

float getfloat();

int main()
{
    float a;
    a=getfloat();
    printf("\nYou entered %10.4f\n", a);
    return 0;
}

float getfloat()
{
    float num;
    char n[30];
    printf("enter a number(string formatted)");
    scanf("%s", n);
    sscanf(n, "%f", &num);
    return num;
}
