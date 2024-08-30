#include <stdio.h>

int main() {
    int row, column, element;

    printf("Enter the sparse matrix in 3-tuple:\n");
    scanf("%d%d%d", &row, &column, &element);

    int arr[element][3], transpose[element][3];

    for (int i = 0; i < element; i++) {
        scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }

    for (int i = 0; i < element; i++) {
        transpose[i][0] = arr[i][1];
        transpose[i][1] = arr[i][0];
        transpose[i][2] = arr[i][2];
    }

    printf("Transpose of the sparse matrix:\n");
    printf("R C Element\n");
    printf("%d %d %d\n", column, row, element);
    for (int i = 0; i < element; i++) {
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

    return 0;
}
