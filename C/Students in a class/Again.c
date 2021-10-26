//display nth name in list, and names of people starting with S
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;
    struct list
    {
        char name[20];
    }; struct list l;
    struct list studl[100];

    int n, j, i=0, slen=sizeof(l);

    s=fopen("STUDENTS.DAT", "rb");
    if(s==NULL)
    {
        printf("\n\tCannot open file STUDENTS.DAT\n");
        exit(1);
    }

    while(fread(&l, slen, 1, s)!=NULL)
    {
        studl[i]=l;
        i++;
    }

    printf("Enter position of name to be displayed(nth): ");
    scanf("%d", &n);

    if(n<i+1&&n>0)
        printf("\n\t%dth name is: %s", n, studl[n-1].name);
    else
        printf("n exceeded the total number of students, or  is less than 0");

    printf("\n\n\tStudents with names starting from S are:\n");

    for(n=0; n<i; n++)
    {
        if(studl[n].name[0]=='S'||studl[n].name[0]=='s')
            printf("\n\t%s", studl[n].name);
    }

    fclose(s);
    printf("\n\tPress any key to exit.");
    _getch();

    return 0;
}
