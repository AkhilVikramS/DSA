#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void insert(struct node **head,int data,int posi)
{
	struct node *newNode=(struct node*)malloc(sizeof(struct node)),*curr;
	newNode->data=data;
	newNode->next=NULL;
	if (posi == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
	
	curr=*head;
	for(int i=0;i<posi-1;i++){
		curr=curr->next;		
	}
	if (curr == NULL) {
		printf("Position out of bounds\n");
		free(newNode);
		return;
	}
	newNode->next=curr->next;
	curr->next=newNode;
}

void delete(struct node **head,int posi)
{
	 if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;

    if (posi == 0) {
        *head = temp->next;  
        free(temp);          
        return;
    }

    for (int i = 0; temp != NULL && i < posi - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    struct node* next = temp->next->next;

    free(temp->next); 

    temp->next = next;  
}
int count(struct node *head)
{
	int count = 0;
    struct node* curr = head;
    while (curr != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}

int search(struct node *head, int key) {
    struct node *curr = head;
    int pos = 0;
    
    while (curr != NULL) {
        if (curr->data == key) {
            return pos;
        }
        curr = curr->next;
        pos++;
    }
    
    return -1; 
}
void sort(struct node *head) {
    if (head == NULL) {
        return;
    }

    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverse(struct node **head) {
    struct node *prev = NULL;
    struct node *curr = *head;
    struct node *next = NULL;

    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;        
        curr = next;
    }

    *head = prev;  
}

void traverse(struct node *head)
{
	printf("The linked list is: ");
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main()
{
	int n,data,posi;
	struct node *head = NULL, *temp = NULL;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		struct node* node=(struct node*) malloc (sizeof(struct node));
		printf("Enter data for node %d:",i+1);
		scanf("%d",&data);
		node->data=data;
		node->next=NULL;

		if (head==NULL)
			head=node;
		else
			temp->next=node;
		temp=node;
	}
	printf("MENU\n");
	printf("1. Insert a node at a position\n");
	printf("2. Delete a node from a specific position\n");
	printf("3. Count\n");
	printf("4. Traversal\n");
	printf("5. Search\n");
	printf("6. Sort\n");
	printf("7. Reverse\n");
	printf("8. Exit\n");
	int opt;
	
	do{
		printf("Enter the choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("Enter element: ");
				scanf("%d",&data);
				printf("Enter position: ");
				scanf("%d",&posi);
				insert(&head,data,posi);
				printf("Node Inserted\n");
				break;
			case 2:
				printf("Enter position: ");
				scanf("%d",&posi);
				delete(&head,posi);
				printf("Element deleted\n");
				break;
			case 3:
				printf("%d Nodes are linked\n",count(head));
				break;
			case 4:
				traverse(head);
				break;
			case 5:
				printf("Enter element to be searched: ");
				int key,pos;
				scanf("%d",&key);
				pos=search(head,key);
				if(pos==-1)
					printf("Element NOT FOUND");
				else
					printf("Element fount at position %d\n",pos);
				break;
			case 6:
				sort(head);
                printf("List sorted\n");
				break;
			case 7:
				reverse(&head);
                printf("List reversed\n");
				break;
			case 8:
				break;
			
		}
	}while (opt!=8);
	return 0;
}
