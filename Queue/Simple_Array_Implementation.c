#include <stdio.h>
#include <stdlib.h>

 struct Queue{
	int size;
	int front;
	int rear;
	int *array;
};

typedef struct Queue Queue;

void Display_Queue(Queue *q){
  if (q->front == q->rear){
    printf("Queue is Empty\n");
    return;
  }

  for (int i = q->front; i < q->rear; i++){
    printf("%d ", q->array[i]);
  }
  printf("\n");
  return;
}

int isEmpty(Queue *q){
	if (q->rear == q->front)
		return 1;
	return 0;
}

int isFull(Queue *q){
	if (q->rear == q->size-1)
		return 1;
	return 0;
}

void EnQueue(Queue *q, int data){
	if (isFull(q)){
		printf("Queue Overflow\n");
		return;
	} else {
		q->array[q->rear++] = data;
	}
}

int DeQueue(Queue *q){
	int x;
	if (isEmpty(q)){
		printf("Queue Underflow\n");
	} else {
		x = q->array[q->front++];
	}
	return x;
}

int main(){
	// Can also use pointer

	Queue q;
	q.size = 10;
	q.front = q.rear = 0;
	q.array = (int *) malloc (q.size * sizeof(int));

	EnQueue(&q, 34);
	EnQueue(&q, 2);
	EnQueue(&q, 76);
  EnQueue(&q, 89);

  Display_Queue(&q);
	printf("Dequeueing Element : %d\n", DeQueue(&q));
	printf("Dequeueing Element : %d\n", DeQueue(&q));
  printf("\n");
  Display_Queue(&q);
	return 0;
}