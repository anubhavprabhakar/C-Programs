/*Menu driven program for elementary database mangaement*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

void gotoxy(short int col, short int row);

int main()
{
    FILE *fp, *ft;
    char another, choice;
    int line=2;

    struct emp
    {
        char name[40];
        int age;
        float bs;
    };
    struct emp e;

    char empname[40];
    long int recsize;

    fp=fopen("dbms.DAT", "rb+");

    if(fp==NULL)
    {
        fp=fopen("dbms.DAT", "wb+");

        if(fp==NULL)
        {
            puts("Cannot open file");
            exit(1);
        }
    }

    recsize=sizeof(e);

    while(1)
    {
        system("cls");

        gotoxy(30, line);
        printf("1. Add Records");
        gotoxy(30, line+2);
        printf("2. List records");
        gotoxy(30, line+4);
        printf("3. Modify records");
        gotoxy(30, line+6);
        printf("4.Delete records");
        gotoxy(30, line+8);
        printf("0. Exit");
        gotoxy(30, line+10);
        printf("Please Choose");

        fflush(stdin);
        choice=getche();
        switch(choice)
        {
            case '1':
                fflush(stdin);

                fseek(fp, 0, SEEK_END);
                another='Y';

                while(another=='Y'||another=='y')
                {
                    printf("\nEnter name, age, and basic salary");
                    scanf("%s %d %f", e.name, &e.age, &e.bs);

                    fwrite(&e, recsize, 1, fp);
                    printf("\nAdd another record (Y/N)");
                    fflush(stdin);
                    another=getche();
                }

                fflush(stdin);

                break;

            case '2':
                fflush(stdin);

                rewind(fp);

                while(fread(&e, recsize, 1, fp))
                    printf("\n%-10s %-3d %8.2f", e.name, e.age, e.bs);

                getch();
                fflush(stdin);

                break;

            case '3':
                fflush(stdin);

                another='Y';
                while(another=='Y'||another=='y')
                {
                    printf("\nEnter the name of employee to modify");
                    scanf("%s", empname);

                    rewind(fp);
                    while(fread(&e, recsize, 1, fp))
                    {
                        if(!(strcmp(e.name, empname)))
                        {
                            printf("\nEnter new name, age, & bs");
                            scanf("%s %d %f", e.name, &e.age, &e.bs);

                            fseek(fp, -recsize, SEEK_CUR);
                            fwrite(&e, recsize, 1, fp);
                            break;
                        }
                    }

                    printf("\nModify another record (Y/N)");
                    fflush(stdin);
                    another=getche();
                }

                fflush(stdin);

                break;

            case '4':
                fflush(stdin);

                another='Y';
                while(another=='Y'||another=='y')
                {
                    printf("\nEnter name of employee to delete");
                    scanf("%s", empname);

                    ft=fopen("TEMP.DAT", "wb");

                    rewind(fp);
                    while(fread(&e, recsize, 1, fp)==1)
                    {
                        if(stricmp(e.name, empname))
                            fwrite(&e, recsize, 1, ft);
                    }

                    fclose(fp);
                    fclose(ft);

                    remove("dbms.DAT");
                    rename("TEMP.DAT", "dbms.DAT");

                    fp=fopen("dbms.DAT", "rb+");

                    printf("Delete another record (Y/N)");
                    fflush(stdin);

                    another=getche();
                }

                fflush(stdin);

                break;

            case '0':
                fclose(fp);
                exit(0);
        }
    }
    return 0;
}
void gotoxy(short int col, short int row)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {col, row};
    SetConsoleCursorPosition(hStdout, position);
}
