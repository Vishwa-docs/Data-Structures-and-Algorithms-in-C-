#include <stdio.h>
#include <stdlib.h>

#define INT_MIN -2;

struct Stack{
	int size;
	int top;
	int *array;
};

struct Node{
	int data;
	struct Node * next;
};

void Display(struct Node *ptr){
	while (ptr != NULL){
		printf("Element : %d\n", ptr->data);
		ptr = ptr->next;
	}
}

/*
struct Stack * Create_Stack(){
	return NULL;
} 
*/

// Is Full can be checked
void Push(struct Stack **top, int data){
	struct Stack *temp;
	temp = (struct Stack *)malloc(sizeof(struct Stack));
	if (!temp)
		return NULL

	temp->data = data;
	temp->next = *top;
	*top = temp;
}

int isEmpty(struct Stack *top){
	return top == NULL;
}

// Redundant Operation
int isFull(struct Stack *top){
	struct Node *p = (struct Node *) malloc (sizeof(struct Node));
	return p == NULL;
}

int Pop(struct Stack **top){
	int data;
	struct Stack *temp;
	if(isEmpty(S))
		return INT_MIN;

	temp = *top;
	*top = *top->next;
	data = temp->data;

	free(temp);
	return data;
}

int Stack_Top(struct Stack *S){
	if(isEmpty(S))
		return INT_MIN;
	return S->next->data;
}
// Stack Bottom can also be implemented

int Peek(int pos){ // See if you can add default Parameters
	struct Node *ptr = top;
	for (int i = 0; (i < pos - 1 && ptr != NULL); i++){
		ptr = ptr->next;
	}
	if (ptr != NULL){
		return ptr->data;
	} else {
		return -1;
	}
}

void Delete_Stack(struct Stack **top){
	struct Stack *temp, *p;
	p = *top;
	while(p->next){
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
	free(p);
}

int main(){
	return 0;
}