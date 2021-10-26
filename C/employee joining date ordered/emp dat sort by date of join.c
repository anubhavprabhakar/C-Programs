//employee data sorted by joining date
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s, *t;
    int n=0, i, j;

    struct date
    {
        int d, m, y;
    };
    struct employee
    {
        char empname[20];
        struct date join_date;
    };
    struct employee e, emp[100]/*to store multiple structures*/, temp;

    s=fopen("EEMPLOYEE.DAT", "rb");
    if(s==NULL)
    {
        printf("\nCannot open file EMPLOYEE.DAT");
        _getch();//to wait for keypress
        exit(1);
    }

    while(fread(&e, sizeof(e), 1, s)!=NULL)
    {
        emp[n]=e;
        n++;
    }

    fclose(s);//close file EMPLOYEE.DAT cz its not needed anymore

    for(i=0; i<=n-2; ++i)//sorting the records stored in struct array emp[], which has n-1 elements.
    {//placing smallest item on top of unsorted batch(unsorted batch: top item and all items below) (sorted: smallest item placed on top and all items above it)
        //"top item" assumes the next item after this for loop is finished.
        for(j=i+1; j<=n-1; j++)
        {//this for loop compares the top item with every item below top item, and actually sorts the batch.
            //the if else if block does simple replacing of top item with any item smaller than it
            if(emp[i].join_date.y>emp[j].join_date.y)
            {
                temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;
            }
            else if((emp[i].join_date.y==emp[j].join_date.y)&&(emp[i].join_date.m>emp[j].join_date.m))
            {
                temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;
            }
            else if((emp[i].join_date.y==emp[j].join_date.y)&&(emp[i].join_date.m==emp[j].join_date.m)&&(emp[i].join_date.d>emp[j].join_date.d))
            {
                temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;
            }
        }
    }

    t=fopen("SORTED EMPLOYEE.DAT", "wb");
    if(t==NULL)
    {
        printf("\nCannot create file SORTED EMPLOYEE.DAT");
        _getch();//waiting for keypress
        exit(2);
    }

    for(i=0; i<n; i++)
    {
        fwrite(&emp[i], sizeof(e), 1, t);
    }
    fclose(t);

    printf("\n\tTask finished successfully!");
    _getch();//wait for keypress.

    return 0;
}
