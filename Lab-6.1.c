#include<stdio.h>
#define MAX 10
void Push(int stack[],int* top,int element)
{
    if(*top==MAX-1){
        printf("Stack is full\n");
        return;
    }
    stack[++(*top)]=element;
}

int Pop(int stack[],int* top)
{
    if(*top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[(*top)--];
}
void isEmpty(int top)
{
    if(top==-1){
        printf("True\n");
    }else{
        printf("False\n");
    }
}
void isFull(int top)
{
    if(top==MAX-1){
        printf("True\n");
    }else{
        printf("False\n");
    }
}
void traverse(int stack[],int top)
{
    for(int i=top;i!=-1;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main()
{
    int stack[MAX],top=-1;
    printf("Main Menu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. IsEmpty\n");
    printf("4. IsFull\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
    int choice,element,pop;
    do{
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element to be pushed into stack: ");
                scanf("%d",&element);
                Push(stack,&top,element);
                break;
            case 2:
                pop = Pop(stack, &top);
                if (pop != -1) {
                    printf("%d Deleted from stack\n", pop);
                }
                break;
            case 3:
                isEmpty(top);
                break;
            case 4:
                isFull(top);
                break;
            case 5:
                traverse(stack,top);
                break;                               
        }
    }while(choice!=6);
    return 0;
}
