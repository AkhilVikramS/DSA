#include<stdio.h>

void max(int *a,int *b)
{
	if(*a>*b)
		printf("%d is greater than %d",*a,*b);
	else
		printf("%d is smaller than %d",*a,*b);
}
int main()
{
	int a,b,result;
	printf("Enter the two numbers ");
	scanf("%d%d",&a,&b);
	max(&a,&b);
	return 0;
}