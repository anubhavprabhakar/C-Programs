#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 6
int main()
{
    char n[50];
    int len, i, j, k, l;
    char *p;
    char *names[NUM];
    char *temp;

    printf("Enter %d names only: \n", NUM);

    for(i=0; i<NUM; ++i)
    {
        printf("\nName %d: ", i+1);
        gets(n);
        len=strlen(n);
        p=(char*)malloc(len+1);
        strcpy(p,n);
        names[i]=p;
        free(n);
    }
    printf("\nNames Entered:\n");
    for(i=0; i<NUM; i++)
        printf("%s\n", names[i]);

    for(i=0; i<NUM; ++i)
    {
        for(j=i+1; j<NUM; j++)
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

    for(i=0; i<NUM; ++i)
        printf("%s\n", names[i]);

    return 0;
}
