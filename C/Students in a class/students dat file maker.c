//store list of names of students in a class
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;
    char name[20];
    char c='y';
    int slen=sizeof(name);

    s=fopen("STUDENTS.DAT", "wb");

    while(c=='y'||c=='Y')
    {
        fflush(stdin);
        printf("\n\nEnter name: ");
        gets(name);
        fwrite(name, slen, 1, s);

        printf("\nName recorded.\nWant to enter another name?(Y/N)");
        c=_getch();
    }
    fclose(s);

    return 0;
}
