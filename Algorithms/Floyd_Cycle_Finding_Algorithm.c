/* 
Efficient Memoryless Approach 
It used two pointers at differnet speeds. if there is a loop, they will meet and we can know if there is a loop
The slow and fast pointers move one and two pointers at a time respectively
*/


// Time Complexity : O(n), Space Complexity O(1)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int Floyd_Loop(struct Node *head){
  struct Node *slow_ptr = head;
  struct Node *fast_ptr = head;

  // != NULL
  while (slow_ptr && fast_ptr && fast_ptr->next){
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;

    if (slow_ptr == fast_ptr)
      return 1;
  }
  return 0;
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
    sixth->next = NULL;

    if (Floyd_Loop(head))
        printf("There is a loop in the Linked List");
    else
        printf("There is no loop in the Linked List");
    return 0;
}