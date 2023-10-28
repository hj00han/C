/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year, month, day = 1;
    double morningRate, eveningRate, morningRateTotal=0, eveningRateTotal=0;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if ((year<MIN_YEAR || year>MAX_YEAR) && (month<JAN || month>DEC))
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        else if (year<MIN_YEAR || year>MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        else if (month<JAN || month>DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        else if ((year >= MIN_YEAR || year <= MAX_YEAR) && (month >= JAN || month <= DEC))
        {
            printf("\n");
            printf("*** Log date set! ***\n\n");
            
            while (day <= LOG_DAYS)
            {
                printf("%d-", year);

                switch (month)
                {
                case 1:
                    printf("JAN-");
                    break;
                case 2:
                    printf("FEB-");
                    break;
                case 3:
                    printf("MAR-");
                    break;
                case 4:
                    printf("APR-");
                    break;
                case 5:
                    printf("MAY-");
                    break;
                case 6:
                    printf("JUN-");
                    break;
                case 7:
                    printf("JUL-");
                    break;
                case 8:
                    printf("AUG-");
                    break;
                case 9:
                    printf("SEP-");
                    break;
                case 10:
                    printf("OCT-");
                    break;
                case 11:
                    printf("NOV-");
                    break;
                case 12:
                    printf("DEC-");
                    break;
                }

                if (day < 10)
                {
                    printf("0%d\n", day);
                }
                else if (day >= 10)
                {
                    printf("%d\n", day);
                }
                
                morningRate = -1;
                eveningRate = -1;

                while (morningRate < 0 || morningRate>5)
                {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morningRate);

                    if (morningRate < 0 || morningRate>5)
                    {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                }

                while (eveningRate < 0 || eveningRate>5)
                {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveningRate);

                    if (eveningRate < 0 || eveningRate>5)
                    {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                }
                printf("\n");

                morningRateTotal += morningRate;
                eveningRateTotal += eveningRate;

                day++;
            }

            printf("Summary\n");
            printf("=======\n");
            printf("Morning total rating: %.3lf\n", morningRateTotal);
            printf("Evening total rating:  %.3lf\n", eveningRateTotal);
            printf("----------------------------\n");
            printf("Overall total rating: %.3lf\n\n", morningRateTotal + eveningRateTotal);
            printf("Average morning rating:  %.1lf\n", morningRateTotal / LOG_DAYS);
            printf("Average evening rating:  %.1lf\n", eveningRateTotal / LOG_DAYS);
            printf("----------------------------\n");
            printf("Average overall rating:  %.1lf\n", (morningRateTotal + eveningRateTotal) / (LOG_DAYS * 2));
        }
    } while ((year<MIN_YEAR || year>MAX_YEAR) || (month<JAN || month>DEC));

    return 0;
}