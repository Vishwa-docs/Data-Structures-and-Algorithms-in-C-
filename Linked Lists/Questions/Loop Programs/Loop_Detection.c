// https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

/************ Modified Linked List Method ************/

// Time Complec=xity is O(n) as we need only one iteration and Space Complexity is O(1)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    int flag;
};

int check_loop(struct Node *head) {
    struct Node *current = head;
    // If there is no cycle, then there will be a NULL pointer ending
    while (current != NULL) {
        // If we detect that the node has already been traversed, it means there is a cycle
        if (current->flag == 1)
            return 1;

        // If we are seeing the node for the first time, then we set its flag as 1
        current->flag = 1;
        current = current->next;
    }
    // If there is no Cycle
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
    head->flag = 0;

    second->data = 5;
    second->next = third;
    second->flag = 0;

    third->data = 54;
    third->next = fourth;
    third->flag = 0;

    fourth->data = 32;
    fourth->next = fifth;
    fourth->flag = 0;

    fifth->data = 76;
    fifth->next = sixth;
    fifth->flag = 0;

    sixth->data = 80;
    sixth->next = second;
    sixth->flag = 0;

    // LLTraversal(head);
    if (check_loop(head) == 1)
        printf("There is a loop in the Linked List");
    else
        printf("There is no loop in the Linked List");
    return 0;
}



/************ Floyd Cycle Finding Algorithm ************/
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