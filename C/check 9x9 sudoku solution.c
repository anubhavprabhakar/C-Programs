//check if the solution of a 9x9 sudoku is correct or not, and display the row and column which has errors
#include<stdio.h>
#include<conio.h>
int main()
{
    int sud[9][9];
    int i, j, k, l=0;
    printf("Enter the sudoku solution:\n(Warning: maintain consistency in entering row wise or column wise)\n\n");
    //storing solution as 9x9 array
    for(i=0;i<9;++i)
    {
        for(j=0;j<9;++j)
        {
            scanf("%d", &sud[i][j]);
        }
        printf("\n");
    }
    //displaying the solution sudoku
    printf("\n\nYour solution is:\n\n");
    for(i=0;i<9;++i)
    {
        for(j=0;j<9;++j)
        {
            printf("%d ", sud[i][j]);
        }
        printf("\n");
    }
    //checking solution
    for(i=0;i<9;++i)
    {
        for(j=0;j<9;++j)
        {
            for(k=0;k<9;++k)
            {
                if(k!=j)
                {
                    if(sud[i][j]==sud[i][k])
                    {
                        printf("\nProblem in row %d", i);
                        l++;
                    }
                }
                if(k!=i)
                {
                    if(sud[i][j]==sud[k][j])
                    {
                        printf("\nProblem in column %d", j);
                        l++;
                    }
                }
            }
        }
    }

    if(l==0)
    printf("\nThe solution is correct\n\n");
    printf("\n\nPress any key to exit");
    getch();
    return 0;
}
