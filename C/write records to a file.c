/*write records to a file using structure*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *fp;
    struct emp
    {
        char name[40];
        int age;
        float bs;
    };
    struct emp e;
    char another='Y';

    fp=fopen("Employee.dat", "w");
    if(fp==NULL)
    {
        puts("Cannot open file");
        exit(1);
    }

    while(another=='Y'||another=='y')
    {
        printf("\nEnter name, age, basic salary\n");
        scanf("%s %d %f", e.name, &e.age, &e.bs);
        fprintf(fp, "%s %d %f\n", e.name, e.age, e.bs);

        fflush(stdin);
        printf("Add another record?(Y/N)");
        another = getche();
    }
    fclose(fp);
    return 0;
}
