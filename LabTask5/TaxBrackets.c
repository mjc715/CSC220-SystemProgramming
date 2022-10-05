#include <stdio.h>
#include <stdlib.h>

double CalcTaxableIncome(double Income, double Deductibles);
char CalcTaxGroup(double TaxableIncome);
double CalcTaxOwed(char TaxGroup, double TaxableIncome);
void PrintInfo(double Income, double Deductibles, double TaxableIncome, char TaxGroup, double TaxOwed);

//===========================================================
int main()
{
	double NextAmount = -1;
	double Deductibles = 0;
	double Income = 0;

	printf("\n");

	while (NextAmount != 0)
	{
		printf("Enter income / deductible: ");
		scanf("%lf", &NextAmount);

		if (NextAmount > 0)
			Income = Income + NextAmount;
		if (NextAmount < 0)
			Deductibles = Deductibles + NextAmount;
	}

	Deductibles = Deductibles * -1;
	double TaxableIncome = CalcTaxableIncome(Income, Deductibles);
	char TaxGroup = CalcTaxGroup(TaxableIncome);
	double TaxOwed = CalcTaxOwed(TaxGroup, TaxableIncome);
	PrintInfo(Income, Deductibles, TaxableIncome, TaxGroup, TaxOwed);

	printf("\n");
	printf("Income : $%.2lf \n", Income);
	printf("Deductions : $%.2lf \n", Deductibles);
}
//=============================================================
double CalcTaxableIncome(double Income, double Deductibles)
{
	double TaxableIncome = Income - Deductibles;
	if (TaxableIncome < 0)
		TaxableIncome = 0;

	return (TaxableIncome);
}
//-------------------------------------------------------------
char CalcTaxGroup(double TaxableIncome)
{

	if (TaxableIncome < 20000)
	{
		return ('P');
	}
	else if (TaxableIncome < 50000)
	{
		return ('R');
	}
	else if (TaxableIncome < 100000)
	{
		return ('A');
	}
	else if (TaxableIncome < 200000)
	{
		return ('M');
	}
	else if (TaxableIncome < 500000)
	{
		return ('Q');
	}
	else
	{
		return ('S');
	}
}
//--------------------------------------------------------------
double CalcTaxOwed(char TaxGroup, double TaxableIncome)
{
	switch (TaxGroup)
	{
	case 'P':
		return 0.0;
	case 'R':
		return (TaxableIncome * .03);
	case 'A':
		return (TaxableIncome * .03);
	case 'M':
		return (TaxableIncome * .1);
	case 'Q':
		if (TaxableIncome * .25 >= 50000)
			return 50000;
		else
			return TaxableIncome * .25;
	case 'S':
		if (TaxableIncome * .25 >= 50000)
			return 50000;
		else
			return TaxableIncome * .25;
	default:
		printf("Something went horribly wrong\n");
	}
}
//----------------------------------------------------------------
void PrintInfo(double Income, double Deductibles, double TaxableIncome, char TaxGroup, double TaxOwed)
{
	printf("\n");
	printf("Income : $%.2lf \n", Income);
	printf("Deductions : $%.2lf \n", Deductibles);
	printf("Taxable income : $%.2lf \n", TaxableIncome);
	printf("Tax group : %c", TaxGroup);
	printf("Tax owed : %.2lf", TaxOwed);
	printf("\n");
}
//-----------------------------------------------------------------
