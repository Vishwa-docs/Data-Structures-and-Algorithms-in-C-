#include <stdio.h>
#include <stdlib.h>

struct DLLNode{
	int data;
	struct DLLNode *next;
	struct DLLNode *prev;
};

int main(){
	struct DLLNode *head; // Struct pointer, NOT instance
	struct DLLNode *second;
	struct DLLNode *third;
	struct DLLNode *tail;

	// Allocate memory for the nodes in LL in Heap
	head = (struct DLLNode *) malloc (sizeof(struct DLLNode));
	second = (struct DLLNode *) malloc (sizeof(struct DLLNode));
	third = (struct DLLNode *) malloc (sizeof(struct DLLNode));
	tail = (struct DLLNode *) malloc (sizeof(struct DLLNode));

	// Linking on Nodes
	head->data = 23;
	head->next = second;
	head->prev = NULL;

	second->data = 5;
	second->next = third;
	second->prev = head;

	third->data = 54;
	third->next = tail;
	third->prev = second;

	tail->data = 32;
	tail->next = NULL;
	tail->prev = third;
  
	return 0;
}