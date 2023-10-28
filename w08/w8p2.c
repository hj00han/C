/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* intValue_P)
{
	int intValue;

	do
	{
		scanf("%d", &intValue);
		if (intValue == 0 || intValue < 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (intValue == 0 || intValue < 0);
	  //keep prompting for user input until intValue(user input) is positive number
	if (intValue_P != NULL)
	{
		*intValue_P = intValue;
		//intValue_P is the pointer for the data 'intValue'
	}
	return intValue; //returning the positive integer value
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* doubleValue_P)
{
	double doubleValue;

	do
	{
		scanf("%lf", &doubleValue);
		if (doubleValue == 0 || doubleValue < 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (doubleValue == 0 || doubleValue < 0);
	//keep prompting for user input until doubleValue(user input) is positive number

	if (doubleValue_P != NULL)
	{
		*doubleValue_P = doubleValue;
		//intValue_P is the pointer for the data 'doubleValue'
	}
	return doubleValue; //returning the positive double value
}

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int sequenceNum)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n\n", SUGGESTED_SERVING_G);
}

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int sequenceNum)
{
	struct CatFoodInfo catProduct;

	printf("Cat Food Product #%d\n", sequenceNum + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	do
	{
		scanf("%d", &catProduct.sku);
		if (catProduct.sku == 0 || catProduct.sku < 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (catProduct.sku == 0 || catProduct.sku < 0);

	printf("PRICE         : $");
	do
	{
		scanf("%lf", &catProduct.price);
		if (catProduct.price == 0 || catProduct.price < 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (catProduct.price == 0 || catProduct.price < 0);

	printf("WEIGHT (LBS)  : ");
	do
	{
		scanf("%lf", &catProduct.weight);
		if (catProduct.weight == 0 || catProduct.weight < 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (catProduct.weight == 0 || catProduct.weight < 0);

	printf("CALORIES/SERV.: ");
	do
	{
		scanf("%d", &catProduct.calories);
		if (catProduct.calories == 0 || catProduct.calories < 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (catProduct.calories == 0 || catProduct.calories < 0);
	printf("\n");

	return catProduct; // Returning the struct
}

// 5. Display the formatted table header

void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int sku, const double* price, const double* weight, const int calorie)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calorie);
}



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(const double* poundKg, double* resultLbsKg_P)
{
	double resultLbsKg;
	resultLbsKg = *poundKg / POUNDS_TO_KG; // calculating conversion Lbs->Kg
	if (resultLbsKg_P != NULL)
	{
		*resultLbsKg_P = resultLbsKg; //assigning result to the pointer
	}
	return resultLbsKg; //returning double floating-point value of conversion result
}

// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(const double* poundG, int* resultLbsG_P)
{
	int resultLbsG;
	resultLbsG = *poundG / POUNDS_TO_KG * 1000;
	/*double lbsKg = 0.0;
	resultLbsG = (int)(convertLbsKg(&pound, &lbsKg) * 1000);
	convert Lbs -> Kg first with function 'convertLbsKg' and convert that to G*/
	if (resultLbsG_P != NULL)
	{
		*resultLbsG_P = resultLbsG; //assigning result to the pointer
	}
	return resultLbsG; //returning integer value of conversion result
}

// 10. convert lbs: kg and g

void convertLbs(const double* pound, double* resultKg_P, int* resultG_P)
{
	double resultKg;
	int resultG;

	resultKg = *pound / POUNDS_TO_KG; 
	//calculating conversion Lbs->Kg with a argument and macro which is the conversion fator
	if (resultKg_P != NULL)
	{
		*resultKg_P = resultKg; //assigning result to the pointer
	}

	resultG = (int)(*pound / POUNDS_TO_KG * 1000); //calulating conversion Lbs->G
	if (resultG_P != NULL)
	{
		*resultG_P = resultG; //assigning result to the pointer
	}
}

// 11. calculate: servings based on gPerServ

double calculateServings(const int servingSizeG, const int totalG, double* servingsInAbag_P)
{
	double servingsInAbag;
	servingsInAbag = (double)totalG / servingSizeG; 
	//calculating total serving of the product with argument provided
	if (servingsInAbag_P != NULL)
	{
		*servingsInAbag_P = servingsInAbag; //assigning result to the pointer
	}
	return servingsInAbag;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double* productPrice, const double* totalServing, double* costPerServing_P)
{
	double costPerServing;
	costPerServing = *productPrice / *totalServing;
	// calculating cost per serving with argument provided
	if (costPerServing_P != NULL)
	{
		*costPerServing_P = costPerServing; 
		//assigning result to the pointer
	}
	return costPerServing; //returning double floating-point value of calculation result
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* calories, double* costPerCalorie_P)
{
	double costPerCalorie;
	costPerCalorie = *productPrice / *calories; 
	//calculating cost per calorie with argument provided
	if (costPerCalorie_P != NULL)
	{
		*costPerCalorie_P = costPerCalorie;
		//assigning result to the pointer
	}
	return costPerCalorie;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo catProduct)
{
	double totalCalories = 0;
	struct ReportData data;

	//assinging values to 'data' from 'catProduct'(matching)
	data.skuData = catProduct.sku;
	data.priceData = catProduct.price;
	data.caloriesData = catProduct.calories;
	data.weight_pounds = catProduct.weight;
	//assigning values to 'data' by using fuction
	data.weight_kg = convertLbsKg(&data.weight_pounds, &data.weight_kg);
	data.weight_g = convertLbsG(&data.weight_pounds, &data.weight_g);
	data.servingTotal = calculateServings(SUGGESTED_SERVING_G, data.weight_g, &data.servingTotal);
	data.costPserving = calculateCostPerServing(&data.priceData, &data.servingTotal, &data.costPserving);
	totalCalories = data.caloriesData * data.servingTotal;
	data.costPcalorie = calculateCostPerCal(&data.priceData, &totalCalories, &data.costPcalorie);

	return data;
}

// 15. Display the formatted table header for the analysis results

void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", SUGGESTED_SERVING_G);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const int cheapiestOption)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", data.skuData, data.priceData, data.weight_pounds, data.weight_kg, data.weight_g, data.caloriesData, data.servingTotal, data.costPserving, data.costPcalorie);

}

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo catProduct)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", catProduct.sku, catProduct.price);
	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct ReportData data[MAX_PRODUCTS];
	struct CatFoodInfo catProduct[MAX_PRODUCTS];
	//allocating arrays of struct since we have to get information for 3(MAX_PRODUCTS) products
	int i, cheapestI=0, cheapestOption;
	double cheapest = 0;

	openingMessage(MAX_PRODUCTS);

	for (i = 0; i < MAX_PRODUCTS; i++)
	//loop for get information for all the products(array)
	{
		catProduct[i] = getCatFoodInfo(i);
		data[i] = calculateReportData(catProduct[i]);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCTS; i++)
	//loop for printing all of the products(printing all of the information that we got from function getCatFooodInfo
	{
		displayCatFoodData(catProduct[i].sku, &catProduct[i].price, &catProduct[i].weight, catProduct[i].calories);
	}
	printf("\n");
	
	displayReportHeader();

	//Figure out which one is the cheapest option
	cheapest = data[0].costPserving;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (data[i].costPserving == cheapest || data[i].costPserving < cheapest)
		//comapring the cost per sering
		{
			cheapest = data[i].costPserving;
			//cheapest price(cost per serving)
			cheapestOption = catProduct[i].sku;
			//get sku of the cheapest product
			cheapestI = i;
			//to call which one of the arrays of product is the cheapest one
		}
	}

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayReportData(data[i], cheapestOption);
		if (i==cheapestI)
		{
			printf(" ***");
		}
		//printing *** to indicate the cheapest option
		printf("\n");
	}
	printf("\n");


	displayFinalAnalysis(catProduct[cheapestI]);


}
