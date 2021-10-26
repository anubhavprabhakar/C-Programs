//displaying line number is a read-only file
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *s;
    char ch;
    char source[256];
    int nline=1;

    printf("Enter source file name(with extension)\n");
    gets(source);
    printf("\n");
    s=fopen(source, "r");

    if(s==NULL)
    {
        exit(1);
    }

    printf("line %d: ", nline++);

    while((ch=fgetc(s))!=EOF)
    {
        printf("%c", ch);
        if(ch=='\n')
        {
            printf("\nline %d: ", nline++);
        }
    }
    fclose(s);
    return 0;
}
