/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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

int main(void)
{
    printf("Set Shirt Prices\n");
    printf("================\n");
    
    double priceS;
    double priceM;
    double priceL;
    int pattybuys;
    double totalSub;
    double tax;
    double totalFinal;
    const double TAX = 0.13;
    const char patSize = 'S';

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &priceS);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &priceM);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &priceL);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", priceS);
    printf("MEDIUM : $%.2lf\n", priceM);
    printf("LARGE  : $%.2lf\n", priceL);

    printf("\nPatty's shirt size is '%c'\n", patSize);
  
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &pattybuys);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", pattybuys);

    totalSub = pattybuys * priceS;
    tax = ((totalSub * TAX + 0.0016) * 100) / 100;
    totalFinal = totalSub + tax;

    printf("Sub-total: $%.4lf\n", totalSub); 
    printf("Taxes    : $ %.4lf\n", tax);
    printf("Total    : $%.4lf\n", totalFinal);

    return 0;
}