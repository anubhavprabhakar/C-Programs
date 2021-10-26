/*Create structure to store engine part data*/
#include<stdio.h>
struct automobile
{
    int sno;
    int yom;
    char material[20];
    int quantity;
};
struct automobile part[2];

void retrieve();
void display();
void setautodata();

int main()
{
    int i;

    /*set the values for the records*/
    setautodata();

    /*list all records*/
    display();

    /*retrieve info on parts with serial numbers between BB1 and CC6*/
    retrieve();
    return 0;
}

void retrieve()
{
    int i, j=0;

    printf("\n\nList of parts between BB1 and CC6:");
    for(i=0;i<2; i++)
    {
        if((part[i].sno>=0xbb1)&&(part[i].sno<=0xcc6))
        {
            j=1;
            printf("\n\n\tPart number = %d", i);
            printf("\nSerial number = %x", part[i].sno);
            printf("\nYear of Manufacture = %d", part[i].yom);
            printf("\nMaterial used: %s", part[i].material);
            printf("\nManufacture Quantity = %d", part[i].quantity);
        }
    }
    if(j==0)
        printf("\nNo such record present");
}

void display()
{
    int i;

    for(i=0;i<2; ++i)
    {
        printf("\n\n\tPart number = %d", i);
        printf("\nSerial number = %x", part[i].sno);
        printf("\nYear of Manufacture = %d", part[i].yom);
        printf("\nMaterial used: %s", part[i].material);
        printf("\nManufacture Quantity = %d", part[i].quantity);
    }
}

void setautodata()
{
    int i;
    for(i=0; i<2; ++i)
    {
        while(1)
        {
            printf("\nEnter the serial number of the part");
            printf("\nNumber must be between AA0 and FF9\n ");
            scanf("%x", &part[i].sno);
            if(part[i].sno>=0xAA0&&part[i].sno<=0xff9)
                break;
        }
        printf("\nEnter the year of manufacturing of the part:");
        scanf("%d", &part[i].yom);

        printf("\nEnter the material of the part");
        scanf("%s", &part[i].material);
        fflush(stdin);
        printf("\nEnter the quantity of the part");
        scanf("%d", &part[i].quantity);
    }
}
