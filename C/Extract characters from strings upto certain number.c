#include<stdio.h>
#include<conio.h>
#include<string.h>
#define N 20//change the number to desired number of elements in string(1 more than that)
int main()
{
    char str[N];
    int i, j, c;
    printf("Please enter a string of %d characters(can be changed in sorce code)\n", N);
    gets(str);
    printf("Enter position to extract characters from:");
    scanf("%d", &i);
    printf("Enter number of character to be extracted upto:");
    scanf("%d", &j);

    if(j==0)
    printf("%s", &str[i-1]);
    for(c=i; c<(i+j); ++c)
    {
        printf("%c", str[c-1]);
    }
    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
