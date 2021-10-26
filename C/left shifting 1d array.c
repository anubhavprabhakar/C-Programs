//circualrly shifting array by two positions
#include<stdio.h>
#include<conio.h>
#define ROW 4//Change constant value with desired number of elements in the array
#define COL 5
void rotate(int *);
int main()
{
    int p[4][5];//NUM is the number of elements in the array
    int i, j;
//taking array as input
    printf("Enter array of %d rows and %d columns:\n", ROW, COL);
    for(i=0;i<4;++i)
    {
        for(j=0;j<5;++j)
        {
            scanf("%d", &p[i][j]);
        }
        printf("\n");
    }
//printing the input array
    printf("\n\nEntered array:\n");
    for(i=0;i<4;++i)
    {
        for(j=0;j<5;++j)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
//calling the function to shift elements of the array
    rotate(*p);
//printing the shifted array
    printf("\n\nRotated array:\n");
    for(i=0;i<4;++i)
    {
        for(j=0;j<5;++j)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
//function to shift array elements
void rotate(int *p)
{
    int k, i, tt, t, j;
    for(k=0;k<4;++k)
    {
        for(i=0;i<2;++i)
        {
            t=*(p+k*5+0);
            for(j=0;j<4;++j)
            {
                tt=*(p+k*5+j);
                *(p+k*5+j)=*(p+k*5+j+1);
                *(p+k*5+j+1)=tt;
            }
            *(p+k*5+j+1)=t;
        }
    }
}
