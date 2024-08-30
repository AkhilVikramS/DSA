#include<stdio.h>
int main()
{
	int row1,col1,ele1;
	printf("Enter sparse matirx-1 in 3-tuple format\n");
	scanf("%d%d%d",&row1,&col1,&ele1);
	int mat1[ele1][3];
	for (int i = 0; i < ele1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}

	int row2,col2,ele2;
	printf("Enter sparse matirx-2 in 3-tuple format\n");
	scanf("%d%d%d",&row2,&col2,&ele2);
	int mat2[ele2][3];
	for (int i = 0; i < ele2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d",&mat2[i][j]);
		}
	}
	int result[ele1 + ele2][3];
    int i = 0, j = 0, k = 0;

	while (i < ele1 && j < ele2) {
        if (mat1[i][0] < mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1])) {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++;
        } else if (mat1[i][0] > mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] > mat2[j][1])) {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++;
        } else {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2] + mat2[j][2];
            i++;
            j++;
        }
        k++;
    }
	 while (i < ele1) {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++;
        k++;
    }
    while (j < ele2) {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = mat2[j][2];
        j++;
        k++;
    }
	 printf("Resultant Sparse Matrix in 3-Tuple Form:\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }

    return 0;
}