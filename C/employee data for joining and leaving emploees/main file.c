//main employee data file
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;
    int i=1;
    char an='y';
    struct emp
    {
        int empnum;
        char name[20];
        char sex;
        float gs;
    }e;

    s=fopen("emp data.dat", "rb+");
    if(s==NULL)
    {
        s=fopen("emp data.dat", "wb+");
        if(s==NULL)
        {
            printf("\n\n\tcannot create file emp data.dat");
            exit(1);
        }
    }

    char choice;
    int delnum, count;
    float newgs;
    long int len=sizeof(e);

    while(an=='y'||an=='Y')
    {
        printf("\nSelect:");
        printf("\n\t1.Add\n\t2.Delete\n\t3.Update\n\t4.List\n\t0.Exit");
        printf("\n\tYour choice");
        choice=getche();

        switch(choice)
        {
            case '1'://to append(add in the end file
            printf("\n\nEmployee number: ");
            scanf("%d", &e.empnum);
            printf("Employee name: ");
            fflush(stdin);
            scanf("%s", e.name);
            printf("Sex: ");
            fflush(stdin);
            e.sex=getche();
            printf("\nGross Salary: ");
            scanf("%f", &e.gs);

            fwrite(&e, len, 1, s);//write record to file
            break;

            case '2'://to delete record
            printf("\n\nEnter employee number: ");
            scanf("%d", &delnum);

            fseek(s, 0, SEEK_SET);
            count=1;
            while(fread(&e, len, 1, s)!=NULL)
            {
                if(e.empnum==delnum)
                {
                    e.gs=0;
                    count=0;
                    fseek(s, -len, SEEK_CUR);
                    fwrite(&e, len, 1, s);
                    break;
                }
            }
            if(count)
            {
                printf("\n\tNo record found for emp num %d", delnum);
            }
            break;

            case '3'://to update gross salary

            count=1;

            printf("\n\nEnter employee number: ");
            scanf("%d", &delnum);
            printf("\nEnter updated gross salary: ");
            scanf("%f", &newgs);

            fseek(s, 0, SEEK_SET);
            while(fread(&e, len, 1, s)!=NULL)
            {
                if(e.empnum==delnum)
                {
                    e.gs=newgs;
                    count=0;
                    fseek(s, -len, SEEK_CUR);
                    fwrite(&e, len, 1, s);
                    break;
                }
            }
            if(count)
            {
                printf("\n\tNo record found for employee number %d", delnum);
            }

            break;

            case '4'://to list all records in database
            fseek(s, 0, SEEK_SET);
            while(fread(&e, len, 1, s)!=NULL)
            {
                printf("\n\nEmployee number: %d", e.empnum);
                printf("\nEmployee name: %s", e.name);
                printf("\nSex: %c", e.sex);
                printf("\nGross Salary: %.2f\n", e.gs);
            }
            break;

            case '0'://to exit
            fclose(s);
            exit(0);

            default:
            printf("\n\tPlease select a valid response\n");
        }
    }

    fclose(s);
    return 0;
}
