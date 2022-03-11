// To Find the length of the cycle

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int Length_Of_Loop(struct Node *head){
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

  int count = 0;

  if (loopExists){
    slow_ptr = head;
    while (slow_ptr != fast_ptr){
      slow_ptr = slow_ptr->next;
      fast_ptr = fast_ptr->next;
    }
    
    do {
      count++;
      fast_ptr = fast_ptr->next;
    } while (fast_ptr != slow_ptr);

    return count;
  }

  else {return -1;}

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

    int ans = Length_Of_Loop(head);

    if (ans == -1){
      printf("Loop does not exist");
    } else {
       printf("Length of Loop : %d", ans);
    }

    return 0;
}