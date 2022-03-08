// Refer : https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node * push (struct Node *head, int data){
  struct Node* ptr = (struct Node *) malloc (sizeof(struct Node));
  ptr->data = data;
  ptr->next = head;
  return ptr;
}

struct Node * pop (struct Node *head){
  struct Node* temp = head;
  head = head->next;
  free(temp);
  return head;
}

void peek (struct Node *head){
  printf("%d\n", head->data);
  return;
}

void isEmpty(struct Node *head){
	if (head->next == NULL)
		printf("The stack is empty");
	else
		printf("List is not empty");
}

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