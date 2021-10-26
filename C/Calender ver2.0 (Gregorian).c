#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void cal(int, int, int, int);
void gotoxy(short int col, short int row);
//external variable, so as to use across functions
char *months[]={
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//days of every month, leap februray will be updated later

int getkey();

int main()
{
    int year, mon, day, d, i=0, ch;
    while(i==0)
    {
        //taking inputs
        printf("Enter the year: ");
        scanf("%d", &year);
        if(year<1)
        {
            printf("\nInvalid input: Enter year correctly\n\n");
            continue;
        }
        month:
        printf("Enter the number of the month(for ex- 4 for April): ");
        scanf("%d", &mon);
        day=((year-1)*365)+(((year-1)/4)-((year-1)/100)+((year-1)/400));

        //verifying the inputs
        if(mon>12||mon<1)
        {
            printf("\nInvalid input: Enter correct month\n\n");
            goto month;
        }


        //if its a leap year, update second month in days[] to 29 days
        if((year%100==0&&year%400==0)||(year%4==0&&year%100!=0))
            days[1]=29;

        //calculating number of days before the selected month
        for(i=0; i<(mon-1); i++)
            day+=days[i];
        day=day%7;//calculating final day, 0 for Sunday and so on

        cal(day, mon, year, days[mon-1]);//passing final day, month, year, and number of days in the input month

        keytap://checkpoint
        printf("\nPress:\n\nesc key: exit calender version 2.0\n\nUP arrow: Next year, same month\nDown arrow: Last year, same month\nRight arrow: Same year, next month\nLeft arrow: Same year, last month\n\nPress any key");
        ch=getkey();
        switch (ch)
        {
            case 72://up arrow
            year+=1;//next year
            day=((year-1)*365)+(((year-1)/4)-((year-1)/100)+((year-1)/400));
            //if its a leap year, update second month in days[] to 29 days
            if((year%100==0&&year%400==0)||(year%4==0&&year%100!=0))
                days[1]=29;
            else
                days[1]=28;//reduce feb back to 28 days, in days[] function

            //calculating number of days before the selected month
            for(i=0; i<(mon-1); i++)
                day+=days[i];
            day=day%7;//calculating final day, 0 for Sunday and so on
            cal(day, mon, year, days[mon-1]);//passing final day, month, year, and number of days in the input month
            goto keytap;//go to checkpoint

            case 80://down arrow
            year-=1;
            day=((year-1)*365)+(((year-1)/4)-((year-1)/100)+((year-1)/400));
            //if its a leap year, update second month in days[] to 29 days
            if((year%100==0&&year%400==0)||(year%4==0&&year%100!=0))
                days[1]=29;
            else
                days[1]=28;//reduce feb back to 28 days, in days[] function


            //calculating number of days before the selected month
            for(i=0; i<(mon-1); i++)
                day+=days[i];
            day=day%7;//calculating final day, 0 for Sunday and so on
            cal(day, mon, year, days[mon-1]);//passing final day, month, year, and number of days in the input month
            goto keytap;//go to checkpoint

            case 77://right arrow, for next month
            mon+=1;

            day=((year-1)*365)+(((year-1)/4)-((year-1)/100)+((year-1)/400));
            //if its a leap year, update second month in days[] to 29 days
            if((year%100==0&&year%400==0)||(year%4==0&&year%100!=0))
                days[1]=29;
            else
                days[1]=28;//reduce feb back to 28 days, in days[] function

            //calculating number of days before the selected month
            for(i=0; i<(mon-1); i++)
                day+=days[i];
            day=day%7;//calculating final day, 0 for Sunday and so on
            cal(day, mon, year, days[mon-1]);//passing final day, month, year, and number of days in the input month
            goto keytap;//go to checkpoint

            case 75://left arrow, for previous month
            mon-=1;

            day=((year-1)*365)+(((year-1)/4)-((year-1)/100)+((year-1)/400));
            //if its a leap year, update second month in days[] to 29 days
            if((year%100==0&&year%400==0)||(year%4==0&&year%100!=0))
                days[1]=29;
            else
                days[1]=28;//reduce feb back to 28 days, in days[] function


            //calculating number of days before the selected month
            for(i=0; i<(mon-1); i++)
                day+=days[i];
            day=day%7;//calculating final day, 0 for Sunday and so on
            cal(day, mon, year, days[mon-1]);//passing final day, month, year, and number of days in the input month
            goto keytap;//go to checkpoint

            case 27://esc key
                exit(0);//exit from the program

            default:
                system("CLS");
                printf("\nPlease Press a valid key\n");
                goto keytap;
        }

        return 0;
    }
}

//function to set date and day on calender
void cal(int d, int m, int y, int p)
{
    int i, r, c;

    system ("CLS");
    gotoxy(25, 2);
    printf("%s %d", months[m-1], y);

    gotoxy(5, 5);
    printf("---------------------------------------------------");

    gotoxy(10, 6);
    printf("Mon   Tue   Wed   Thu   Fri   Sat   Sun");

    gotoxy(5, 7);
    printf("---------------------------------------------------");

    r=8;
    c=11+6*d;//so that numbers follow the proper seperation

    for(i=1; i<=p; i++)
    {
        gotoxy(c, r);
        printf("%d", i);

        if(c<=41)
            c+=6;//so that cursor changes line when last day reached in row
        else
        {
            c=11;
            r++;
        }
    }
    printf("\n\n");


}

//function to print the calender design
void gotoxy(short int col, short int row)
{
    HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={col, row};
    SetConsoleCursorPosition(hStdout, position);
}
//to find out which key is pressed
int getkey()
{
    int ch;
    ch=getch();//fetches character code of the key pressed
    if(ch==0)//if enter key is pressed
    {
        ch=getch();
    }
    return ch;
}
