#include<stdio.h>
struct employee
{
	char name[50],designation[50];
	int basic,hra,da,gross;
};
int main()
{
	int n;
	printf("Enter the no. of employees: ");
	scanf("%d",&n);
	struct employee employee[n];

	for (int i = 0; i < n; i++)
	{
		printf("Enter Employee %d information: \n",i+1);
		printf("Enter Employee name: ");
		scanf(" %[^\n]",employee[i].name);
		printf("Enter Employee designation: ");
		scanf(" %[^\n]",employee[i].designation);
		printf("Enter Employee basic pay: ");
		scanf(" %d",&employee[i].basic);
		printf("Enter Employee HRA: ");
		scanf(" %d",&employee[i].hra);
		printf("Enter Employee DA: ");
		scanf(" %d",&employee[i].da);
		employee[i].gross=employee[i].basic+employee[i].hra*employee[i].basic+employee[i].da*employee[i].basic;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("Details of Employee-\n");
		printf("Name: %s\nDesignation: %s\nBasic Pay: %d\nHRA%: %d\nDA%: %d\nGross Pay: %d\n\n\n",employee[i].name,employee[i].designation,employee[i].basic,employee[i].hra,employee[i].da,employee[i].gross);
		return 0;
	}
}