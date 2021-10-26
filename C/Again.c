//display total number of words in trial.txt
//display number of four letter words in trial.txt

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    FILE *s;
    int words=0, wfour=0, i;

    char str[80];

    s=fopen("trial.txt", "r");
    if(s==NULL)
    {
        printf("Cannot open source file");
        exit(1);
    }

    while(fgets(str, 79, s)!=NULL)
    {
        for(i=0; str[i]!='\0'; i++)
        {
            if(str[i]==' '||str[i]=='.'||str[i]==','||str[i]=='\n'||str[i]=='\0')
                words++;
            if(words==0&&!(str[i+1]==' '||str[i+1]=='.'||str[i+1]==','||str[i+1]=='\n'||str[i+1]=='\0'))
            {
                if(!(str[i+2]==' '||str[i+2]=='.'||str[i+2]==','||str[i+2]=='\n'||str[i+2]=='\0'))
                {
                    if(!(str[i+3]==' '||str[i+3]=='.'||str[i+3]==','||str[i+3]=='\n'||str[i+3]=='\0'))
                    {
                        if(str[i+4]==' '||str[i+4]=='.'||str[i+4]==','||str[i+4]=='\n'||str[i+4]=='\0')
                            wfour++;
                    }
                }
            }
            if(i<=74&&str[i]==' ')
            {
                if(!(str[i+1]==' '||str[i+1]=='.'||str[i+1]==','||str[i+1]=='\n'||str[i+1]=='\0'))
                {
                    if(!(str[i+2]==' '||str[i+2]=='.'||str[i+2]==','||str[i+2]=='\n'||str[i+2]=='\0'))
                    {
                        if(!(str[i+3]==' '||str[i+3]=='.'||str[i+3]==','||str[i+3]=='\n'||str[i+3]=='\0'))
                        {
                            if(str[i+4]==' '||str[i+4]=='.'||str[i+4]==','||str[i+4]=='\n'||str[i+4]=='\0')
                                wfour++;
                        }
                    }
                }
            }
        }
    }

    fclose(s);

    printf("\nTotal words: %d", words);
    printf("\nFour letter words: %d", wfour);

    return 0;
}
