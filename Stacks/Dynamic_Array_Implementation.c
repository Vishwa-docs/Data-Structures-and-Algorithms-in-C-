#include <stdio.h>
#include <stdlib.h>

#define INT_MIN -2;

struct Stack{
	int capacity;
	int top;
	int *array;
};

struct Stack * Create_Stack(){
	struct Stack *S = (struct Stack *) malloc (sizeof(struct Stack));
	if (!S)
		return NULL;

	S->capacity = 1;
	S->top = -1;
	S->array = (int *) malloc (S->size * sizeof(int));
	if (!S->array)
		return NULL;
	return S;
}

int isFull(struct Stack *S){
	return S->top == S->capacity - 1;
}

void Double_Stack(struct Stack *S){
	S->capacity *= 2;
	S->array = realloc(S->array, S->capacity * sizeof(int)); // Realloc attempts to reallocate the memory with the new size
}

void Push(struct Stack *S, int data){
	if (isFull(S))
		Double_Stack(S);
	S->array[++S->top] = data;
}

int isEmpty(struct Stack *S){
	return S->top == -1;
}

int Stack_Top(struct Stack *S){
	if (isEmpty(S))
		return INT_MIN;
	return S->array[S->top];
}

int Pop(struct Stack *S){
	if (isEmpty(S))
		return INT_MIN;

	return S->array[S->top--];
}


void Delete_Stack(struct Stack *s){
	if (S){
		if(S->array)
			free(S->array)
		free(S);
	}
}