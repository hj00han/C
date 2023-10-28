/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Hyunjoo Han
Student ID#: 132749227
Email      : hhan39@myseneca.ca
Section    : NEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int anothershopping;

    do{
        int apples = -1, oranges = -1, pears = -1, tomatoes = -1, cabbages = -1;
        int applePick, orangePick, pearPick, tomatoPick, cabbagePick;
        printf("Grocery Shopping\n");
        printf("================\n");

        while (apples < 0)
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");

            }
        }
        printf("\n");

        while (oranges < 0)
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");

            }
        }
        printf("\n");

        while (pears < 0)
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);

            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");

            }
        }

        printf("\n");
        while (tomatoes < 0)
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);

            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");

            }
        }

        printf("\n");
        while (cabbages < 0)
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);

            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");

            }
        }

        printf("\n");
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        
        if (apples > 0)
        {
            printf("\n");
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &applePick);

                if (applePick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (applePick > apples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
                }
                else if (applePick < apples || applePick < apples - applePick)
                {
                    printf("Looks like we still need some APPLES...\n");
                    apples -= applePick;
                }
                else if (applePick < apples && applePick > apples - applePick)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples - applePick);
                }
                else if (applePick == apples)
                {
                    printf("Great, that's the apples done!\n");
                    apples -= applePick;
                }
            } while (apples > 0);
        }

        if (oranges > 0)
        {
            printf("\n");
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &orangePick);

                if (orangePick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (orangePick > oranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
                }
                else if (orangePick < oranges || orangePick < oranges - orangePick)
                {
                    printf("Looks like we still need some ORANGES...\n");
                    oranges -= orangePick;
                }
                else if (orangePick < oranges && orangePick > oranges - orangePick)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges - orangePick);
                }
                else if (orangePick == oranges)
                {
                    printf("Great, that's the oranges done!\n");
                    oranges -= orangePick;
                }
            } while (oranges > 0);
        }

        if (pears > 0)
        {
            printf("\n");
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pearPick);

                if (pearPick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pearPick > pears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                }
                else if (pearPick < pears || pearPick < pears - pearPick)
                {
                    printf("Looks like we still need some PEARS...\n");
                    pears -= pearPick;
                }
                else if (pearPick < pears && pearPick > pears - pearPick)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears - pearPick);
                }
                else if (pearPick == pears)
                {
                    printf("Great, that's the pears done!\n");
                    pears -= pearPick;
                }
            } while (pears > 0);
        }

        if (tomatoes > 0)
        {
            printf("\n");
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &tomatoPick);

                if (tomatoPick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (tomatoPick > tomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                }
                else if (tomatoPick < tomatoes || tomatoPick < tomatoes - tomatoPick)
                {
                    printf("Looks like we still need some TOMATOES...\n");
                    tomatoes -= tomatoPick;
                }
                else if (tomatoPick < tomatoes && tomatoPick > tomatoes - tomatoPick)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes - tomatoPick);
                }
                else if (tomatoPick == tomatoes)
                {
                    printf("Great, that's the tomatoes done!\n");
                    tomatoes -= tomatoPick;
                }
            } while (tomatoes > 0);
        }

        if (cabbages > 0)
        {
            printf("\n");
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &cabbagePick);

                if (cabbagePick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (cabbagePick > cabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                }
                else if (cabbagePick < cabbages || cabbagePick < cabbages - cabbagePick)
                {
                    printf("Looks like we still need some CABBAGES...\n");
                    cabbages -= cabbagePick;
                }
                else if (cabbagePick < cabbages && cabbagePick > cabbages - cabbagePick)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages - cabbagePick);
                }
                else if (cabbagePick == cabbages)
                {
                    printf("Great, that's the cabbages done!\n");
                    cabbages -= cabbagePick;
                }
            } while (cabbages > 0);
        }

        printf("\nAll the items are picked!\n\n");

        printf("Do another shopping? (0=NO): ");
        scanf("%d", &anothershopping);
        printf("\n");

    }while (anothershopping != 0);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}