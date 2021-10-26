//remove the existence of 'the' from a sentence, input through keyboard
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char str[80], str1[80];
    char *s, *p, *q;
    int i;

    printf("Enter a sentence: ");
    gets(str);//taking the sentence as input

    s=str;
    p=str1;//for copying the new sentence without 'the'

    if((*s=='t'||*s=='T')&&(*(s+1)=='h'||*(s+1)=='H')&&(*(s+2)=='e'||*(s+2)=='E')&&(*(s+3)==' '))
        s+=4;//to remove the first 'the' and giving control to next character

    while(*s)
    {
        q=s;
        if(*s==' ')//to avoid changing words ending in '-the'
        {
            s++;
            if(*s=='t'||*s=='T')
            {
                s++;
                if(*s=='h'||*s=='H')
                {
                    s++;
                    if(*s=='e'||*s=='E')
                    {
                        s++;
                        if(*s==' ')//to avoid changing words that contain '-the-'
                        *p++=*q++;
                        else
                        {
                            for(i=0; i<5; i++)
                                *p++=*q++;//the word is more than 'the-', copy in p till 'the'
                        }
                    }
                    else
                    {
                        *p++=*q++;//copying till 'th'
                        s-=3;//there's no 'e' after 'th', then take s back to 't' (will increment s in line 50)
                    }
                }
                else
                {
                    *p++=*q++;//copy 't'
                    s-=2;//there's no h, take s back to 't' (will increment s in line 50)
                }
            }
            else
            {
                *p++=*q++;
                s--;
            }
        }
        else
            *p++=*s;
        s++;//increment s to next character
    }
    *p='\0';//end string str1 with '\0'

    printf("\n\nSentence after deleting all the 'the's is:\n");
    puts(str1);//print the new string str1

    printf("\nPress any key to exit");
    getch();//to hold screen before exiting

    return 0;
}
