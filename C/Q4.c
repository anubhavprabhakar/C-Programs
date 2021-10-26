#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
    char *c[]={"US", "UK", "Europe", "India"};
    float ussize[]={5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10, 10.5, 11, 11.5, 12, 13, 14, 15, 16};
    float ukindsize[]={4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10, 10.5, 11, 12, 13, 14, 15};
    float europesize[]={39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46, 47, 48, 49, 50};
    char country[10];
    float shoesize;
    int i;

    printf("Enter your location: ");
    gets(country);
    strupr(country);
    printf("Enter your shoe size: ");
    scanf("%f", &shoesize);
    printf("\n");

    for(i=0; i<5; i++)
    {
        if(stricmp(c[i], country)==0)
            break;
    }

    if(stricmp(c[i], country)!=0)
    {
        printf("\nEnter location properly");
        getch();
        return 0;
    }

    switch (i)
    {
        case 0:
        if(shoesize<5.5||shoesize>16)
            {
                printf("\nEnter valid size\n");
                getch();
                return 0;
            }
            for(i=0; i<18; ++i)
            {
                if(shoesize==ussize[i])
                    break;
            }
            printf("US size:\t%5.2f\nUK size:\t%5.2f\nEurope size:\t%5.2f\nIndia size:\t%5.2f", ussize[i], ukindsize[i], europesize[i], ukindsize[i]);
            break;

        case 1:
            if(shoesize<4.5||shoesize>15)
            {
                printf("\nEnter valid size\n");
                getch();
                return 0;
            }
            for(i=0; i<18; ++i)
            {
                if(shoesize==ukindsize[i])
                    break;
            }
            printf("US size:\t%5.2f\nUK size:\t%5.2f\nEurope size:\t%5.2f\nIndia size:\t%5.2f", ussize[i], ukindsize[i], europesize[i], ukindsize[i]);
            break;

        case 2:
        if(shoesize<39||shoesize>50)
            {
                printf("\nEnter valid size\n");
                getch();
                return 0;
            }
            for(i=0; i<18; ++i)
            {
                if(shoesize==europesize[i])
                    break;
            }
            printf("US size:\t%5.2f\nUK size:\t%5.2f\nEurope size:\t%5.2f\nIndia size:\t%5.2f", ussize[i], ukindsize[i], europesize[i], ukindsize[i]);
            break;

        case 3:
            if(shoesize<4.5||shoesize>15)
            {
                printf("\nEnter valid size\n");
                getch();
                return 0;
            }
            for(i=0; i<18; ++i)
            {
                if(shoesize==ukindsize[i])
                    break;
            }
            printf("US size:\t%5.2f\nUK size:\t%5.2f\nEurope size:\t%5.2f\nIndia size:\t%5.2f", ussize[i], ukindsize[i], europesize[i], ukindsize[i]);
            break;
    }

    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
