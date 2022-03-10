#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next; // Self Referencial structure
};

int main(){
	struct Node *head; // Struct pointer, NOT instance
	struct Node *second;
	struct Node *third;
	struct Node *fourth;

	// Allocate memory for the nodes in LL in Heap
	head = (struct Node *) malloc (sizeof(struct Node));
	second = (struct Node *) malloc (sizeof(struct Node));
	third = (struct Node *) malloc (sizeof(struct Node));
	fourth = (struct Node *) malloc (sizeof(struct Node));

	// Linking on Nodes
	head->data = 23;
	head->next = second;

	second->data = 5;
	second->next = third;

	third->data = 54;
	third->next = fourth;

	fourth->data = 32;
	fourth->next = NULL;
	return 0;
}


/********** Taking Inputs from Users *************/

struct Node *prev, *head, *temp;
int n;
printf("Enter the number of elements : ");
scanf("%d", &n);
head = NULL;

for (int i = 0; i < n; i++){
	temp = (struct Node *) malloc (sizeof(struct Node));
	scanf("%d", &temp->data);
	temp->next = NULL;
	if (head == NULL)
		head = temp;
	else
		prev->next = temp;
	prev = temp;
}