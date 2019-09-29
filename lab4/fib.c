/* Dan Halverson */
#include <stdio.h>

long int fibonacci(int n);

FILE *ipt, *opt;

main()
{
	long int fib = 0, a, i;

	ipt = fopen ("RFIB.IN", "r");
	opt = fopen ("FIB.OUT ", "w");

	for (i = 1; i <= 36; i++)
	{
		fscanf(ipt,"%d", &a);
		fib = fibonacci (a);
		fprintf(opt,"%d = %d \n", a, fib);
	}

	fclose (ipt);
	fclose (opt);

	return 0;
}

long int fibonacci (int n)
{
	int i;
	long int fib_1 = 1, fib_2 = 0, fib;

	if(n == 0)
	{fib = 0;}
	else if (n == 1)
	{fib = 1;}
	else
	{
		for (i = 2; i <= n; i++)
		{
			fib = fib_1 + fib_2;
			fib_2 = fib_1;
			fib_1 = fib;
		}
	}
	return (fib);
}
