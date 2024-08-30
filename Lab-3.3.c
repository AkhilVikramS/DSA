#include <stdio.h>
#include <stdlib.h>

int main() {
    int max_degree;
    printf("Enter maximum degree of x: ");
    scanf("%d", &max_degree);

    int *poly1 = (int *)malloc((max_degree + 1) * sizeof(int));
    int *poly2 = (int *)malloc((max_degree + 1) * sizeof(int));
    int *result = (int *)malloc((max_degree + 1) * sizeof(int));


    printf("Enter Polynomial-1: ");
    for (int i = 0; i <= max_degree; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter Polynomial-2: ");
    for (int i = 0; i <= max_degree; i++) {
        scanf("%d", &poly2[i]);
    }

    for (int i = 0; i <= max_degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }

    printf("Result: ");
    for (int i = max_degree; i >= 0; i--) {
        printf("%dx^%d", result[i], i);
        if (i!=0)
            printf(" + ");
    }
    printf("\n");
    free(poly1);
    free(poly2);
    free(result);
    return 0;
}