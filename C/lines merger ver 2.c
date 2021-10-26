//book prog. of lines merger, for two files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    FILE *fs1, *fs2, *ft;
    char str1[80], str2[80], source1[67], source2[67], target[67];
    char *ptrch, newl='\n';
    int flag=0;

    puts("Enter source1 file name: ");
    gets(source1);
    puts("Enter source2 file name: ");
    gets(source2);
    puts("Enter target file name: ");
    gets(target);

    fs1=fopen(source1, "r");

    if(fs1==NULL)
    {
        puts("\nUnable to open source1");
        exit(1);
    }
    fs2=fopen(source2, "r");
    if(fs2==NULL)
    {
        puts("\nUnable to open source2");
        fclose(fs1);
        exit(2);
    }
    ft=fopen(target, "w");
    if(ft==NULL)
    {
        puts("\nUnable to open target");
        fclose(fs1);
        fclose(fs2);
        exit(3);
    }

    while(fgets(str1, 79, fs1)!=NULL)
    {
        ptrch=strchr(str1, newl);
        fputs(str1, ft);
        if(!ptrch)
        {
            fputs("\n", ft);
        }

        if(fgets(str2, 79, fs2)!=NULL)
        {
            fputs(str2, ft);
            ptrch=strchr(str2, newl);
            flag=1;
            if(!ptrch)
                fputs("\n", ft);
        }
    }

    if(flag==1)
    {
        while(fgets(str2, 79, fs2)!=NULL)
        {
            fputs(str2, ft);
        }
    }

    printf("\nCopying files completed!\n");
    fclose(fs1);
    fclose(fs2);
    fclose(ft);

    return 0;
}
