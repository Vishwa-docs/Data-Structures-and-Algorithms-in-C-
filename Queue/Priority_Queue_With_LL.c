#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    // Lower values indicate higher priority
    int priority;
    struct Node *next;
};

void Display(struct Node *head){
    struct Node *current = head;
    if (head == NULL)
        return;
    do {
        printf("Element :  %d\n", current->data);
        current = current->next;
    } while (current != head);

  printf("\n");
}

/*
void Create(struct Node **head, int n){
    struct Node *temp, *rear;
    int count = 1;

    for (int i = 0; i < n ; i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = count;
        temp->next = NULL;
        if (*head == NULL){
            *head = temp;
        } else {
            rear->next = temp;
        }
        rear = temp;
        count++;
    }
    rear->next = NULL;
}
*/

int Peek(struct Node **head){
    return (*head)->data;
}

// Remove element with highest priority
void Pop(struct Node **head){
    struct Node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void Push(struct Node **head, int data, int priority){
    struct Node *traverse = *head;

    // Create New Node
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;

    // Change head node if head < newNode
    if ((*head)->priority > priority){
        temp->next = *head;
        *head = temp;
    } else {
        // Find Node
        while (traverse->next != NULL && traverse->next->priority < priority){
            traverse = traverse->next;
        }

        temp->next = traverse->next;
        traverse->next = temp;
    }
}

int isEmpty(struct Node **head){
    return ((*head) == NULL);
}

int main(){

int main(){
    struct Node *head;
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

    while (!isEmpty(&head)){
        printf("%d ", Peek(&head));
        Pop(&head);
    }
    return 0;
}