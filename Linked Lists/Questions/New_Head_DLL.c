#include <stdio.h>
#include <stdlib.h>

struct DLLNode{
	int data;
	struct DLLNode *next;
	struct DLLNode *prev;
};

void DLL_Forward_Traversal(struct DLLNode *head){
	struct DLLNode *ptr = head;
	int count = 0;

	while (ptr != NULL){
		count++;
		printf("Element: %d\n", ptr->data);
		ptr = ptr->next;
	}
	return;
}

struct DLLNode * vv(struct DLLNode *head, int n){
  struct DLLNode *temp = head;
  struct DLLNode *temp1 = head;

  for(int i=1;i<n;i++)
	  temp=temp->next;
  temp1=temp->prev;
  // temp1=temp->prev;
  temp->prev=NULL;
  head->prev = temp;
  temp1->next=temp->next;
  temp->next=head;
  temp=temp1->next;
  temp->prev=temp1;
  head = head->prev;
  return head;
}

int main(){
	struct DLLNode *head; // Struct pointer, NOT instance
	struct DLLNode *second;
	struct DLLNode *third;
	struct DLLNode *fourth;
	struct DLLNode *fifth;
	struct DLLNode *sixth;

	// Allocate memory for the nodes in LL in Heap
	head = (struct DLLNode *) malloc (sizeof(struct DLLNode));
	second = (struct DLLNode *) malloc (sizeof(struct DLLNode));
	third = (struct DLLNode *) malloc (sizeof(struct DLLNode));
	fourth = (struct DLLNode *) malloc (sizeof(struct DLLNode));
	fifth = (struct DLLNode *) malloc (sizeof(struct DLLNode));
	sixth = (struct DLLNode *) malloc (sizeof(struct DLLNode));

	// Linking on Nodes
	head->data = 23;
	head->next = second;
	head->prev = NULL;

	second->data = 5;
	second->next = third;
	second->prev = head;

	third->data = 54;
	third->next = fourth;
	third->prev = second;

	fourth->data = 32;
	fourth->next = fifth;
	fourth->prev = third;

	fifth->data = 90;
	fifth->next = sixth;
	fifth->prev = fourth;

	sixth->data = 11;
	sixth->next = NULL;
	sixth->prev = fifth;

	DLL_Forward_Traversal(head);
  printf("\n");

  head = vv(head, 3);
  DLL_Forward_Traversal(head);
  
	return 0;
}