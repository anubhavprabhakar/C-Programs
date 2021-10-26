//Copy contents, and convert lowercase letters to uppercase
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *s, *t;
    char ch, source[256], target[256];
    printf("Enter source file name(with extension)\n");
    gets(source);
    printf("Enter target file name(with extension)\n");
    gets(target);

    s=fopen(source, "r");
    t=fopen(target, "w");

    if(s==NULL||t==NULL)
    {
        printf("\ncannot open/create file");
        exit(1);
    }

    while((ch=fgetc(s))!=EOF)
    {
        if(ch>=97&&ch<=122)
        {
            ch-=32;
        }
        fputc(ch, t);
    }

    printf("\nFile copied!\nAll characters converted to upper case!\nProcess completed!\n");

    fclose(s);
    fclose(t);

    return 0;
}
