//hospital blood donor records for file RECORDS.DAT
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;
    char c='y';

    struct info
    {
        char name[20];
        char address[40];
        int age;
        int bloodtype;
    };
    struct info h;
    int slen=sizeof(struct info);

    s=fopen("RECORDS.DAT", "wb");

    while(c=='y'||c=='Y')
    {
        fflush(stdin);//clearing since the next input is a string
        printf("\n\nEnter donor name[20 characters only]: ");
        gets(h.name);

        fflush(stdin);//since the next input is a string
        printf("\nEnter donor address[40 characters only]: ");
        gets(h.address);

        printf("\nEnter donor age: ");
        scanf("%d", &h.age);

        marker1:
        printf("\nEnter donor blood type(1, 2, 3, or 4): ");
        scanf("%d", &h.bloodtype);

        if(h.bloodtype>4||h.bloodtype<1)//checking if bloodtype entered correctly
        {
            printf("\n\tEnter bloodtype correctly.\n");
            goto marker1;
        }

        fwrite(&h, slen, 1, s);

        printf("\n\n\tWant to print another record?(Y/N)");
        c=_getch();//take input from user
    }

    fclose(s);

    return 0;
}
