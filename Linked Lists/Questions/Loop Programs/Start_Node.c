// Objective : To Find the starting Node of a cycle in a Linked List

/*
After finding the loop, we initialize the slow_ptr to head of linked list and make the slow and fast ptr move only one step at a time
The point they meet is at the start of the loop
*/

/*
Program Analysis : 
Time Complexity : O(n) and Space complexity : O(1)

Why Do they meet at the beginning of the loop?
Solved using Number Theory
The slow and fast pointer will meet when they are n x L (L is loop length)
The slow ptr is at the midpoint between the fast and the beginning of sequence because of how they move
So, the slow ptr is always n x L away from the beginning as well
If we move one step at a time, they will meet exacty when the loop starts (Since they are n x L : a multiple of loop length apart)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node * Beginning_of_Loop(struct Node *head){
  struct Node *slow_ptr = head;
  struct Node *fast_ptr = head;
  int loopExists = 0;

  // != NULL
  while (slow_ptr && fast_ptr && fast_ptr->next){
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;

    if (slow_ptr == fast_ptr){
    	loopExists = 1;
    	break;
    }
  }

  if (loopExists){
  	slow_ptr = head;
  	while (slow_ptr != fast_ptr){
	    slow_ptr = slow_ptr->next;
	    fast_ptr = fast_ptr->next;
  	}
  	return slow_ptr;
  } else {
    return NULL;
  }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;

    head = (struct Node *) malloc (sizeof(struct Node));
    second = (struct Node *) malloc (sizeof(struct Node));
    third = (struct Node *) malloc (sizeof(struct Node));
    fourth = (struct Node *) malloc (sizeof(struct Node));
    fifth = (struct Node *) malloc (sizeof(struct Node));
    sixth = (struct Node *) malloc (sizeof(struct Node));

    head->data = 23;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 54;
    third->next = fourth;

    fourth->data = 32;
    fourth->next = fifth;

    fifth->data = 76;
    fifth->next = sixth;

    sixth->data = 80;
    sixth->next = third;

    struct Node * ans = Beginning_of_Loop(head);

    if (ans != NULL){
      printf("Loop Begins at : %d", ans->data);
    } else {
      printf("Loop does not Exist");
    }
    return 0;
}