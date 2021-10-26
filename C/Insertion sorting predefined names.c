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
    int i, j, k, l;

    printf("Names are as follows:\n");

    for(i=0; i<6; ++i)
        printf("%s\n", names[i]);

    for(i=1; i<6; ++i)
    {
        for(j=0; j<i; j++)
        {
            if(stricmp(names[i], names[j])<0)
            {
                k=1;
                l=i;
                temp=names[i];
                while((i-k)!=j)
                {
                    names[l]=names[l-k];
                    l=l-k;
                    k++;
                }
                names[j]=temp;
            }
        }
    }

    printf("\nAlphabatically sorted names are as follows:\n");

    for(i=0; i<6; ++i)
        printf("%s\n", names[i]);

    return 0;
}
