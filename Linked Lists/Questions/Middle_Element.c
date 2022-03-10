// To Print the Middle Element in a linked list

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

// To find the number of nodes
int count (struct Node *head){
    struct Node *current = head;
    int val = 0;

    while (current != NULL){
        val++;
        current = current->next;
    }
    return val;
};

void Print_Middle_element(struct Node *head){
    int n = count(head);
    struct Node *current = head;

    if (n%2 != 0) {
        for (int i = 1; i < 2 * (n / 2) - 1; i++) {
            current = current->next;
        }
        printf("Middle Element: %d\n", current->data);
    } else if (n%2 == 0){
        for (int i = 1; i < (n / 2); i++){
            current = current->next;
        }
        printf("Middle Elements are: %d and %d\n", current->data, current->next->data);
    }

    return;
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


    LLTraversal(head);
    Print_Middle_element(head);
    return 0;
}