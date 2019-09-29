/* Dan Halverson */
#include <stdio.h>

long int fibonacci(int n);

FILE *ipt, *opt;

main()
{
	long int fib = 0, a, i;

	ipt = fopen ("RFIB.IN", "r");
	opt = fopen ("RFIB.OUT ", "w");

	for (i = 1; i <= 36; i++)
	{
		fscanf(ipt,"%ld", &a);
		fib = fibonacci (a);
		fprintf(opt,"%ld = %ld \n", a, fib);
	}

	fclose (ipt);
	fclose (opt);

	return 0;
}

long int fibonacci (int n)
{
	if(n == 0)
	{return 0;}
	else if (n == 1)
	{return 1;}
	else
	{
        return (fibonacci(n-1) + fibonacci(n-2));
	}
	
}
