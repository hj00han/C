/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>
#include "core.h"


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//1.
int inputInt(void)
{
    int inputInt;
    char inputChar;
    do
    {
        scanf("%d%c", &inputInt, &inputChar);
        if (inputChar != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (inputChar != '\n');

    return inputInt;
}

//2.
int inputIntPositive(void)
{
    int input;
    char null = '\n';
    do
    {
        scanf("%d%c", &input, &null);
        if (null != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (input <= 0)
        {
            printf("ERROR! Value must be > 0: ");

        }
    } while (null != '\n' || input <= 0);

    return input;
}

//3.   
int inputIntRange(int lowerBound, int upperBound)
{
    int intVal;
    char null;
    do
    {
        scanf("%d%c", &intVal, &null);
        if (null != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (intVal<lowerBound || intVal>upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while (null != '\n' || intVal < lowerBound || intVal > upperBound);

    return intVal;
}

//4.
char inputCharOption(char charOption[])
{
    char character;
    int i, j = 0;
    do
    {
        scanf(" %c", &character);
        for (i = 0; charOption[i] != '\0'; i++)
        {
            if (character == charOption[i])
            {
                j++;
            }
        }

        if (j == 0)
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", charOption);
        }
    } while (j == 0);
    return character;
}

//5.
void inputCString(char* cStr, int min, int max)
{
    int length = 0, i = 1;
    char string[50];

    do
    {
        scanf(" %[^\n]", string);
        //upgrade with string library function(define the lenth of string)
        length = strlen(string);
        //for (i = 0; string[i] != '\0'; i++)
        //{
          //  length++;
        //}
        if (length >= min && length <= max)
        {
            i = 0;
            strcpy(cStr, string);// upgrade with string library function
            //for (i = 0; i < length; i++)
            //{
              //  cStr[i] = string[i];
            //}
        }
        else
        {
            if (min == max)
            {
                printf("Invalid 10-digit number! Number: ");
            }
            else if (length > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
        }
    } while (i);

}

//6.
void displayFormattedPhone(const char* numPhone)
{
    int i = 0, length = 0, digit = 0;
    if (numPhone == NULL)
    {
        printf("(___)___-____");
    }
    else
    {
        length = strlen(numPhone); //upgrate with string library function
        for (i = 0; numPhone[i] != '\0'; i++)
        {
            if (numPhone[i] >= '0' && numPhone[i] <= '9')
            {
                digit++;
            }
            // length++;
        }

        if (length == 10 && digit == 10)
        {
            printf("(");
            for (i = 0; i < 3; i++)
            {
                printf("%c", numPhone[i]);
            }
            printf(")");
            for (i = 3; i < 10; i++)
            {
                printf("%c", numPhone[i]);
                if (i == 5)
                {
                    printf("-");
                }
            }
        }
        else { printf("(___)___-____"); }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////
