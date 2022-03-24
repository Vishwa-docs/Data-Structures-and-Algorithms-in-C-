#include <stdio.h>
#include <stdlib.h>

struct CLLNode {
    int data;
    struct CLLNode *next;
};

void Display(struct CLLNode *head){
    struct CLLNode *current = head;
    if (head == NULL)
        return;
    do {
        printf("Element :  %d\n", current->data);
        current = current->next;
    } while (current != head);

  printf("\n");
}

void Create(struct CLLNode **head, int n){
    struct CLLNode *temp, *rear;
    int count = 1;

    for (int i = 0; i < n ; i++){
        temp = (struct CLLNode *)malloc(sizeof(struct CLLNode));
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
    rear->next = *head;
}


int survivor(struct CLLNode **head, int k){
    struct CLLNode *p, *q;
    int i;
 
    q = p = *head;
    while (p->next != p){
        for (i = 0; i < k - 1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%d has been killed.\n", p->data);
        free(p);
        p = q->next;
    }
    *head = p;

    return (p->data);
}

int main(){
  struct CLLNode *head = NULL;
  Create(&head, 7);
  Display(head);
  printf("\n");
  survivor(&head, 3);
  return 0;
}