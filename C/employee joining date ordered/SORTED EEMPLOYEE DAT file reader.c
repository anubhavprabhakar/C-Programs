//SORTED employee data records in file SORTED EMPLOYEE.DAT
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;//pointer to the main file

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

    s=fopen("SORTED EMPLOYEE.dat", "rb");
    if(s==NULL)
    {
        printf("\n\tCannot OPEN file SORTED EMPLOYEE.DAT");
        _getch();//wait for a key press
        exit(1);
    }

    while(fread(&e, sizeof(e), 1, s)!=NULL)
    {
        printf("\n\nEmployee name: %s", e.empname);
        printf("\nDate of Joining: %d %d %d", e.join_date.d, e.join_date.m, e.join_date.y);
    }

    fclose(s);

    printf("\n\n\tPress any key to continue.");
    _getch();//wait for keypress

    return 0;
}
