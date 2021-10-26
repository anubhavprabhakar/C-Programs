//enter students name and age in records
//file stored on disk
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int main()
{
    FILE *fp;
    struct emp
    {
        char name[40];
        int age;
    };
    struct emp e;
    char another = 'y';

    fp=fopen("students data.DAT", "wb");
    if(fp==NULL)
    {
        exit(1);
    }

    while(another=='y'||another=='Y')
    {
        printf("\nEnter name, and age of students\n");
        scanf("%s %d", e.name, &e.age);
        fwrite(&e, sizeof(e), 1, fp);
        printf("\nWant to enter another record? Y/N\n");
        another=getche();
    }

    fclose(fp);
    return 0;
}
