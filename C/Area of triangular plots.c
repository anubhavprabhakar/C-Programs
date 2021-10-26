//calculating area of triangular plots
//using sine law
//and finding the largest plot
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define NUM 6 //set the digit to desired number of triangles
float area(float *);//to calculate area
int largest(float *);//to find largest plot
int main()
{
    int i, j, biggest;
    float line[3], ar[NUM];
    float tri[NUM][4];

    printf("Enter data in the format: \n plot no.\n side length a\n side length b\n sine of angle between a and b\n\n");
//taking input in array
    for(i=0; i<NUM; ++i)
    {
        for(j=0; j<4; ++j)
        {
            scanf("%f", &tri[i][j]);
        }
    }


//passing values to area() function
    for(i=0;i<NUM;++i)
    {
        for(j=1;j<4;j++)
        {
            line[j-1]=tri[i][j];
        }
        ar[i]=area(line);
    }
//printing area of plots
    for(i=0;i<NUM;++i)
    {
        printf("\n\nPlot no. %d, area=%f", i+1, ar[i]);
    }
//largest plot:
    biggest=largest(ar);
    printf("\n\n\nLargest Plot is %d and has area = %f\n\n", biggest+1, ar[biggest]);
    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
//area() function
float area(float *line)
{
    float ar=(0.5)*line[0]*line[1]*sin(line[2]);
    return ar;
}
//funtion to find out the largest plot
int largest(float *area)
{
    int i, a=0;
    for(i=0; i<NUM; ++i)
    {
        if(area[i]>a)
        a=i;
    }
    return a;
}
