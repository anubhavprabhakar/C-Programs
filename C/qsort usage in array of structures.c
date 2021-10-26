/*create array of structures, sort, display*/
/*used qsort func*/
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

int sort_function(const void *, const void *);
void sortbyavg();
void display();
void setdata();

struct cric_player
{
    char name[20];
    int age;
    int notest;
    float avgrun;
};
struct cric_player cp[3];
int main()
{
    /*set the values of the structure elements*/
    setdata();

    /*display all the entries present in the structure*/
    printf("\nData as entered :\n");
    display();

    /*sort the array of structures*/
    sortbyavg();
    printf("\nData sorted on Average runs:\n");
    display();

    return 0;
}

/*function used for sorting the array of the structures*/
void sortbyavg()
{
    int i, j;
    struct cric_player t;
    qsort((struct cric_player *) cp, 3, sizeof(cp[0]), sort_function);
}

int sort_function(const void *f, const void *ff)
{
    return(((struct cric_player *)f)->avgrun-((struct cric_player *)ff)->avgrun);
}

/*function to display all the entries present in the structure*/
void display()
{
    int i;
    for(i=0;i<3;++i)
    {
        printf("\n\n\tName : %s", cp[i].name);
        printf("\n\tAge : %d", cp[i].age);
        printf("\n\tNo of tests : %d", cp[i].notest);
        printf("\n\tAverage : %f", cp[i].avgrun);
    }
}

/*function to set the values of the structure*/
void setdata()
{
    int i;
    for(i=0; i<3; ++i)
    {
        printf("\nEnter the name: ");
        scanf("%s", &cp[i].name);
        fflush(stdin);

        printf("\nEnter the age: ");
        scanf("%d", &cp[i].age);
        fflush(stdin);

        printf("\nEnter the total number of test matches played:");
        scanf("%d", &cp[i].notest);
        fflush(stdin);

        printf("\nEnter the average number of runs scored in all the matches:\n\t");
        scanf("%f", &cp[i].avgrun);
        fflush(stdin);
    }
}
