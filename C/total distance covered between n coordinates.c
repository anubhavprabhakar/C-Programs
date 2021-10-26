//final distnce between n number of points(co-ordinates)
//if you go through those points, you will cover 'd' distance
//d is the variable used to store the final distance
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define N 10//change the number to the desired number of points
int main()
{
    int i, j;
    float point[N][2], d=0.0;
//taking co-ordinate positions
    printf("Enter co-ordinates(x, y) in the form:\nx\ny\n");

    for(i=0; i<N; ++i)
    {
        for(j=0; j<2;++j)
        {
            scanf("%f", &point[i][j]);
        }
        printf("\n");
    }
//computing distance between first and Nth point
    for(i=0; i<N-1; ++i)
    {
        d+=sqrt(((point[i+1][0]-point[i][0])*(point[i+1][0]-point[i][0]))+((point[i+1][1]-point[i][1])*(point[i+1][1]-point[i][1])));
    }

//final output
    printf("\nDistance between first and last co-ordinates is = %f\n", d);
    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
