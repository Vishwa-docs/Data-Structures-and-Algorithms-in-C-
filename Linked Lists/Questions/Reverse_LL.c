// https://www.geeksforgeeks.org/reverse-a-linked-list/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
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

struct Node * reverse(struct Node * head){
  struct Node *next = NULL;
  struct Node *prev = NULL;
  struct Node *current = head;

  while (current != NULL){
    // Store Next pointer
    next = current->next;
    
    // Reverse
    current->next = prev;
    // Head pointer will point to NULL as prev is initially NULL

    // Move One position
    prev = current;
    current = next;
  }
  head = prev;
  return head;
}

int main(){
	struct Node *head; 
	struct Node *second;
	struct Node *third;
	struct Node *fourth;


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
  printf("\n");
  head = reverse(head);
  LLTraversal(head);
	return 0;
}