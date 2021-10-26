//substitution cipher
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//substitution values in below two lines
char enc[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '\n', '\0'};
char dec[]={'!', '@', '%', '#', '$', '8', '0', '6', '9', '7', '5', '3', '1', '2', '4', '^', '*', ')', '&', '(', 'q', 'a', 'z', 'w', 'e', 'r', 's', 't', 'y', 'u', 'i', 'o', 'p', 'x', 'd', 'f', 'g', 'h', 'j', ';', '[', '|', '.', '<', '/', '"', ':', 'b', 'c', 'v', 'n', 'm', 'k', 'l', 'P', 'L', 'M', 'Q', 'E', ' ', 'A', 'S', 'G', 'T', '\0'};

void code();
void decode();

FILE *s, *t;//file pointers
char ch, c;

int main()
{
    char source[80];
    printf(">>Make sure the file to be encrypted is in same folder as this app<<\n");
    printf("\nEnter source file name(with extension, for eg: code word.txt)\n");
    gets(source);

    s=fopen(source, "r");//initiate pointer to source file

    if(s==NULL)//if the source file doesnt open, returns 1
    {
        printf("\nFailed to open source file\nMake sure to check if all conditions are met\nPress any key to exit");
        _getch();
    }
        exit(1);

    printf("\nPress e for encryption, or d for decryption\n");
    ch=_getch();//to store the key pressed in char ch variable

    switch(ch)
    {
        case 'e': case 'E':

        t=fopen("ENC file.txt", "w");//to create 'ENC file.txt', and assign file pointer 't' to it

        if(t==NULL)//if failed to open target file 'ENC file.txt', returns 2
        {
            printf("\nFailed to create target file\nPress any key to exit");
            _getch();//to register a key press
            exit(2);
        }

        code();//calling function 'void code()'

        printf("\nEncrypting done successfully!");
        printf("\nPress any key to exit.");
        _getch();//to register a key press

        break;

        case 'd': case 'D':

        t=fopen("DEC file.txt", "w");

        if(t==NULL)//if failed to open target file 'ENC file.txt', returns 3
        {
            printf("\nFailed to create target file\nPress any key to exit");
            _getch();//to register a key press
            exit(3);
        }

        decode();//calling function 'void decode'

        printf("\nDecrypting done successfully");
        printf("\nPress any key to exit.");
        _getch();//to register a key press

        break;

        default:
        printf("\nProcess failed. Please select options carefully.\nTry again.");
    }
    //closing file pointers
    fclose(s);
    fclose(t);

    return 0;
}

void code()
{
    int i, done=0;//'done' is encryption counter in this function
    while((c=fgetc(s))!=EOF)//run loop until the end of file is not met
    {
        for(i=0; i<=63; i++)
        {
            if(c==enc[i])//match character from the list
            {
                fputc(dec[i], t);//encryption
                done=1;//count the encryption
                break;
            }
        }
        if(done==0)//if encryption counter is set to 0
        {
            fputc(c, t);//put the character as it is
        }
    }
}


void decode()
{
    int i, done=0;//'done' is decryption counter in this function
    while((c=fgetc(s))!=EOF)//run loop until the end of file is not met
    {
        for(i=0; i<=63; i++)
        {
            if(c==dec[i])//match character from the list
            {
                fputc(enc[i], t);//decryption
                done=1;//count the decryption
                break;
            }
        }
        if(done==0)//if decryption counter is set to 0
        {
            fputc(c, t);//put the character as it is
        }
    }
}
