#include <stdio.h>
#include <stdlib.h>

typedef struct CLLNode {
	int data;
	struct CLLNode *next; // Can be "struct Node *next" is the other structure exists
};

int main(){
	struct CLLNode *head; // Struct pointer, NOT instance
	struct CLLNode *second;
	struct CLLNode *third;
	struct CLLNode *fourth;

	// Allocate memory for the nodes in LL in Heap
	head = (struct CLLNode *) malloc (sizeof(struct CLLNode));
	second = (struct CLLNode *) malloc (sizeof(struct CLLNode));
	third = (struct CLLNode *) malloc (sizeof(struct CLLNode));
	fourth = (struct CLLNode *) malloc (sizeof(struct CLLNode));

	// Linking on Nodes
	head->data = 23;
	head->next = second;

	second->data = 5;
	second->next = third;

	third->data = 54;
	third->next = fourth;

	fourth->data = 32;
	fourth->next = head; // Only difference
	return 0;
}


// Create with Loop
void create (struct node **head)
{
    struct node *temp, *rear;
    int a, ch;
 
    do
    {
        printf("Enter a number: ");
        scanf("%d", &a);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = a;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Do you want to add a number [1/0]? ");
        scanf("%d", &ch);
    } while (ch != 0);
    rear->next = *head;
}


// Create with singly incrementing numbers : 
void create (struct CLLNode **head, int n){
    struct CLLNode *temp, *rear;
    int count = 1;

    for (int i = 0; i < n ; i++){
        temp = (struct CLLNode *)malloc(sizeof(struct CLLNode));
        temp->data = count;
        temp->next = NULL;
        if (*head == NULL){
            *head = temp;
        } else {
            rear->next = temp;
        }
        rear = temp;
        count++;
    }
    rear->next = *head;
}

