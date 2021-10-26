//merge lines from two files
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *s1, *s2, *t;

    char ch1, ch2;
    char so1[80], so2[80], tar[80];

    printf("Enter name of source file 1 (with extension)\n");
    gets(so1);
    printf("Enter name of source file 2 (with extension)\n");
    gets(so2);
    printf("Enter name of target file(with extension)\n");
    gets(tar);

    s1=fopen(so1, "r");
    s2=fopen(so2, "r");
    t=fopen(tar, "w");

    if(s1==NULL||s2==NULL||tar==NULL)
    {
        printf("\nCannot open/create file");
        exit(1);
    }

    while(1)
    {
        while((ch1=fgetc(s1))!='\n'&&ch1!=EOF)
        {
            fputc(ch1, t);
        }
        while((ch2=fgetc(s2))!='\n'&&ch2!=EOF)
        {
            fputc(ch2, t);
        }
        if(ch1!=EOF||ch2!=EOF)//if more lines left in any one files
            fputc('\n', t);
        else//break if both the files reached EOF
            break;
    }

    fclose(s1);
    fclose(s2);
    fclose(t);

    printf("\nTask completed!\nLines merged!");

    return 0;
}
