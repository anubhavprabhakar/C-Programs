//append two files, without using the predefined append feature
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *s, *temp;
    char str1[80], s1[256], s2[256], t[256];
    printf("Enter source 1(with extension)\n");
    gets(s1);
    printf("Enter source 2(with extension)\n");
    gets(s2);
    printf("Enter target file name(with extension)\n");
    gets(t);

    s=fopen(s1, "r");
    temp=fopen(t, "w");

    if(s==NULL)
    {
        exit(1);
    }

    while(fgets(str1, 79, s)!=NULL)
    {
        fputs(str1, temp);
    }

    fputs("\n", temp);

    s=fopen(s2, "r");

    while(fgets(str1, 79, s)!=NULL)
    {
        fputs(str1, temp);
    }

    fclose(temp);
    fclose(s);

    printf("\nCopying files completed!\n");

    return 0;
}
