#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


///////////////////////////////////
int isOperand(char ch){
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Precedence(char ch){
  switch(ch){
    case '+':
      return 1;
    case '-':
      return 1;

    case '*':
      return 2;
    case '/':
      return 2;

    case '^':
      return 3;
  }
  return -1;
}


int infix_to_postfix(char* exp){
  struct Stack* stack = Create_Stack();
  int k, i;

  if (!stack)
    return -1;

  for (i = 0, k = -1; exp[i]; ++i){
    // If the scanned character is an operand, add to output
    if (isOperand(exp[i])){
      exp[++k] = exp[i];
    }

    // If '(' push to stack
    else if (exp[i] == '('){
      Push(stack, exp[i]);
    }

    // If ')' then pop until ( is reached
    else if (exp[i] == ')'){
      while (!isEmpty(stack) && Peek(stack) != '('){
        exp[++k] = Pop(stack);
      }
      if (!isEmpty(stack) && Peek(stack) != '(') {
        return -1;
      }
      else
        Pop(stack);
    }

    // Operator is encountered
    else {
      while (!isEmpty(stack) && (Precedence(exp[i]) <= Precedence(Peek(stack)))){
        exp[++k] = Pop(stack);
      }
      Push(stack, exp[i]);
    }
  }

  while (!isEmpty(stack)){
    exp[++k] = Pop(stack);
  }

  exp[++k] = '\0';
  printf("%s",exp);

  return 0;
}


int main(){
  char exp[] = "b*g(u+v-i)/x^t";
  infix_to_postfix(exp);
  
  return 0;
}