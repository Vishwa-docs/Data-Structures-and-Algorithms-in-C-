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




/***********   Alternative   ***********/
struct Node *front = NULL;
struct Node *rear = NULL;

struct Node{
	int data;
	struct Node *next;
};

void Enqueue(int data){
	struct Node *newNode = (struct Node *) malloc (sizeof(struct Node));
	if (newNode == NULL){
		printf("Queue Overflow\n");
	} else {
		newNode->data = data;
		newNode->next = NULL;

		if (front == NULL){
			front = rear = newNode;
		} else {
			rear->next = newNode;
			rear = newNode;
		}
	}
}


int Dequeue(){
	int val;
	struct Node *ptr = front;
	if (front == NULL){
		printf("Queue Underflow\n");
	} else {
		front = front->next;
		val = ptr->data;
		free(ptr);
	}
	return val;
}