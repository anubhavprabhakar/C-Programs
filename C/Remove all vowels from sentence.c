//remove all the vowels from the input sentence
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char str[80];
    char str1[80];
    //array of characters to store vowels
    char vow[11]={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', '\0'};

    char *s, *p;
    int i;
    //take sentence as input
    printf("Enter a sentence in not more than 80 characters\n");
    gets(str);
    //using pointer to the string
    s=str;
    p=str1;

    while(*s)
    {
        for(i=0; vow[i]!='\0'; i++)//check if the character is a vowel or not, form the vow[]
        {
            if(vow[i]==*s)
            {
                s++;
                break;//break when found, to avoid unnecessary changes
            }
        }
    //copy the rest of string in a new string
    *p++=*s++;
    }
    //end the new string with '\0'
    *p='\0';

    //print the new string without vowels
    printf("\nSentence after removing vowels:\n%s\n", str1);

    printf("Press any key to exit");
    getch();//to hold screen before exiting
    return 0;
}
