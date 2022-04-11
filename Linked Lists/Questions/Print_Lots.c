// Take 2 Linked List and print the elements from list 1 whose positions were in list 3

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next; // Self Referencial structure
};

void Print_Lots(struct Node * head, struct Node * head_1){
  struct Node * temp2 = head_1;

  while (temp2 != NULL){
    int num = temp2->data;
    struct Node * temp1 = head;
    for (int i = 0; i < num - 1 ; i++){
      temp1 = temp1->next;
    }
    printf("%d ", temp1->data);
    temp2 = temp2->next;
  }
}

int main(){
	struct Node *head;
	struct Node *second;
	struct Node *third;
	struct Node *fourth;

  struct Node *head_1;
	struct Node *second_1;


	head = (struct Node *) malloc (sizeof(struct Node));
	second = (struct Node *) malloc (sizeof(struct Node));
	third = (struct Node *) malloc (sizeof(struct Node));
	fourth = (struct Node *) malloc (sizeof(struct Node));

	head_1 = (struct Node *) malloc (sizeof(struct Node));
	second_1 = (struct Node *) malloc (sizeof(struct Node));

	head->data = 23;
	head->next = second;

	second->data = 5;
	second->next = third;

	third->data = 54;
	third->next = fourth;

	fourth->data = 32;
	fourth->next = NULL;

  head_1->data = 2;
  head_1->next = second_1;

  second_1->data = 3;
  second_1->next = NULL;

  Print_Lots(head, head_1);
  
	return 0;
}