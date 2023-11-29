/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    double priceS, priceM, priceL;
    int pattybuys, salbuys, tombuys;
    double totalSubPatty, totalSubSal, totalSubTom, totalSubAll, taxPatty, taxSal, taxTom, taxAll;
    double totalFinalPatty, totalFinalSal, totalFinalTom, totalFinalAll;
    
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';


    printf("Set Shirt Prices\n");
    printf("================\n");

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

    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tombuys);

    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salbuys);
    
    totalSubPatty = pattybuys * priceS;
    taxPatty = ((int)((totalSubPatty * TAX+0.005)*100))/(double)100;
    totalFinalPatty = totalSubPatty + taxPatty;
    totalSubTom = tombuys * priceL;
    taxTom = (totalSubTom * TAX + 0.0017) * 100 / 100;
    taxTom = ((int)((totalSubTom * TAX + 0.005) * 100)) / (double)100;
    totalFinalTom = totalSubTom + taxTom;
    totalSubSal = salbuys * priceM;
    taxSal = ((int)((totalSubSal * TAX + 0.005) * 100)) / (double)100;
    totalFinalSal = totalSubSal + taxSal;
    totalSubAll = totalSubPatty + totalSubSal + totalSubTom;
    taxAll = taxPatty + taxSal + taxTom;
    totalFinalAll = totalFinalPatty + totalFinalSal + totalFinalTom;

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, priceS, pattybuys, totalSubPatty, taxPatty, totalFinalPatty);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, priceM, salbuys, totalSubSal, taxSal, totalFinalSal);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, priceL, tombuys, totalSubTom, taxTom, totalFinalTom);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                        %9.4lf %9.4lf %9.4lf\n\n", totalSubAll, taxAll, totalFinalAll);
   
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");


    int  toony1, loony1, quarter1, dime1, nickel1, penny1;
    double afterToony1, afterLoony1, afterQuarter1, afterDime1, afterNickel1, afterPenny1, avgSub;
   

    toony1 = totalSubAll / 2;
    afterToony1 = ((int)(totalSubAll * 100) % 200) / (double)100;
    loony1 = afterToony1 / 1;
    afterLoony1 = ((int)(afterToony1 * 100) % 100) / (double)100;
    quarter1 = afterLoony1 / 0.25;
    afterQuarter1 = ((int)(afterLoony1 * 100) % 25) / (double)100;
    dime1 = afterQuarter1 / 0.1;
    afterDime1 = ((int)(afterQuarter1 * 100) % 10) / (double)100;
    nickel1 = afterDime1 / 0.05;
    afterNickel1 = ((int)(afterDime1 * 100) % 5) / (double)100;
    penny1 = afterNickel1 / 0.01;
    afterPenny1 = ((int)(afterNickel1 * 100) % 1) / (double)100;
    avgSub = totalSubAll / (pattybuys + salbuys + tombuys);
   
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", totalSubAll);
    printf("Toonies  %3d %9.4lf\n", toony1, afterToony1);
    printf("Loonies  %3d %9.4lf\n", loony1, afterLoony1);
    printf("Quarters %3d %9.4lf\n", quarter1, afterQuarter1);
    printf("Dimes    %3d %9.4lf\n", dime1, afterDime1);
    printf("Nickels  %3d %9.4lf\n", nickel1, afterNickel1);
    printf("Pennies  %3d %9.4lf\n", penny1, afterPenny1);

    printf("\nAverage cost/shirt: $%.4lf\n\n", avgSub);

    int toony2, loony2, quarter2, dime2, nickel2, penny2;
    double afterToony2, afterLoony2, afterQuarter2, afterDime2, afterNickel2, afterPenny2, avgFinal;

    toony2 = totalFinalAll / 2;
    afterToony2 = ((int)(totalFinalAll * 100) % 200) / (double)100;
    loony2 = afterToony2 / 1;
    afterLoony2 = ((int)(afterToony2 * 100) % 100) / (double)100;
    quarter2 = afterLoony2/0.25;
    afterQuarter2 = ((int)((afterLoony2+0.01) * 100) % 25) / (double)100;
    // line121: meant to be ' afterQuater2 = ((int)(afterLoony2*100) % 25 / (double)100 ; '
    // but when it's excuted, it print 0.06 instead of 0.007.
    // even if i put ((int)(0.57*100)) % 25 / (double)100, it's the same. 

    dime2 = afterQuarter2 / 0.1;
    afterDime2 = ((int)(afterQuarter2 * 100) % 10) / (double)100;
    nickel2 = afterDime2 / 0.05;
    afterNickel2 = ((int)(afterDime2 * 100) % 5) / (double)100;
    penny2 = afterNickel2 / 0.01;
    afterPenny2 = ((int)(afterNickel2 * 100) % 1) / (double)100;
    avgFinal = totalFinalAll / (pattybuys + salbuys + tombuys);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", totalFinalAll);
    printf("Toonies  %3d %9.4lf\n", toony2, afterToony2);
    printf("Loonies  %3d %9.4lf\n", loony2, afterLoony2);
    printf("Quarters %3d %9.4lf\n", quarter2, afterQuarter2);
    printf("Dimes    %3d %9.4lf\n", dime2, afterDime2);
    printf("Nickels  %3d %9.4lf\n", nickel2, afterNickel2);
    printf("Pennies  %3d %9.4lf\n", penny2, afterPenny2);

    printf("\nAverage cost/shirt: $%.4lf\n", avgFinal);
   
    return 0;
}