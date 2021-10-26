//to convert a set of names into initials
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int getkey();

int main()
{
    while(true)//to run program indefinitely
    {
        char name[30];
        char *p;
        int bs=0, ch;

        printf("\nEnter the name: ");
        gets(name);

        p=name;
        //calculate blank spaces in the name
        while(*p)
        {
            if(*p == ' ')
                bs++;
            p++;
        }
        p=name;
        strupr(p);//convert the name to uppercase
        for(; bs>0; p++, bs--)
        {
            printf("%c ", *p);//print a character
            while(*p != ' ')//neglect characters before blank space
                p++;
        }
        //print the last name
        printf("%s", p);

        printf("\n\nTo exit press Esc, Press any other key to enter name again\n");

        ch=getkey();//get the character code of the key pressed
        if(ch==27)//exit only if Esc key is pressed
        {
            return 0;
        }

    }
}
//note the key pressed
int getkey()
{
    int ch;
    ch=getch();
    if(ch==224||0)//if key nil
        ch=getch();
    return ch;
}
