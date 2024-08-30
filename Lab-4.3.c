#include<stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coeff,expo;
    struct node* next;
}node;

node* createNode(int coeff,int expo)
{
    node* newNode = (node*) malloc(sizeof(node));
    if (newNode==NULL) 
        printf("Memory error\n");
    newNode->coeff=coeff;
    newNode->expo=expo;
    newNode->next=NULL;
    return newNode;
}

void append(node **head,int coeff,int expo)
{
    node* newNode = createNode(coeff,expo);
    if (*head==NULL)
        *head=newNode;
    else{
        node* temp=*head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }

}

node* addPoly(node* P,node* Q)
{
    node* result=NULL;
    while (P!=NULL && Q!=NULL){
        if (P->expo==Q->expo){
            append(&result,P->coeff+Q->coeff,P->expo);
            P=P->next;
            Q=Q->next;
        }else if (P->expo>Q->expo) {
            append(&result,P->coeff,P->expo);
            P=P->next;
        }else {
            append(&result,Q->coeff,Q->expo);
            Q=Q->next;
        }
    }
    while (P!=NULL){
        append(&result,P->coeff,P->expo);
        P=P->next;        
    }
    while (Q!=NULL){
        append(&result,Q->coeff,Q->expo);
        Q=Q->next;        
    }
    return result;
}

int main()
{
    int max_pow1,max_pow2,coeff;
    node* poly1=NULL,*poly2=NULL;
    printf("Polynomial-1: \n");
    printf("Enter the Maximum power of x: ");
    scanf("%d",&max_pow1);
    for (int i = max_pow1; i>=0 ; i--) {
        printf("Enter the coefficient of degree %d: ",i);
        scanf("%d",&coeff);
        append(&poly1,coeff,i);
    }
    printf("Polynomial-2: \n");
    printf("Enter the Maximum power of x: ");
    scanf("%d",&max_pow2);
    for (int i = max_pow2; i>=0 ; i--) {
        printf("Enter the coefficient of degree %d: ",i);
        scanf("%d",&coeff);
        append(&poly2,coeff,i);
    }
    node* result=addPoly(poly1,poly2),*temp=result;
    while(temp!=NULL)
	{
		printf("%dx^%d",temp->coeff,temp->expo);
        temp=temp->next;
        if (temp!=NULL)
            printf(" + ");
	}       
    return 0;
}