#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next; // Self Referencial structure
};

// LinkedList Traversal
void LLTraversal(struct Node *head){
	struct Node *current = head;
	int count = 0;

	while (current != NULL){
		count++; // Number of elements
		printf("Element %d\n", current->data); // Element data
		current = current->next; // Go to next element
	}
	return;
}

// Insertion Operations
void Insertions(struct Node **head, int data, int position){
	int k = 1;
	struct Node *p, *q, *newNode;
	newNode = (struct Node *) malloc (sizeof(struct Node));

	if (!newNode){
		printf("Memory Error");
		return;
	}

	newNode->data = data;
	p = *head;

	// Insertion at Beginning
	if (position == 1){
		newNode->next = p;
		*head = newNode;
	}

	else {
		// Traverse until the position you want to insert
		while ((p != NULL) && (k < position)){
			k++;
			q = p;
			p = p->next;
		}
		q->next = newNode; // More optimal way to do it
		newNode->next = p;
	}
}

void Deletion(struct Node **head, int position){
	int k = 1;
	struct Node *p, *q;

	if (*head == NULL){
		printf("List Empty");
		return;
	}

	p = *head;

	// Delete from beginning
	if (position == 1){
		*head = p->next;
		free(p);
		return;
	} else {
		// Traverse ubntil the position we want to delete
		while ((p != NULL) && (k < position)){
			k++;
			q = p;
			p = p->next;
		}

		if (p == NULL){ // At the end
			printf("Position does not exist");
		}
		else{ // From the Middle
			q->next = p->next;
			free(p);
		}
	}
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