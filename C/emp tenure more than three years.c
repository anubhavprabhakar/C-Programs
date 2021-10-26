/*structure to hold employee data*/
/*display employees whose tenure is more or equal to three years*/
#include<stdio.h>
#include<stdlib.h>
struct doj
{
    int day;
    int mon;
    int year;
};

struct emp
{
    int empcode;
    char name[10];
    struct doj date;
};
struct emp e[3];

void data();/*to assign data to the structure*/
void calcten();/*to calculate tenure*/

int main()
{

    printf("\n\t\tEnter the employee details");
    data();
    printf("\n\t\tEmployees with tenure greater than three years are:");
    calcten();

    return 0;
}

void data()
{
    int i;
    for(i=0; i<3; ++i)
    {
        printf("\n\n\t\t\tEnter the employee code: ");
        scanf("%d", &e[i].empcode);

        printf("\n\t\t\tEnter the employee name: ");
        scanf("%s", e[i].name);

        fflush(stdin);
        printf("\n\t\t\tDay of joining of the employee: ");
        scanf("%d", &e[i].date.day);
        if(e[i].date.day<1||e[i].date.day>31)
        {
            printf("\n\t\tPlese enter correct date");
            exit(1);
        }

        printf("\n\t\t\tEnter the month of joining of the employee: ");
        scanf("%d", &e[i].date.mon);
        if(e[i].date.mon<1||e[i].date.mon>12)
        {
            printf("\n\t\tPlese enter correct date");
            exit(1);
        }

        printf("\n\t\t\tEnter the year of joining of the employee: ");
        scanf("%d", &e[i].date.year);
        if(e[i].date.year>2020)
        {
            printf("\n\t\tPlese enter correct date");
            exit(1);
        }
    }
    return;
}

void calcten()
{
    int i, j=0;
    for(i=0; i<3; i++)
    {
        if(e[i].date.year==2017)
        {
            if(e[i].date.mon==11&&e[i].date.day>=23||e[i].date.mon>11)
                continue;

        }
        if(e[i].date.year>2017)
            continue;

        printf("\n\t\t\tEmployee name: %s", e[i].name);
        printf("\n\t\t\tEmployee code: %d", e[i].empcode);
        printf("\n\t\t\tDate of joining is %d/%d/%d", e[i].date.day, e[i].date.mon, e[i].date.year);
        j++;
    }
    if(j==0)
    printf("\n\tNo record of any employee with tenure greater than 3 years found");
}
