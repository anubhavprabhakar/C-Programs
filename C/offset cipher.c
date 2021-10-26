//encrypt/decrypt by offset cipher
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void code();
void decode();

int encdec=128;//offset value
FILE *s, *t;
int ch;

int main()
{
    char choice, source[80];
    printf("Enter name of source file\n");
    gets(source);

    s=fopen(source, "r");
    if(s==NULL)
        exit(1);

    printf("\n\nPress E for encryption, or press D for decryption");
    choice=getche();

    switch(choice)
    {
        case 'e':

        t=fopen("ENC file.txt", "w");
        if(t==NULL)
            exit(2);

        code();

        printf("\nEncrypting task done successfully!");
        break;

        case 'd':

        t=fopen("DEC file.txt", "w");
        if(t==NULL)
            exit(3);

        decode();

        printf("\nDecrypting task done successfully!");
        break;

        default:
        printf("\nPlease select a valid option and try again.");
    }
    fclose(s);
    fclose(t);

    return 0;
}

void code()
{
    while((ch=fgetc(s))!=EOF)
        {
            ch=ch+encdec;
            fputc(ch, t);
        }
}

void decode()
{
    while((ch=fgetc(s))!=EOF)
        {
            ch=ch-encdec;
            fputc(ch, t);
        }
}
