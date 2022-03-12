#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct Stack{
	int capacity;
	int top;
	int *array;
}

struct Stack * Create_Stack(){
	struct Stack *S = (struct Stack *) malloc (sizeof(struct Stack));
	if (!S)
		return NULL

	S->capacity = MAXSIZE;
	S->top = -1;
	S->array = (int *) malloc (S->capacity * sizeof(int));
	if (!S->array)
		return NULL;
	return S;
}

int isEmpty(struct Stack *ptr){
	if (ptr->top == -1)
		return 1;
	else
		return 0;
	// return (S->top = -1) // If it is true then return 1 else return 0
}

int isFull(struct Stack *ptr){
	if (ptr->top == ptr->size - 1)
		return 1;
	else
		return 0;
	// return (S->top == S->capacity - 1)
}

void Push(struct Stack *S, int data){
	if(isFull(S)){
		printf("Stack Overflow");
		return;
	}
	else {
		// Increasing the top by 1 and storing the value at the 'top' position
		S->array[++S->top] = data;
		return;
	}
}

void Pop(struct Stack *S){
	if (isEmpty(S)){
		printf("Stack Underflow");
		return;
	}
	else{
		// Remove Element from top and reduce top by 1
		S->array[S->top--];
		// Can be returned as well
		return;
	}
}

int Peek(struct Stack *S){
	return S->top;
}


int main(){
	struct Stack *S = Create_Stack():
	/*
	Or can be
	struct Stack S;
	S.capacity = 100;
	S.top = -1

	// Pointer to the Array where elements are stored
	S.array = (int *) malloc (S.capacity * sizeof(int));
	*/

	// Pushing Elements Manually
	S->array[0] = 9;
	S->top++;

	// To Check if stack is empty
	if (isEmpty(S))
		printf("The Stack is empty");
	else
		printf("The Stack is not empty");
	return 0;
}