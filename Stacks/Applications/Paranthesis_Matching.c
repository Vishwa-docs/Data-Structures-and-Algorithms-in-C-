// Also called Symbol Balancing

#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int size;
	int top;
	char *array;
};

int isEmpty(struct Stack *ptr){
	return ptr->top == -1;
}

int isFull(struct Stack *ptr){
	return ptr->top == ptr->size - 1;
}

void Push(struct Stack *ptr, char data){
	if(isFull(ptr)){
		printf("Stack Overflow");
	} else {
		ptr->top++;
		ptr->array[ptr->top] = data;
	}
}

char Pop(struct Stack *ptr){
	if (isEmpty(ptr)){
		printf("Stack Underflow");
		return -1;
	} else {
		char val = ptr->array[ptr->top];
		ptr->top--;
		return val;
	}
}

int Single_Paranthesis_Match(char * exp){
	struct Stack *sp;
	sp->size = 100;
	sp->top = -1;
	sp->array = (char *) malloc (sp->size * sizeof(char));

	for (int i = 0; exp[i] != '\0'; i++){
		if (exp[i] == '('){
			Push(sp, '(');
		} else if (exp[i] == ')'){
			if (isEmpty(sp)){
				return 0;
			}
			Pop(sp);
		}
	}

	if (isEmpty(sp)){
		return 1;
	} else {
		return 0;
	}
}

int match(char a, char b){
		if (a == '(' && b == ')'){
			return 1;
		}
		if (a == '[' && b == ']'){
			return 1;
		}
		if (a == '{' && b == '}'){
			return 1;
		}
		return 0;
}

int Multi_Paranthesis_Matching(char * exp){
	struct Stack *sp;
	sp->size = 100;
	sp->top = -1;
	sp->array = (char *) malloc (sp->size * sizeof(char));
	char popped_char;

	for (int i = 0; exp[i] != '\0'; i++){
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
			Push(sp, exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
			if (isEmpty(sp)){
				return 0;
			}
			popped_char = Pop(sp);
			if (!match(popped_char, exp[i])){
				return 0;
			}
		}
	}

	if (isEmpty(sp)){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	char * exp = "((5)(tkk-))";
	if (Single_Paranthesis_Match(exp)){
		printf("Paranthesis is mathcing");
	} else {
		printf("Paranthesis is not matching");
	}
	return 0;
}