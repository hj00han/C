#pragma once

/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Hyunjoo Han
Student ID#: 132749227
Email      : hhan39@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// Clear the standard input buffer 
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//1.
int inputInt(void);

//2.
int inputIntPositive(void);

//3.
int inputIntRange(int, int);

//4.
char inputCharOption(char charOption[]);

//5.
void inputCString(char* cString, int, int);

//6.
void displayFormattedPhone(const char* display);
