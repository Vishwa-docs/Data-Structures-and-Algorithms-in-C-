/* 
https://www.geeksforgeeks.org/reverse-a-linked-list/
https://www.geeksforgeeks.org/recursively-reversing-a-linked-list-a-simple-implementation/
XOR Method : https://www.geeksforgeeks.org/iteratively-reverse-a-linked-list-using-only-2-pointers/
*/


/*************ITERATIVE METHOD*************/

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

/*************RECURSIVE METHOD*************/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void LLTraversal(struct Node *head){
    struct Node *current = head;

    while (current != NULL){
        printf("Element %d\n", current->data);
        current = current->next;
    }
    return;
}

void reverseUtil(struct Node* curr, struct Node* prev, struct Node** head);

void reverse(struct Node** head){
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}

void reverseUtil(struct Node* curr, struct Node* prev, struct Node** head){
    if (!curr->next) {
        *head = curr;

        /* Update next to prev struct node */
        curr->next = prev;
        return;
    }

    /* Save curr->next struct node for recursive call */
    struct Node* next = curr->next;

    /* and update next ..*/
    curr->next = prev;

    reverseUtil(next, curr, head);
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;


    head = ( struct Node *) malloc (sizeof( struct Node));
    second = ( struct Node *) malloc (sizeof( struct Node));
    third = ( struct Node *) malloc (sizeof( struct Node));
    fourth = ( struct Node *) malloc (sizeof( struct Node));

    // Linking on struct Nodes
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
    reverse(head);
    LLTraversal(head);
    return 0;
}
