/* Dan Halverson */

#include <stdio.h>

#define MAXY(a,b) ( ((a) > (b)) ? (a) : (b) )

int RMaxInArray (int a[], int n);

int main(void)
{
   int a[] = {6, 17, -5, 24, 0, 18}, size = 6;
   
   printf("The maximum array element is %d \n", RMaxInArray(a,size));
   
   return 0;
}

int RMaxInArray (int a[], int n)
{
   if (n == 1)
   {
      return a[0];
   }
   else
   {
      return (MAXY(a[n-1], (RMaxInArray(a, n - 1))));
   }
}
