// Q. Functions to delete the smallest and Largest element in a Linked List

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

struct Node * delete_smallest(struct Node *head) {
    struct Node *current = head;
    struct Node *small_ptr = head;
    struct Node *prev = NULL;


    while (current != NULL) {
        if ((current->next != NULL) && (current->next->data < small_ptr->data)) {
            small_ptr = current->next;
            prev = current;
        }
        current = current->next;
    }

    // If the first element is smallest, update head else don't
    small_ptr != head ? (prev->next = small_ptr->next) : (head = head->next);
    return head;
}

struct Node * delete_largest(struct Node *head) {
    struct Node *current = head;
    struct Node *large_ptr = head;
    struct Node *prev = NULL;


    while (current != NULL) {
        if ((current->next != NULL) && (current->next->data > large_ptr->data)) {
            large_ptr = current->next;
            prev = current;
        }
        current = current->next;
    }

    // If the first element is smallest, update head else don't
    large_ptr != head ? (prev->next = large_ptr->next) : (head = head->next);
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

    head->data = 23;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 54;
    third->next = fourth;

    fourth->data = 32;
    fourth->next = NULL;

    LLTraversal(head);
    head = delete_smallest(head);
    printf("\n");
    LLTraversal(head);
    return 0;
}