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