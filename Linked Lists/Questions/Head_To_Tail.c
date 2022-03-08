// Q. To make the head node as the last node and the second node as the head

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next; // Self Referencial structure
};

void LLTraversal(struct Node *head){
	struct Node *current = head;
	int count = 0;

	while (current != NULL){
		printf("Element %d\n", current->data); 
		current = current->next;
	}
	return;
}

struct Node * head_to_tail(struct Node *head){
  struct Node *current = head;
  struct Node *oldhead = head;

  head = head->next;

  while(current->next != NULL){
    current = current->next;
  }
  current->next = oldhead;
  current->next->next = NULL;
  
  return head;
}

int main(){
	struct Node *head;
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

  LLTraversal(head);
  head = head_to_tail(head);
  printf("\n");
  LLTraversal(head);
	return 0;
}