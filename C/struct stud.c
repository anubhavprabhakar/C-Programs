//create structure to hold student data
#include<stdio.h>
#include<stdlib.h>
struct stud
{
    int rn;
    char name[20];
    char dep[15];
    char course[10];
    int yoj;
};
struct stud s[2];

void set_student_data();
void display();
void name_acc_year(int);
int data_acc_rollno(int);

int main()
{
    int i, r;
    int y;

    printf("\nEnter the data for each student:\n\n");

    /*initialize the values for the student structure*/
    set_student_data();

    /*Display all the elelments of the student structure*/
    display();

    /*Search data on the year of joining*/
    printf("\nEnter the year of joining of the students:");
    scanf("%d", &y);

    name_acc_year(y);/*year of joining passed to function*/

    /*Search data based on roll no*/
    printf("\nEnter the roll number of the student:");
    scanf("%d", &r);

    data_acc_rollno(r);/*roll number passed to function*/
    return 0;
}

void set_student_data()/*Enter student data*/
{
    int i;
    for(i=0;i<2;i++)
    {
        fflush(stdin);/*flush the input buffer*/
        printf("\nEnter the roll number of the student\n");
        scanf("%d", &s[i].rn);
        fflush(stdin);
        printf("Enter the name of the student");
        scanf("%s", s[i].name);
        fflush(stdin);
        printf("Enter the name of the department");
        scanf("%s", s[i].dep);
        fflush(stdin);
        printf("Enter the name of the course");
        scanf("%s", s[i].course);
        fflush(stdin);
        printf("Enter the year of joining");
        scanf("%d", &s[i].yoj);
    }
}

/*function to display data*/
void display()
{
    int i;
    for(i=0;i<2;++i)
    {
        printf("\n\tRoll number : %d\n", s[i].rn);
        printf("\n\tName of the student is %s\n", s[i].name);
        printf("\n\tName of the department is %s\n", s[i].dep);
        printf("\n\tName of the course is %s\n", s[i].course);
        printf("\n\tYear of joining of the student is %d\n", s[i].yoj);
    }
}

/*function to get name based on year of joining*/
void name_acc_year(int y)
{
    int i, j=0;
    for(i=0;i<2;++i)
    {
        if(y==s[i].yoj)
        {
            printf("%s joined in the year %d\n", s[i].name, y);
            j=1;
        }
    }
    if(j==0)
        printf("\nNo student joined in the year %d\n", y);
}

/*function to get student data based on roll number*/
int data_acc_rollno(int r)
{
    int i, j=0;
    for(i=0; i<2; ++i)
    {
        if(s[i].rn==r)
        {
            printf("\n\tRoll Number:%d\n\n\tName of the student is %s\n\n\tName of the department is %s\n\n\tName of the course is %s\n\n\tYear of joining is: %d\n", r, s[i].name, s[i].dep, s[i].course, s[i].yoj);
            j=1;
        }
    }
    if(j==0)
        printf("\nNo such roll number present");
}
