/* 

https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void nth_from_end (struct Node * head, int n){
  struct Node * temp = head;
  int len = 0;

  while (temp != NULL){
    len++;
    temp = temp -> next;
  } 

  int go = len - n + 1;

  temp = head;
  for (int i = 0; i <= go; i++){
    temp = temp->next;
  }

  printf("%d", temp->data);
  
  return;
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

  nth_from_end(head, 3);
  
	return 0;
}