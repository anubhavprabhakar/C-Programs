/*input ranks of 5 players, by three judges*/
/*determine mvp, player with the highest rank*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct player
{
    char name[20];
    int rank[3];//to store ranks by three judges
    int total;//to total ranks by all judges
};
struct player p[]={
    "Sachin", {0}, 0,
    "Pranav", {0}, 0,
    "Sanchit", {0}, 0,
    "Rohit", {0}, 0,
    "Akash", {0}, 0
};
int main()
{
    char winner[20];
    int i, judge, win;
    for(judge=0; judge<3; judge++)
    {
        printf("\n\tEnter ranking by judge %d", judge+1);
        for(i=0; i<5; ++i)//one for each player
        {
            printf("\n\n\t\tPlayer name: %s", p[i].name);
            printf("\n\n\t\tRank: ");
            scanf("%d", &p[i].rank[judge]);
            /*check whether rank is legal*/
            if(p[i].rank[judge]>5||p[i].rank[judge]<1)
            {
                printf("\n\a\tWrong input");
                exit(0);
            }
            p[i].total+=p[i].rank[judge];//totalling the ranks
        }
    }

    win=p[0].total;
    /*finding out the highest total*/
    for(i=0; i<5; ++i)
    {
        (p[i].total>win?(win=p[i].total):(win));//conditional operator
    }

    i=0;
    /*finding out the position of the name of highest rank holder in the array*/
    while(p[i].total!=win)
        i++;

    printf("\n\tMVP is %s", p[i].name);//winner takes it all

    return 0;
}
