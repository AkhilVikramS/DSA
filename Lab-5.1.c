#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next,*prev;
};

void insert(struct node** head,int data,int pos)
{
    struct node* newNode=(struct node*) malloc (sizeof(struct node));
    struct node* curr;
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    if (pos == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    curr=*head;
    for (int i = 0; i < pos-1; i++){
    curr=curr->next;
    }
    if (curr==NULL){
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }else if (curr->next==NULL) {
        newNode->prev=curr;
        curr->next=newNode;
        return;
    }else{
        newNode->next=curr->next;
        newNode->prev=curr;
        curr->next->prev=newNode;
        curr->next=newNode;
        return;
    }
}

void delete(struct node** head,int pos)
{
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp=*head;

    if (pos == 0) {
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    return;
    }

    for (int i = 0;temp!=NULL && i < pos-1; i++){
        temp=temp->next;
    }
    if (temp==NULL || temp->next==NULL){
        printf("Position out of bound\n");
        return;
    }
    struct node* nodeToDelete = temp->next;
    struct node* next = nodeToDelete->next;

    temp->next = next;
    if (next != NULL) {
        next->prev = temp;
    }
    free(nodeToDelete);
}

void traverse(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" <--> ");
        head = head->next;
    }
    printf("\n");
}


int main()
{
    int n,data;
    struct node* head=NULL,*temp=NULL;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&data);
        newNode->data=data;
        newNode->prev=NULL;
        newNode->next=NULL;
        if (head==NULL)
            head=newNode;
        else{
            temp->next=newNode;
            newNode->prev=temp;
        }
        temp=newNode;
    }
    printf("   MENU:\n");
    printf("1. Insert the node at a position\n");
    printf("2. Delete a node from specific position\n");
    printf("3. Traversal\n");
    printf("5. Exit\n");
    int choice,pos;
    do{
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&data);
                printf("Enter position: ");
                scanf("%d",&pos);
                insert(&head,data,pos);
                printf("Node inserted\n");
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d",&pos);
                delete(&head,pos);
                printf("Node deleted\n");
                break;
            case 3:
                traverse(head);
                break;
        }
    }while(choice!=4);
    return 0;
}