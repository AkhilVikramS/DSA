#include <stdio.h>
#include <stdlib.h>

void insert(int *n, int a[], int element, int position) {
    if (position < 0 || position > *n) {
        printf("Unable to insert the element.\n");
        return;
    }
    for (int i = *n; i > position; i--) {
        a[i] = a[i - 1];
    }
    a[position] = element;
    (*n)++;
    printf("Element inserted.\n");
}

void delete(int a[], int *n, int position) {
    if (position < 0 || position >= *n) {
        printf("Unable to delete.\n");
        return;
    }
    for (int i = position; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
    printf("Element deleted.\n");
}

int linearSearch(int n, int a[], int element) {
    for (int i = 0; i < n; i++) {
        if (a[i] == element) {
            return i;
        }
    }
    return -1;
}

void traverseArray(int n, int a[]) {
    printf("Array elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, element, position, choice;
    int a[100];

    printf("Enter size n:\n");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("\n");

    do {
        printf("MENU\n");
        printf("1. Insert an element at a specific position\n");
        printf("2. Delete an element from a specific position\n");
        printf("3. Search for an element (linear search)\n");
        printf("4. Traverse the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to enter the element: ");
                scanf("%d", &position);
                insert(&n, a, element, position);
                break;
            case 2:
                printf("Enter the position to delete the element: ");
                scanf("%d", &position);
                delete(a, &n, position);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                position = linearSearch(n, a, element);
                if (position == -1) {
                    printf("Element not found in the array.\n");
                } else {
                    printf("Element found at position: %d\n", position);
                }
                break;
            case 4:
                traverseArray(n, a);
                break;
            case 5:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
