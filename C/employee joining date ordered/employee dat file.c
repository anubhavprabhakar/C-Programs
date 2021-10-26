//employee data records for file EMPLOYEE.DAT
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;//pointer to the main file
    char an='y';
    struct date
    {
        int d, m, y;
    };
    struct employee
    {
        char empname[20];
        struct date join_date;
    };
    struct employee e;

    s=fopen("Eemployee.dat", "wb");
    if(s==NULL)
    {
        printf("\n\tCannot create/edit file EMPLOYEE.DAT");
        _getch();//wait for a key press
        exit(1);
    }

    while(an=='y'||an=='Y')
    {
        fflush(stdin);
        printf("\nEnter name: ");
        gets(e.empname);

        marker1:
        printf("\nEnter year of joining: ");
        scanf("%d", &e.join_date.y);

        if(e.join_date.y>2021||e.join_date.y<1960)//check for logically correct year input
        {
            printf("\n\n\tWrong input for year. Enter year correctly.\n");
            goto marker1;
        }

        marker2:
        printf("\nEnter month of joining: ");
        scanf("%d", &e.join_date.m);

        if(e.join_date.m>12||e.join_date.m<1)
        {
            printf("\n\n\tWrong input for month. Enter month correctly.\n");
            goto marker2;
        }

        marker3:
        printf("\nEnter day of joining: ");
        scanf("%d", &e.join_date.d);

        if((e.join_date.m==2) && (e.join_date.d>28))
        {
            printf("\n\n\tWrong day entered. Enter day correctly.");
            goto marker3;
        }
        else if((e.join_date.m==4||e.join_date.m==6||e.join_date.m==9||e.join_date.m==11) && (e.join_date.d>30))
        {
            printf("\n\n\tWrong day entered. Enter day correctly.");
            goto marker3;
        }
        else if(e.join_date.d>31 || e.join_date.d<1)
        {
            printf("\n\n\tWrong day entered. Enter day correctly.");
            goto marker3;
        }

        fwrite(&e, sizeof(e), 1, s);

        fflush(stdin);
        printf("\n\tWant to enter another record?(Y/N)");
        an=_getche();
    }
    fclose(s);
    printf("\n\n\tAll data recorded. Task Succesful!");
    _getch();//wait for keypress

    return 0;
}
