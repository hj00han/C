/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Hyunjoo Han
Student ID#: 132749227
Email      : hhan39@myseneca.ca
Section    : NEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_LENGTH 70
#define MAX_BOMBS 35
#define MAX_TREASURES 35

struct PlayerInfo
{
    int lives;
    char name;
    int treasures;
    int history[MAX_LENGTH];

};

struct GameInfo
{
    int moves;
    int pathLength;
    int bombs[MAX_BOMBS];
    int treasures[MAX_TREASURES];
};


int main(void)
{
    int i, j; //Variables for Iterations
    int ruller, nextMove;
    int been[MAX_LENGTH]; //array for ruller(if you have been to the move)

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    //declaration object of 'player' with 'struct PlayerInfo'
    struct PlayerInfo player;

    //Getting input from the user and store in the sturct PlayerInfo player
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.name);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < 1 || player.lives>10)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.lives < 1 || player.lives > 10);

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    //declaration object of 'game' with 'struct GameInfo'
    struct GameInfo game;

    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
        if (game.pathLength % 5 != 0 || game.pathLength < 10 || game.pathLength>MAX_LENGTH)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (game.pathLength % 5 != 0 || game.pathLength < 10 || game.pathLength>MAX_LENGTH);

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        if (game.moves < 3 || game.moves>15)
        {
            printf("    Value must be between 3 and 15\n");
        }
    } while (game.moves < 3 || game.moves>15);

    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    
    //Iteration of user input for array 
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    
    //Iteration of user input for array
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasures[i], &game.treasures[i + 1], &game.treasures[i + 2], &game.treasures[i + 3], &game.treasures[i + 4]);
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.name);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    
    //Iteration for printing values of array
    for (j = 0; j < game.pathLength; j++)
    {
        printf("%d", game.bombs[j]);
    }
    printf("\n");

    printf("   Treasure   : ");

    //Iteration for printing values of array
    for (j = 0; j < game.pathLength; j++)
    {
        printf("%d", game.treasures[j]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    //printing ruller depending on game.pathLength below
    printf("  ");
    //first line of the ruller(player position)
    for (i = 0; i < game.pathLength; i++)
    {
        printf("-");
    }
    printf("\n");

    printf("  ");
    //second line of the ruller
    for (i = 1; i < game.pathLength + 1; i++)
    {
        if (i % 10 != 0)
        {
            printf("|");
        }
        else if (i % 10 == 0)
        {
            j = i / 10;
            printf("%d", j);
        }
    }
    printf("\n");

    printf("  ");
    //third line of the ruller
    for (j = 0; j < game.pathLength; j++)
    {
        ruller = (j + 1) % 10;
        printf("%d", ruller);
    }
    printf("\n");

    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasures = 0 , game.moves);
    printf("+---------------------------------------------------+\n");

    while (player.lives != 0 && game.moves != 0)
    {
        do
        {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &nextMove);

            if (nextMove < 1 || nextMove>game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }
        } while (nextMove < 1 || nextMove>game.pathLength);
        printf("\n");

        if (been[nextMove - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n");
        }
        else
        {
            if (game.bombs[nextMove - 1] == 0 && game.treasures[nextMove - 1] == 0)
            {
                printf("===============> [.] ...Nothing found here... [.]\n");
            }
            else if (game.bombs[nextMove - 1] == 1 && game.treasures[nextMove - 1] == 0)
            {
                printf("===============> [!] !!! BOOOOOM !!! [!]\n");
                player.lives -= 1;
            }
            else if (game.bombs[nextMove - 1] == 0 && game.treasures[nextMove - 1] == 1)
            {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                player.treasures += 1;
            }
            else if (game.bombs[nextMove - 1] == 1 && game.treasures[nextMove - 1] == 1)
            {
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                player.lives -= 1;
                player.treasures += 1;
            }
            been[nextMove - 1] = 1;
            player.history[nextMove - 1] = 1;
            game.moves -= 1;
        }
        printf("\n");

        if (player.lives < 1)
        {
            printf("No more LIVES remaining!\n\n");
        }

        //first line of the ruller
        printf("  ");
        for (i = 0; i < nextMove - 1; i++)
        {
            printf(" ");
        }
        printf("%c\n", player.name);
           
        
        //second line of the ruller
        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            if (i == 15)
            {
                printf("-");
            }
            else if (player.history[i] != 1)
            {
                printf("-");
            }
            else if (player.history[i] == 1)
            {
                if (game.bombs[i] != 1 && game.treasures[i] != 1)
                {
                    printf(".");
                }
                else if (game.bombs[i] == 1 && game.treasures[i] != 1)
                {
                    printf("!");
                }
                else if (game.bombs[i] != 1 && game.treasures[i] == 1)
                {
                    printf("$");
                }
                else if (game.bombs[i] == 1 && game.treasures[i] == 1)
                {
                    printf("&");
                }
            }
        }
        printf("\n");

        //third line of the ruller
        printf("  ");
        for (i = 1; i < game.pathLength + 1; i++)
        {
            if (i % 10 != 0)
            {
                printf("|");
            }
            else if (i % 10 == 0)
            {
                j = i / 10;
                printf("%d", j);
            }
        }
        printf("\n");

        //fourth line of the ruller
        printf("  ");
        for (j = 0; j < game.pathLength; j++)
        {
            ruller = (j + 1) % 10;
            printf("%d", ruller);
        }
        printf("\n");
  
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasures, game.moves);
        printf("+---------------------------------------------------+\n");
    }
    
    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");

    return 0;
}