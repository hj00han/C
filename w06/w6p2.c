/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : HYUNJOO HAN
Student ID#: 132749227
Email      : hhan39@myseneca.ca
Section    : NEE
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_WISH 10

#include <stdio.h>

int main(void)
{
    double income = 0, finalCost = 0, prioCost=0, forecast;
    int wishItems = 0, i, forecastOption, prioFilter, year, month;
    const double min_cost = 100.00;

    double cost[MAX_WISH] = { 0 };
    int importance[MAX_WISH] = { 0 };
    char finance[MAX_WISH];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

    while (income < 500 || income>400000)
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);

        if (income < 500)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        else if (income > 400000)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
    }
    printf("\n");

    while (wishItems <= 0 || wishItems > MAX_WISH)
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &wishItems);

        if (wishItems <= 0 || wishItems > MAX_WISH)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
    }
    printf("\n");

    for (i = 0; i < wishItems; i++)
    {
        printf("Item-%d Details:\n", i + 1);

        while (cost[i] < min_cost)
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] < min_cost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        }

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &importance[i]);

            if (importance[i] < 1 || importance[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (importance[i] < 1 || importance[i] > 3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);

            if (finance[i] != 'y' && finance[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }

        } while (finance[i] != 'y' && finance[i] != 'n');
        printf("\n");
    }



    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < wishItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, importance[i], finance[i], cost[i]);

        finalCost += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", finalCost);
    
    do
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &forecastOption);
        printf("\n");

        if (forecastOption < 0 || forecastOption > 2)
        {
            printf("ERROR: Invalid menu selection.\n\n");
        }
        else if (forecastOption == 1) // 1. All the Item(no filter)
        {
            forecast = finalCost / income;
            if (forecast - (int)forecast > 0)
            {
                year = ((int)forecast + 1) / 12;
                month = ((int)forecast + 1) % 12;

            }
            else
            {
                year = (int)forecast / 12;
                month = (int)forecast % 12;
            }

            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", finalCost);
            printf("Forecast: %d years, %d months\n", year, month);
            
            for (i = 0; i<wishItems; i++)
            {
                if (finance[i] == 'y')
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    i = wishItems; // so that if there is any item with finalcial option, exit the loop
                }

            }
            
            printf("====================================================\n\n");
        }
        else if (forecastOption == 2) // 2. By priority
        {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &prioFilter);
            printf("\n");
            
            for (i = 0; i < wishItems; i++)
            {
                if (importance[i] == prioFilter)
                {
                    prioCost += cost[i];
                }
            }

            forecast = prioCost / income;
            if (forecast - (int)forecast > 0)
            {
                year = ((int)forecast + 1) / 12;
                month = ((int)forecast + 1) % 12;

            }
            else
            {
                year = (int)forecast / 12;
                month = (int)forecast % 12;
            }

            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", prioFilter);
            printf("Amount:   $%1.2lf\n", prioCost);
            printf("Forecast: %d years, %d months\n", year, month);

            for (i = 0; i < wishItems; i++)
            {
                if (finance[i] == 'y' && importance[i] == prioFilter) 
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    i = wishItems; // so that if there is a item with finalcial option, exit the loop
                }

            }

            printf("====================================================\n\n");

            prioCost = 0; // This is to reset the filtered price
        }

    } while (forecastOption != 0);

    printf("Best of luck in all your future endeavours!\n");
    
    return 0;
}