#include "factorial.h"
void main()
{
	int n;
	printf("Enter the number for which you want to find the factorail: ");
	scanf("%d",&n);
	printf("Factorial of %d : %d",n,factorial(n));
}
