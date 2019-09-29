/* Dan Halverson fbubble.c */

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
	opt = fopen("FBUBBLE.OUT", "w");

	fscanf(ipt,"%d",&count);

	item = fvecalloc (1, count);

	for (i = 1; i <= count; ++i)
	{
		fscanf(ipt, "%f", &item[i]);
	}
	
	bubble_float(item, count);

	for (i = 1; i <= count; ++i)
	{
		fprintf(opt, "% 6.4f \n", item[i]);
	}

	fclose (ipt);
	fclose (opt);

	return 0;
}

void bubble_float(float *item, int count)
{
	int i, j;
	
	for (i = 1; i < count; ++i)
	{
		for(j = (count - 1); j > i; --j)
		{
			if (item[j-1] > item [j])
			{
			swap_float(&item[j-1], &item[j]);
			}
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