//Computing standard deviation and mean
#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
    int data[15]={-6, -12, 8, 13, 11, 6, 7, 2, -6, -9, 2, 11, 10, 9, -10};
    float std[15], mean=0;
    int i, n=15;
//print the data items
    for(i=0; i<=14; ++i)
    {
        printf("%d  ", data[i]);
    }
//calculating mean
    for(i=0;i<=14;++i)
    {
        mean=mean+data[i];
    }
    mean=mean/n;
//calculating standard deviation
    for(i=0;i<15;++i)
    {
        std[i]=sqrt(pow((data[i]-mean), 2))/n;
    }
//printing mean and standard deviation
    printf("\n\n Mean=%f\n\n", mean);
    for(i=0;i<15;++i)
    {
        printf("\nStandard deviation of %d = %f\n", data[i], std[i]);
    }
    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
