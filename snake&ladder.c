//header files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#include<Windows.h>

//Snakes and Ladder in the game
int snakes_ladders(int i)
{
    if(i==16)i=79;
    if(i==22)i=33;
    if(i==44)i=72;
    if(i==87)i=14;
    if(i==94)i=38;
    return i;

}
struct game     //structure to save players data
    {
       int index;
       char name;
       int increment;
    };

// Ground(number base with current player location) for the game
void ground(struct game *gmpr, int players)
{
    printf("\n\n\n\n\n");
    printf("\t");
    for(int i=100; i>=1; i--)
    {
        printf("\t|%d",i);
        for(int j=0; j<players; j++)
        {if(i == gmpr->index)
        {
            printf("<-%c-",gmpr->name);
            gmpr++;
        }}
        if(i-1==16) printf(" L-79");
        else if(i-1==22) printf(" L-33");
        else if(i-1==44) printf(" L-72");
        else if(i-1==87) printf(" S-14");
        else if(i-1==94) printf(" S-38");
        else printf("\t");


        if(i%10==1 && i!=100)
        {
            printf("\n\n\n");
        }
        if(i%10==1)
        {
            printf("\t");
        }
    }
}

//main function
void main()
{
    int players;    //Number of players
    printf("Number of players : ");
    scanf("%d",&players);

    struct game gmpr[players];

    printf("For player name use small single alphabet only\r");
    sleep(1);

    for(int i=0; i<players; i++)
    {
        printf("player %d name : \t\t\t\t\t",i+1);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        printf("\b\b\b\b\b\b\b\b");
        scanf("%s",&gmpr[i].name);
        gmpr[i].index = 0;
        gmpr[i].increment = 0;

        if(gmpr[i].name<'a' || gmpr[i].name>'z')    //restricting players to select only alphabets
        {
            printf("Enter small Alphabets only\r");
            sleep(1);
            i-=1;
            continue;
        }

        for(int j=0; j<i; j++)  //Insisting players to select a new name
        {
            if(gmpr[i].name == gmpr[j].name)
            {
                printf("This Name is already taken, enter new name \r");
                sleep(1);
                i-=1;
            }
        }
    }

    system("cls");  // Loading the game environment
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t.....LOADING.....");
    sleep(1);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tLET'S BEGIN THE GAME : ");
    //starting the game
    comehere:
    for(int i=0; i<players; i++)
    {
        if(gmpr[i].index == 0)
        {
            system("cls");
            ground(gmpr, players);
            printf("\nMr.%c: ",gmpr[i].name);
            system("timeout -1");
            printf("\t\t\tMR.%c ROLLING THE DICE",gmpr[i].name);
            gmpr[i].increment = rand() % 6+1;
            if(gmpr[i].increment == 1)
            {
                printf("\t\t\t AND GOT ENTERED THE GAME ");
                sleep(1);
                gmpr[i].index += gmpr[i].increment;
            }
            else
            {
                printf("\t\t\t BETTER LUCK NEXT TIME ");
                sleep(1);
            }
        }
        else
        {
            system("cls");
            ground(gmpr, players);
            printf("Mr.%c: ",gmpr[i].name);
            system("timeout -1");
            printf("\t\t\tMR.%c ROLLING THE DICE",gmpr[i].name);
            gmpr[i].increment = rand() % 6+1;
            printf("\t\t\tYou Got %d ",gmpr[i].increment);
            sleep(1);
            gmpr[i].index =gmpr[i].index + gmpr[i].increment;
            gmpr[i].index = snakes_ladders(gmpr[i].index);
            if(gmpr[i].index ==100)
            goto end;
            if(gmpr[i].index >100)
            gmpr[i].index =gmpr[i].index - gmpr[i].increment;
        }
    }
    for(int i=0; i<players ; i++)
    {
        if(gmpr[i].index==100)
        {
            end:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t.....LOADING.....");
            sleep(1);
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t");
            printf("Mr.%c WINNER WINNER SNAKE DINNER\n\n\n\n\n\n ",gmpr[i].name);
            system("timeout -1");
            break;
        }
        else
            goto comehere;
    }
}
