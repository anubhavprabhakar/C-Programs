#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *names[]={
        "Akshay",
        "Parag",
        "Raman",
        "Srinivas",
        "Gopal",
        "Rajesh"
    };
    char *temp;
    int i, j;

    printf("Names are as follows:\n");

    for(i=0; i<6; ++i)
        printf("%s\n", names[i]);

    for(i=0; i<6; ++i)
    {
        for(j=i+1; j<6; j++)
        {
            if(stricmp(names[i], names[j])>0)
            {
                temp=names[i];
                names[i]=names[j];
                names[j]=temp;
            }
        }
    }

    printf("\nAlphabatically sorted names are as follows:\n");

    for(i=0; i<6; ++i)
        printf("%s\n", names[i]);

    return 0;
}
