// Q. To Swap the kth nodes from the beginning and the end


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

void kth_Node_Swap (struct Node *head, int k){
    int n = count(head);

    // If k is valid
    if ( n < k )
        return;

    // If kth node from beginning and end are the same
    if (2 * k - 1 == n)
        return;

    struct Node *k_from_front = head;
    struct Node *k_from_front_prev = NULL;

    // Getting the kth node from the beginning
    for (int i = 0; i < k-1; i++){
        k_from_front_prev = k_from_front;
        k_from_front = k_from_front->next;
    }

    // Kth node from the end is n - k + 1 node from the front
    struct Node *k_from_back = head;
    struct Node *k_from_back_prev = NULL;

    for (int i = 1; i < n - k + 1; i++){
        k_from_back_prev = k_from_back;
        k_from_back = k_from_back->next;
    }

    // Swapping the Pointers of the previous elements
    if (k_from_front_prev)
        k_from_front_prev->next = k_from_back;

    if (k_from_back_prev)
        k_from_back_prev->next = k_from_front;

    // Swap the Next pointers ot k_from_front and k_from_back
    struct Node *temp = k_from_front->next;
    k_from_front->next = k_from_back->next;
    k_from_back->next = temp;

    /*
    If k is 1 or n, then change the head pointers
    Use double pointer in the function parameter and change head above to *head, then
        if (k == 1)
            *head = k_from_back;
        if (k == n)
            *head = k_from_front;
    */

    return;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *) malloc (sizeof(struct Node));
    second = (struct Node *) malloc (sizeof(struct Node));
    third = (struct Node *) malloc (sizeof(struct Node));
    fourth = (struct Node *) malloc (sizeof(struct Node));
    fifth = (struct Node *) malloc (sizeof(struct Node));

    head->data = 23;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 54;
    third->next = fourth;

    fourth->data = 32;
    fourth->next = fifth;

    fifth->data = 12;
    fifth->next = NULL;

    LLTraversal(head);
    kth_Node_Swap(head, 2);
    printf("\n");
    LLTraversal(head);
    return 0;
}