#include <stdio.h>
#include <stdlib.h>

struct Node {
  int coeff;
  int power;
  struct Node * next;
};

// Creating a new node : 
void Create_Node(int x, int y, struct Node **temp){
  struct Node *r, *z;
  z = *temp;
  if (z == NULL){
    r = (struct Node *)malloc(sizeof(struct Node));
    r->coeff = x;
    r->power = y;
    *temp = r;
    r->next = (struct Node *)malloc(sizeof(struct Node));
    r = r->next;
    r->next = NULL;
  } else {
    r->coeff = x;
    r->power = y;
    r->next = (struct Node *)malloc(sizeof(struct Node));
    r = r->next;
    r->next = NULL;
  }
}

void Poly_Add (struct Node * poly1, struct Node * poly2, struct Node * poly){
  while (poly1->next && poly2->next) {
    // If power of 1st polynomial is greater then 2nd, then store 1st as it is and move its pointer
    if (poly1->power > poly2->power) {
      poly->power = poly1->power;
      poly->coeff = poly1->coeff;
      poly1 = poly1->next;
    }

    else if (poly1->power < poly2->power){
      poly->power = poly2->power;
      poly->coeff = poly2->coeff;
      poly2 = poly2->next;
    }

    // If powers are the same then add the coefficient

    else {
      poly->power = poly1->power;
      poly->coeff = poly1->coeff + poly2->coeff;
      poly1 = poly1->next;
      poly2 = poly2->next;
    }

    // Create a new node 
    poly->next = (struct Node *)malloc(sizeof (struct Node));
    poly = poly->next;
    poly->next = NULL;
}

    while (poly1->next || poly2->next) {
        if (poly1->next) {
            poly->power = poly1->power;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) {
            poly->power = poly2->power;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next
            = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

void Traversal(struct Node * temp){
  while (temp->next != NULL) {
    printf("%dx^%d", temp->coeff, temp->power);
    temp = temp->next;

    if (temp->coeff >= 0){
      if (temp->next != NULL){
        printf("+");
      }
    }
  }
}


int main(){
  // Poly 1 : 4x^3 + 16x^2 + 3x + 9
  // Poly 2 : 5x^4 + 4x^2 + 2x + 1
  
  struct Node *head_1;
  struct Node *second_1;
  struct Node *third_1;
  struct Node *fourth_1;

  struct Node *head_2;
  struct Node *second_2;
  struct Node *third_2;
  struct Node *fourth_2;

  struct Node *poly;
  poly = (struct Node *) malloc (sizeof(struct Node));

    // Allocate memory for the nodes in LL in Heap
    head_1 = (struct Node *) malloc (sizeof(struct Node));
    second_1 = (struct Node *) malloc (sizeof(struct Node));
    third_1 = (struct Node *) malloc (sizeof(struct Node));
    fourth_1 = (struct Node *) malloc (sizeof(struct Node));

    head_2 = (struct Node *) malloc (sizeof(struct Node));
    second_2 = (struct Node *) malloc (sizeof(struct Node));
    third_2 = (struct Node *) malloc (sizeof(struct Node));
    fourth_2 = (struct Node *) malloc (sizeof(struct Node));

    // Linking on Nodes
    head_1->coeff = 4;
    head_1->power = 3;
    head_1->next = second_1;

    second_1->coeff = 16;
    second_1->power = 2;
    second_1->next = third_1;

    third_1->coeff = 3;
    third_1->power = 1;
    third_1->next = fourth_1;

    fourth_1->coeff = 9;
    fourth_1->power = 0;
    fourth_1->next = NULL;

    head_2->coeff = 5;
    head_2->power = 4;
    head_2->next = second_2;

    second_2->coeff = 4;
    second_2->power = 2;
    second_2->next = third_2;

    third_2->coeff = 2;
    third_2->power = 1;
    third_2->next = fourth_2;

    fourth_2->coeff = 1;
    fourth_2->power = 0;
    fourth_2->next = NULL;


  Traversal(head_1);
  printf("\n");
  Traversal(head_2);

  printf("\n");
  Poly_Add(head_1, head_2, poly);
  Traversal(poly);
  
  return 0;
}