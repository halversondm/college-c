/* Dan Halverson ftranspos.c */

#include <stdio.h>
#include "MEMALLOC.C"

void bubble_float(float *item, int count);
void swap_float(float *p, float *q);

FILE *ipt, *opt;

int main(void)
{
	float *item;
	int count, i;

	ipt = fopen("FLOATS.IN", "r");
	opt = fopen("FTRANSPOS.OUT", "w");

	fscanf(ipt,"%d",&count);

	item = fvecalloc (1, count);

	for (i = 1; i <= count; ++i)
	{
		fscanf(ipt, "%f", &item[i]);
	}
	
	bubble_float(item, count);

	fprintf(opt,"\n");
	
	for (i = 1; i <= count; ++i)
	{
		fprintf(opt,"% 6.4f \n", item[i]);
	}

	fclose (ipt);
	fclose (opt);

	return 0;
}

void bubble_float(float *item, int count)
{
	int i, j, k;
	
	for (i = 1; i < count; ++i)
	{
		for(j = i + 1; j < count; ++j)
		{
			if (item[i] > item[j])
			{
			swap_float(&item[i], &item[j]);
			}
		}

		fprintf(opt,"\n");
		for (k = 1; k <= count; ++k)
		{
		fprintf(opt,"% 6.4f \n", item[k]);
		}
	}
}


void swap_float(float *p, float *q)
{
	float temp;

	temp = *p;
	*p = *q;
	*q = temp;

}