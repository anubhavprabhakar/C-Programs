//displaying records in order by name
//records present in "students data.dat" on disk
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    struct stud
    {
        char name[40];
        int age;
    };
    struct stud s, stud[10], temp;
    int j, i,k;
    int n=0;

    fp=fopen("students data.DAT", "rb");
    if(fp==NULL)//checking if the file exists
        exit(1);

    while((fread(&s, sizeof(s), 1, fp))==1)
    {
        stud[n]=s;
        n++;
    }

    //compairing and sorting
    for(i=1; i<n; i++)//i<n since number of items = n-1(since n++ in line 23)
    {
        for(j=0; j<i; j++)
        {
            if(strcmp(stud[j].name, stud[i].name)>0)
            {   //sorting using insertion sort
                temp=stud[i];
                for(k=i; k>j; k--)
                {
                    stud[k]=stud[k-1];
                }
                stud[j]=temp;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        printf("Name: %-15s age: %-3d\n", stud[i].name, stud[i].age);
    }

    return 0;
}
