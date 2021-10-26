/*getint() converts numeric string to integers*/
#include<stdio.h>

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
    int num;
    char n[30];
    printf("enter a number(string formatted)");
    scanf("%s", n);
    sscanf(n, "%d", &num);
    return num;
}
