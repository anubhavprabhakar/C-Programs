//multiplying two 3x3 matrices
//without using pointers
#include<stdio.h>
#include<conio.h>
int main()
{
	int m1[3][3], m2[3][3], m3[3][3]={//initialising m3 as zero
	    0,0,0,
	    0,0,0,
	    0,0,0
	    };
	int i, a, j;

//get values of both matrices
	printf("Enter matrix 1-\n");
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
			scanf("%d", &m1[i][j]);
	}

	printf("\nEnter matrix 2-\n");
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
			scanf("%d", &m2[i][j]);
	}

//calculating the product
	for(i=0;i<3;++i)
	{
		for(a=0;a<3;++a)
		{
			for(j=0;j<3;++j)
			{
				m3[i][a]+=(m1[i][j]*m2[j][a]);
			}
		}
    }

//printing the product matrix
	printf("Multplying both matrices, you get:\n\n");
	for(i=0;i<3;++i)
	{
	    for(j=0;j<3;++j)
	    {
	        printf("%d\t", m3[i][j]);
	    }
	    printf("\n");
	}
	printf("\n\nPress any key to exit");
	getch();
	return 0;
}
