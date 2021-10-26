//read records from file RECORDS.DAT, and display certain data
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;

    struct info
    {
        char name[20];
        char address[40];
        int age;
        int bloodtype;
    };
    struct info h;
    int slen=sizeof(struct info);

    s=fopen("RECORDS.DAT", "rb");

    printf("\n\tList of all donors younger than 25 years old, and blood type 2\n");

    while(fread(&h, slen, 1, s)!=NULL)
    {
        if(h.age<25&&h.bloodtype==2)
        {
            printf("\n\nName: %s", h.name);
            printf("\nAddress: %s", h.address);
            printf("\nAge: %d", h.age);
            printf("\nBloodtype: %d", h.bloodtype);
        }
    }

    fclose(s);
    _getch();//wait for keypress

    return 0;
}
