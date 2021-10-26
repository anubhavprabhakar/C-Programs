/*determining hurricane category*/
#include<stdio.h>
#include<string.h>

int main()
{
    struct hur
    {
        int ls;
        int hs;
        char cat[10];
    };
    struct hur h[]={
        74, 95, "I",
        96, 110, "II",
        111, 130, "III",
        131, 155, "IV",
        156, 200, "V"
    };
    int ws, i;

    printf("\nEnter wind speed:");
    scanf("%d", &ws);

    for(i=0; i<5; ++i)
    {
        if(h[i].ls<=ws && ws<=h[i].hs)
            printf("Category of hurricane is %s", h[i].cat);
    }
    return 0;
}
