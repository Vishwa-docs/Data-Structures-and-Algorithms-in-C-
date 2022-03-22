void InsertAtEndCLL (struct CLLNode **head, int data){
	struct CLLNode *current = *head;
	struct CLLNode *newNode = (struct CLLNode *) malloc (sizeof(struct CLLNode));

	if (!newNode){
		printf("Memory Error");
		return;
	}

	newNode->data = data;
	while (current->next != *head)
		current = current->next;

	newNode->next = newNode;

	if (*head == NULL)
		*head = newNode;

	else {
		newNode->next = *head;
		current->next = newNode;
	}
}

void InsertAtBeginningCLL (struct CLLNode **head, int data){
	struct CLLNode *current = *head;
	struct CLLNode *newNode = (struct CLLNode *) malloc (sizeof(struct CLLNode));

	if (!newNode){
		printf("Memory Error");
		return;
	}

	newNode->data = data;
	while (current->next != *head)
		current = current->next;

	newNode->next = newNode;

	if (*head == NULL)
		*head = newNode;

	else {
		newNode->next = *head;
		current->next = newNode;
		*head = newNode;
	}
}

