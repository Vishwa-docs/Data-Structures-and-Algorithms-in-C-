#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 100

struct Stack{
  int size;
  int top;
  int *array;
};

struct Stack * Create_Stack(){
  struct Stack *S = (struct Stack *) malloc (sizeof(struct Stack));
  if (!S)
    return NULL;

  S->size = MAXSIZE;
  S->top = -1;
  S->array = (int *) malloc (S->size * sizeof(int));
  return S;
}

int isEmpty(struct Stack *ptr){
  if (ptr->top == -1)
    return 1;
  else
    return 0;
}

void Push(struct Stack *S, char data){
    S->array[++S->top] = data;
}

char Pop(struct Stack *S){
  if (!isEmpty(S)){
    return S->array[S->top--];
  }
  return '|';
}

char Peek(struct Stack *S){
  return S->array[S->top];
}

int Postfix_Evaluation(char* exp){
  struct Stack* stack = Create_Stack();

  if (!stack)
    return -1;

  for (int i = 0; exp[i]; ++i){
    if (isdigit(exp[i])){
      Push(stack, exp[i] - '0');
    }

    else {
      int val1 = Pop(stack);
      int val2 = Pop(stack);

      switch (exp[i]){
        case '+':
            Push(stack, val2 + val1);
            break;
        case '-':
            Push(stack, val2 - val1);
            break;
        case '*':
            Push(stack, val2 * val1);
            break;
        case '/':
            Push(stack, val2 / val1);
            break;
      }
    }
  }

  return Pop(stack);
}


int main(){
  char exp[] = "231*+9-";
  printf("%d", Postfix_Evaluation(exp));
  return 0;
}