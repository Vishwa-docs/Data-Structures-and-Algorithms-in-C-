#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int front, rear;
	int capacity;
	int *array;
};

struct Queue * Create_Queue(int size){
	struct Queue *Q = malloc (sizeof(struct Queue));
	if (!Q)
		return NULL;

	Q->capacity = size;
	Q->front = Q->rear = -1; // Initial
	Q->array = malloc (Q->capacity * sizeof(int));

	if (!Q->array)
		return NULL;

	return Q;
}

int isEmpty(struct Queue *Q){
	return (Q->front == -1 || Q->rear == Q->front);
}

int isFull (struct Queue *Q){
	return ((Q->rear + 1) % Q->capacity == Q->front);
}

int QueueSize(){
	return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void Enque(struct Queue *Q, int data){
	if (isFull(Q))
		printf("Queue Overflow\n");

	else {
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = data;
		if (Q->front == -1)
			Q->front = Q->rear;
	}
}


int Deque(struct Queue *Q){
	int data = 0;
	if (isEmpty(Q)){
		printf("Queue Underflow");
		return 0;
	} else {
		data = Q->array[Q->front];
		if (Q->front == Q->rear)
			Q->front = Q->rear = -1
		else Q->front = (Q->front + 1) % Q->capacity;
	}

	return data;
}

void DeleteQueue(struct Queue *Q){
	if(Q){
		if (Q->array)
			free(Q->array)
		free(Q)
	}
}