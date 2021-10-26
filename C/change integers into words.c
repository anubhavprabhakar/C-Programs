//to convert a number from integers to words
#include<stdio.h>
#include<string.h>
#include<conio.h>
void words(long int, char *);

char *ones[]={"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine" , "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
char *tens[]={"", "", "Twenty "  "Thirty ", "Fourty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

int main()
{
    long int num;

    printf("Enter the number: ");
    scanf("%ld", &num);
    printf("\n%ld in words is :\n", num);

    if(num<=0&&num>999999999)
        printf("No negative number or zero, and only 9 digit numbers");

    else
    {
        words((num/1000000), "Million");
        words(((num/1000)%1000), "Thousand");
        words(((num%1000)), "");
    }
    printf("\nPress any key to continue\n");
    getch();
    return 0;
}

void words(long int n, char *s)
{
    if(n>100)
        printf("%sHundred %s%s ", ones[n/100], tens[(n%100)/10], ones[n%10]);
    else if(n<100&&n>19)
        printf("%s%s", tens[n/10], ones[n%10]);
    else
        printf("%s", ones[n]);
    if(n)
        printf("%s ", s);
}
