#include<stdio.h>
int nonzero(int row,int column,int arr[row][column])
{
	int count=0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (arr[i][j]!=0)
				count+=1;
		}
	}
	return count;

}
int main()
{
	int row,column,nzero;
	printf("Enter size of the sparse matrix: ");
	scanf("%d%d",&row,&column);
	int arr[row][column];
	printf("Enter elements of saprse matrix: ");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	nzero=nonzero(row,column,arr);
	printf("sparse matrix in 3-tuple format\n");
	printf("%d %d %d\n",row ,column,nzero);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (arr[i][j]!=0)
				printf("%d %d %d",i,j,arr[i][j]);
		}
		printf("\n");
	}

	
	return 0;
}