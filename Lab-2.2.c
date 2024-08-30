#include<stdio.h>
int nonzero(int n,int arr[n][n])
{
	int count=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j]!=0)
				count+=1;
		}
	}
	return count;

}


void utrimat(int n,int arr[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(j>i)
				printf("%d ",arr[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
}

void abmat(int n,int arr[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j==i+1 || j==i-1)
				printf("%d ",arr[i][j]);
		}
	}
}

int main()
{
	int n,nonzero_count,utmat;
	printf("Enter size of the square matrix: ");
	scanf("%d",&n);
	int arr[n][n];
	printf("Enter elements of the matrix: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	nonzero_count = nonzero(n, arr);
	printf("Nonzero elements: %d\n",nonzero_count);
	utrimat(n,arr);
	abmat(n,arr);
	return 0;
}