/* Dan Halverson lab2.c*/

#include <stdio.h>
#include <string.h>

float depreciation (float cost, int checked);
float rounded (float dep_cost);
float savings (float cost, float rounded_dep);
int print_header(int break_sw, char LName[], char FName[]);

FILE *ipt, *opt;

int main(void)
{
	char BookNum[6], CopyNum[5], LName[18], FName[12], old_lname[18], old_fname[12];
	int checked = 0, sw = 1, counter_book = 0, break_sw = 0;
	float deprec_cost,  rounded_deprec, savings_calculated;
	float cost = 0.0f, SubCost = 0.0f, SubDepCost = 0.0f, SubSavings = 0.0f;
	float GrandCost = 0.0f, GrandDepCost = 0.0f, GrandCostSavings = 0.0f;
	
	ipt = fopen("LAB3.IN", "r+");
	opt = fopen("LAB3.OUT", "w+");

	fscanf (ipt, "%s %s %f %d %s %s",BookNum, CopyNum, &cost, &checked, LName, FName);

	print_header(break_sw, FName, LName);

	strcpy (old_lname, LName);
	strcpy (old_fname, FName);
	
	do
	{
		deprec_cost = depreciation (cost, checked);
		rounded_deprec = rounded (deprec_cost);
		savings_calculated = savings (cost, rounded_deprec);

	if ((strcmp (old_lname, LName) == 0) && (strcmp (old_fname, FName) == 0))
	{	
			
			SubCost += cost;
			SubDepCost += deprec_cost;
			SubSavings += savings_calculated;
			counter_book++;
			
	}
	else
	{	
			fprintf(opt,"***\n");
			fprintf(opt,"Subtotal:        $ %6.2f          $ %6.2f     $ %6.2f \n", SubCost, SubDepCost, SubSavings);
			fprintf(opt,"Books Checked Out:  %d", counter_book);
			fprintf(opt,"\n");
			
			GrandCost += SubCost;
			GrandDepCost += SubDepCost;
			GrandCostSavings += SubSavings;
			SubCost = cost;
			SubDepCost = deprec_cost;
			SubSavings = savings_calculated;
			sw = 1;
			counter_book = 1;
			break_sw++;
			print_header(break_sw, FName, LName);
			strcpy (old_lname, LName);
			strcpy (old_fname, FName);
			
	}
	
	fprintf(opt,"%s    %s    $ %6.2f    %-1d     $ %6.2f     $ %6.2f \n", BookNum, CopyNum, cost, checked, rounded_deprec, savings_calculated);
	
	}
	while (fscanf (ipt, "%s %s %f %d %s %s",BookNum, CopyNum, &cost, &checked, LName, FName) == 6);
	
	fprintf(opt,"***\n");
	fprintf(opt,"Subtotal:        $ %6.2f          $ %6.2f     $ %6.2f \n", SubCost, SubDepCost, SubSavings);
	fprintf(opt,"Books Checked Out:  %d", counter_book);
	fprintf(opt,"\n");

	GrandCost += SubCost;
	GrandDepCost += SubDepCost;
	GrandCostSavings += SubSavings;

	fprintf(opt,"Grand Total:     $ %.2f        $ %.2f      $%.2f", GrandCost, GrandDepCost, GrandCostSavings);
	
	fclose (ipt);
	fclose (opt);

	return 0;
}

float depreciation (float cost, int checked)
{
	int i;	
	float percent = 0.9;
	float dep_cost = cost;
	
	for (i = 1; i <= checked; i++)
	{
		dep_cost = percent * dep_cost;
		
	}

	return dep_cost;
}

float rounded (float dep_cost)
{
	int cents;
	float rounded_dep;

	cents = dep_cost * 100 + .5;
	rounded_dep = cents / 100.0;


	return rounded_dep;
}

float savings (float cost, float rounded_dep)
{
	float savings_calc;
	savings_calc = cost - rounded_dep;

	return savings_calc;
}

int print_header(int break_sw, char FName[], char LName[])
{
	if (break_sw == 4)
	{fprintf(opt, "\f");
	break_sw = 0;}

	fprintf(opt,"Student Name:  %s %s \n", FName, LName);
	fprintf(opt,"*** \n");
	fprintf(opt,"Book     Copy    Original  Times   Depreciated  Cost \n");
	fprintf(opt,"Number   Number  Cost      Rented  Cost         Savings \n");
	fprintf(opt,"*** \n");

	return break_sw;
}
