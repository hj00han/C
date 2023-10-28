/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    const double GRAMS_IN_LBS = 453.5924;
    char coffee1Type, coffee2Type, coffee3Type, bestWcream1, bestWcream2, bestWcream3;
    int bagWeight1, bagWeight2, bagWeight3;
    char preferCoffee_strength, preferCoffee_cream; 
    int typicalServingPD;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee1Type);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestWcream1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee2Type);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestWcream2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee3Type);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestWcream3);

    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee1Type == 'l' || coffee1Type == 'L', coffee1Type == 'm' || coffee1Type == 'M', coffee1Type == 'r' || coffee1Type == 'R', 
        bagWeight1, bagWeight1 / GRAMS_IN_LBS, bestWcream1 == 'y' || bestWcream1 == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee2Type == 'l' || coffee2Type == 'L', coffee2Type == 'm' || coffee2Type == 'M', coffee2Type == 'r' || coffee2Type == 'R', 
        bagWeight2, bagWeight2 / GRAMS_IN_LBS, bestWcream2 == 'y' || bestWcream2 == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", coffee3Type == 'l' || coffee2Type == 'L' , coffee3Type == 'm' || coffee3Type == 'M', coffee3Type == 'r' || coffee3Type == 'R', 
        bagWeight3, bagWeight3 / GRAMS_IN_LBS, bestWcream3 == 'y' || bestWcream3 == 'Y');
    
    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &preferCoffee_strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &preferCoffee_cream);
    printf("Typical number of daily servings: ");
    scanf("%d", &typicalServingPD);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (((preferCoffee_strength == 'L' || preferCoffee_strength == 'l') && (coffee1Type == 'L' || coffee1Type == 'l')) || ((preferCoffee_strength == 'M' || preferCoffee_strength == 'm') && (coffee1Type == 'M' || coffee1Type == 'm'))) || ((preferCoffee_strength == 'R' || preferCoffee_strength == 'r') && (coffee1Type == 'R' || coffee1Type == 'r')),
        (typicalServingPD < 5 && bagWeight1 == 250) || (((4 < typicalServingPD) && (typicalServingPD < 10) && bagWeight1 == 500)) || (typicalServingPD >= 10 && bagWeight1 == 1000),
        (preferCoffee_cream == 'y' || preferCoffee_cream == 'Y') == (bestWcream1 == 'y' || bestWcream1 == 'Y'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (((preferCoffee_strength == 'L' || preferCoffee_strength == 'l') && (coffee2Type == 'L' || coffee2Type == 'l')) || ((preferCoffee_strength == 'M' || preferCoffee_strength == 'm') && (coffee2Type == 'M' || coffee2Type == 'm'))) || ((preferCoffee_strength == 'R' || preferCoffee_strength == 'r') && (coffee2Type == 'R' || coffee2Type == 'r')),
        (typicalServingPD < 5 && bagWeight2 == 250) || (((4 < typicalServingPD) && (typicalServingPD < 10) && bagWeight2 == 500)) || (typicalServingPD >= 10 && bagWeight2 == 1000),
        (preferCoffee_cream == 'y' || preferCoffee_cream == 'Y') == (bestWcream2 == 'y' || bestWcream2 == 'Y'));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", (((preferCoffee_strength == 'L' || preferCoffee_strength == 'l') && (coffee3Type == 'L' || coffee3Type == 'l')) || ((preferCoffee_strength == 'M' || preferCoffee_strength == 'm') && (coffee3Type == 'M' || coffee3Type == 'm'))) || ((preferCoffee_strength == 'R' || preferCoffee_strength == 'r') && (coffee3Type == 'R' || coffee3Type == 'r')),
        (typicalServingPD < 5 && bagWeight3 == 250) || (((4 < typicalServingPD) && (typicalServingPD < 10) && bagWeight3 == 500)) || (typicalServingPD >= 10 && bagWeight3 == 1000),
        (preferCoffee_cream == 'y' || preferCoffee_cream == 'Y') == (bestWcream3 == 'y' || bestWcream3 == 'Y'));

    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &preferCoffee_strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &preferCoffee_cream);
    printf("Typical number of daily servings: ");
    scanf("%d", &typicalServingPD);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (((preferCoffee_strength == 'L' || preferCoffee_strength == 'l') && (coffee1Type == 'L' || coffee1Type == 'l')) || ((preferCoffee_strength == 'M' || preferCoffee_strength == 'm') && (coffee1Type == 'M' || coffee1Type == 'm'))) || ((preferCoffee_strength == 'R' || preferCoffee_strength == 'r') && (coffee1Type == 'R' || coffee1Type == 'r')),
        (typicalServingPD < 5 && bagWeight1 == 250) || (((4 < typicalServingPD) && (typicalServingPD < 10) && bagWeight1 == 500)) || (typicalServingPD >= 10 && bagWeight1 == 1000),
        (preferCoffee_cream == 'y' || preferCoffee_cream == 'Y') == (bestWcream1 == 'y' || bestWcream1 == 'Y'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (((preferCoffee_strength == 'L' || preferCoffee_strength == 'l') && (coffee2Type == 'L' || coffee2Type == 'l')) || ((preferCoffee_strength == 'M' || preferCoffee_strength == 'm') && (coffee2Type == 'M' || coffee2Type == 'm'))) || ((preferCoffee_strength == 'R' || preferCoffee_strength == 'r') && (coffee2Type == 'R' || coffee2Type == 'r')),
        (typicalServingPD < 5 && bagWeight2 == 250) || (((4 < typicalServingPD) && (typicalServingPD < 10) && bagWeight2 == 500)) || (typicalServingPD >= 10 && bagWeight2 == 1000),
        (preferCoffee_cream == 'y' || preferCoffee_cream == 'Y') == (bestWcream2 == 'y' || bestWcream2 == 'Y'));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", (((preferCoffee_strength == 'L' || preferCoffee_strength == 'l') && (coffee3Type == 'L' || coffee3Type == 'l')) || ((preferCoffee_strength == 'M' || preferCoffee_strength == 'm') && (coffee3Type == 'M' || coffee3Type == 'm'))) || ((preferCoffee_strength == 'R' || preferCoffee_strength == 'r') && (coffee3Type == 'R' || coffee3Type == 'r')),
        (typicalServingPD < 5 && bagWeight3 == 250) || (((4 < typicalServingPD) && (typicalServingPD < 10) && bagWeight3 == 500)) || (typicalServingPD >= 10 && bagWeight3 == 1000),
        (preferCoffee_cream == 'y' || preferCoffee_cream == 'Y') == (bestWcream3 == 'y' || bestWcream3 == 'Y'));
    printf("Hope you found a product that suits your likes!\n");


    return 0;
}