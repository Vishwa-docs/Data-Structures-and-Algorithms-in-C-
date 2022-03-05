// Insertion Operations
void DLLInsertions(struct DLLNode **head, int data, int position){
	int k = 1;
	struct DLLNode *temp, *newNode;
	newNode = (struct DLLNode *) malloc (sizeof(struct DLLNode));

	if (!newNode){ // Always check for memory Errors
		printf("Memory Error");
		return;
	}

	newNode->data = data;

	// Insertion at Beginning
	if (position == 1){
		newNode->next = *head;
		newNode->prev = NULL

		if (*head)
			(*head)->prev = newNode;

		*head = newNode;
		return;
	}

	temp = *head;

	while ((k < position - 1) && (temp->next != NULL)){
		temp = temp->next;
		k++;
	}

	if (k != position){
		printf("Desired Position Does not exist\n");
	}

	newNode->next = temp->next;
	newode->prev = temp;

	if (temp->next)
		temp->next->prev = newNode;

	temp->next = newNode;
	return;
}

/**************** Individual Functions ****************/

// ToDo : Look at other variations and ways to insert

/**************** Function Call ****************/