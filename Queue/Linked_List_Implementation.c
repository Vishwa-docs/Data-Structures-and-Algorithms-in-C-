#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Queue{
	struct Node *front;
	struct Node *back;
};

struct Queue * Create_Queue(){
	struct Queue *Q;
	struct Node *temp;

	Q = malloc (sizeof(struct Queue));
	if (!Q)
		return NULL

	temp = malloc(sizeof(struct Node));
	Q->front = Q->rear = NULL;
	return Q;
}

int isEmpty(struct Queue *Q){
	return (Q->front == NULL);
}

void Enque(struct Queue *Q, int data){
	struct Node *newNode;
	newNode = malloc(sizeof(struct Node));

	if (!newNode)
		return;

	newNode->data = data;
	newNode->next = NULL;

	if (Q->rear)
		Q->rear->next = newNode;

	Q->rear = newNode;

	if (Q->front == NULL)
		Q->front = Q->rear;
}


int Deque(struct Queue *Q){
	int data = 0;
	struct Node *temp;

	if (isEmpty(Q)){
		printf("Queue Underflow");
		return -1; // Create number to return
	} else {
		temp = Q->front;
		data = Q->front->data;
		Q->front = Q->front->next;
		free(temp);
	}

	return data;
}


void Delete_Queue(struct Queue *Q){
	struct Node *temp;
	while(Q){
		temp = Q;
		Q = Q->ext;
		free(temp);
	}
	free(Q);
}