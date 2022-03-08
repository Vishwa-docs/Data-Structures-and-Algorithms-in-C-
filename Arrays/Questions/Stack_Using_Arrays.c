#include <stdio.h>
#include <stdlib.h>

struct stack{
  int size;
  int top;
  int *arr;
};


int isEmpty(struct stack *ptr){
  if (ptr->top == -1)
    return 1;
  else
    return 0;
}

int isFull(struct stack *ptr){
  if (ptr->top == ptr->size -1)
    return 1;
  else
    return 0;
}

void push(struct stack *ptr, int val){
  if (isFull(ptr))
    printf("Stack Overflow, cannot be pushed\n");
  else {
    ptr->top++;
    ptr->arr[ptr->top] = val;
  }

  return;
}

int pop(struct stack *ptr){
  if(isEmpty(ptr)){
    printf("Stack Underflow, cannot be popped");
    return -1;
  }
  else {
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
  }
}

int peek(struct stack *ptr){
  return ptr->arr[ptr->top];
}

int search(struct stack *ptr, int ind){
  int arrayInd = ptr->top - ind + 1;
  if (arrayInd
     < 0){
    printf("Not a valid position for the stack\n");
    return -1;
     }

  else {
    return ptr->arr[arrayInd];
  }
}

void display (struct stack *ptr){
  for (int j = 0; j <= ptr->top + 1; j++){
    printf("The value at position %d is %d\n", j, search(ptr, j));
  }
}

int main(void){
  struct stack *s; // Stack pointers
  s->size = 100;
  s->top = -1;
  s->arr = (int *)malloc(size-> * sizeof(int));
/*
Other Method :
struct stack s;
s.size = 100;
s.top = -1;
s.arr = (int *) malloc (s.size * sizeof(int));
*/

  // Manually Pusing elements : 
  s->arr[0] = 8;
  s->top++;

  s->arr[1] = 15;
  s->top++;

  s->arr[2] = 34;
  s->top++;

  s->arr[3] = 46;
  s->top++;

  // Checking : 

  if (isEmpty(s))
    printf("Stack is empty");
  else if (isFull(s))
    printf("Stack is Full");
  else
    printf("Elements are now entered");
  return 0;
}