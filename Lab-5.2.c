#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

int main()
{
    int n,data;
    struct node* head=NULL,*temp;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++){
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            newNode->next=head;
        }else{
            temp->next=newNode;
            newNode->next=head;
        }
        temp=newNode;
    }
    if (head == NULL) {
        printf("List is empty\n");
    }
    temp=head;    
    do{
        printf("%d",temp->data);
        if (temp->next!=head)
            printf(" -> ");
        temp=temp->next;
    }while(temp!=head);
    return 0;    
}