//verify whether a 10 digit isbn is correct or not
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char isbn[20];
    int i, j, n=0;
    printf("Enter the 10 digit ISBN number\n");
    gets(isbn);
    printf("input: ");
    puts(isbn);
    for(i=0, j=10; i<10; ++i, --j)
    {
        if(isbn[i]>47&&isbn[i]<58)
        {
            n+=(j*(isbn[i]-48));
        }
        else if(isbn[i]==88||isbn[i]==120)
        {
            n+=(j*10);
        }
        else
        {
            printf("Wrong Input");
            break;
        }
    }
    printf("\nsum of digits:%d\n", n);
    if(n%11==0)
        printf("\nISBN verified/Correct ISBN\n");
    else
        printf("\nIncorrect ISBN/ISBN cant be verified\n");
    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
