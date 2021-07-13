#include<stdio.h>
void main()
{
int a = 0;
int b = 1;
int c = 0;
int i ;
int n ;
printf("Enter the term till which you want fibonacci series to be generated: ");
scanf("%d",&n);
for(i = 2 ; i <= n ; i ++)
{
	c = a + b;
	a = b;
	b = c;	
}	
printf("The generated term is: %d",c);
}
