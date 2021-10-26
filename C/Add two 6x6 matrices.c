//Adding two 6x6 matrices
//without using pointers
#include<stdio.h>
#include<conio.h>
int main()
{
	int m1[6][6], m2[6][6], m3[6][6];
	int i, j;
    printf("(Hit Enter after each individual entry)\n\n");
//getting both matrices from user
	printf("Enter a 6x6 matrix\n");
	for(i=0;i<6;++i)
	{
		for(j=0;j<6;++j)
			scanf("%d", &m1[i][j]);
        printf("\n");
	}

	printf("Enter another 6x6 matrix 2\n");
	for(i=0;i<6;++i)
	{
		for(j=0;j<6;++j)
			scanf("%d", &m2[i][j]);
        printf("\n");
	}

//displaying matrices as they are
	printf("The matrices are-\n\nMatrix 1:\n");
	for(i=0;i<6;++i)
	{
		for(j=0;j<6;++j)
			printf("%d\t", m1[i][j]);
		printf("\n");
	}

	printf("\n\nMatrix 2:\n");
	for(i=0;i<6;++i)
	{
		for(j=0;j<6;++j)
			printf("%d\t", m2[i][j]);
		printf("\n");
	}

//Addition and printing of sum simultaneously
	printf("Adding the two matrices you get:\n");\
	for(i=0;i<6;++i)
	{
		for(j=0;j<6;++j)
			printf("%d\t", m1[i][j]+m2[i][j]);
		printf("\n");
	}
    printf("\nPress any key to exit");
    getch();
	return 0;
}
