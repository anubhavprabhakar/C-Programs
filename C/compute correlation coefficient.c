//finding correlation constant with the formula given below:
//r=(∑xy - ∑x∑y)/√((n∑x^2 - (∑x)^2)(n∑y^2 - (∑y)^2))
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define N 11//change the number to the desired number of data points
int main()
{
    int n, i, j;
    float r, xy=0, x=0, y=0, x2=0, y2=0;
    float data[N][2];

    float r1, r2;

    printf("Enter data in the format:\nx\ny\n\n");
//taking input
    for(i=0;i<N;++i)
    {
        for(j=0;j<2;++j)
        {
            scanf("%f", &data[i][j]);
        }
        printf("\n");
    }
//displaying the input data
    printf("\n\ndata entered is as follows:\n    x\t\t     y\n");

    for(i=0; i<N; ++i)
    {
        for(j=0; j<2; ++j)
            printf("%f\t", data[i][j]);
        printf("\n");
    }
//processing the data
    for(i=0; i<N; i++)
    {
        xy+=data[i][0]*data[i][1];
        x+=data[i][0];
        y+=data[i][1];
        x2+=data[i][0]*data[i][0];
        y2+=data[i][1]*data[i][1];
    }
    r=(xy-(x*y))/sqrt(((N*x2)-(x*x))*((N*y2)-(y*y)));
//displaying the final solution
    printf("\n\nCorrelation coefficient is = %f\n\n", r);
    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
