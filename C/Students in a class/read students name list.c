//show list of names of students in a class
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;
    char name[20];
    int slen=sizeof(name);

    s=fopen("STUDENTS.DAT", "rb");
    if(s==NULL)
    {
        printf("\n\tCannot open file STUDENTS.DAT\n");
        exit(1);
    }

    while(fread(name, slen, 1, s)!=NULL)
    {
        printf("\nName: %s", name);
    }

    fclose(s);
    printf("\n\n\tPress any key to exit.");
    getch();

    return 0;
}
