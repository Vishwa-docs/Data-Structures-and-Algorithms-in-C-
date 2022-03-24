void Inject(struct Node **head, int data){
	struct Node *newNode = (struct Node *) malloc (sizeof(struct Node));
	newNode->data = data;
	if (*head == NULL){
		*head = newNode;
		(*head)->next = *head;
		(*head)->prev = *head;
	} else {
		newNode->prev = (*head)->prev;
		newNode->next = *head;
		(*head)->prev->next = newNode;
		(*head)->perv = newNode;
	}
}

void Push(struct Node **head, int data){
	Inject(head, data);
	*head = (*head)->prev;
}

int Eject(struct Node **head){
	int data;
	if((*head)->prev == *head){
		data = (*head)->data;
		free(*head);
		*head = NULL;
	} else {
		struct Node *newTail = (*head)->prev->prev;
		data = (*head)->prev->data;
		newTail->next = *head;
		free((*head)->prev);
		(*head)->prev = newTail;
	}
	return data;
}


int Pop(struct Node **head){
	int data;
	*head = (*head)->next;
	data = Eject(head);
	return data;
}

/*
Inject : push from back 
Eject : Pop from back
*/