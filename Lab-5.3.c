#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(Node** head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the sparse matrix in 3-tuple format
void displaySparseMatrix(Node* head) {
    printf("sparse matrix in 3-tuple format\n");
    while (head != NULL) {
        printf("%d   %d   %d\n", head->row, head->col, head->value);
        head = head->next;
    }
}

int main() {
    int rows, cols;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    Node* head = NULL;

    int numElements = rows * cols;
    int elements[numElements];
    printf("Enter elements of sparse matrix: ");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &elements[i]);
    }

    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (elements[count] != 0) {
                insertNode(&head, i, j, elements[count]);
            }
            count++;
        }
    }

    displaySparseMatrix(head);

    return 0;
}