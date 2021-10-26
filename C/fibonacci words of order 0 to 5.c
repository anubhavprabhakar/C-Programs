#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char s1[50];
    char s2[50];
    char s3[50];
    int i;
    printf("For the sake of memory, dont input strings bigger than 5 characters");
    printf("\nEnter first string\n");
    gets(s1);
    printf("Enter second string\n");
    gets(s2);
    printf("\nWord 1 = %s", s1);
    printf("\nWord 2 = %s", s2);
    for(i=3;i<6;++i)
    {
        strcpy(s3, s2);
        strcat(s2, s1);
        printf("\nWord %d = %s", i, s2);
        strcpy(s1, s3);
    }
    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
