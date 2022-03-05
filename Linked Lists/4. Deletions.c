void Deletion(struct Node **head, int position){
	int k = 1;
	struct Node *p, *q;

	// Condition for Empty
	if (*head == NULL){
		printf("List Empty");
		return;
	}

	p = *head;

	// Delete from beginning
	if (position == 1){
		*head = p->next;
		free(p);
		return;
	} else {
		// Traverse ubntil the position we want to delete
		while ((p != NULL) && (k < position)){
			k++;
			q = p;
			p = p->next;
		}

		if (p == NULL) // At the end
			printf("Position does not exist")
		else // From the Middle
			q->next = p->next;
			free(p);
	}
}

/**************** Individual Functions ****************/

// Deletion at the Beginning 
struct Node * DeleteAtBeginning(struct Node * head){
	struct Node *p = head;
	head = head->next;
	free(ptr);

	return head;
}

// Deletion at the Index 
struct Node * DeleteAtIndex(struct Node * head, int index){
	struct Node *p = head;
	struct Node *q = head->next;

	for (int i = 0; i < index - 1; i++){
		p = p->next;
		q = q->next;
	}

	p->next = q->next;
	free(q);
	
	return head;
}

// Deletion at the End 
struct Node * DeleteAtEnd(struct Node * head){
	struct Node *p = head;
	struct Node *q = head->next;

	while (q->next != NULL){
		p = p->next;
		q = q->next;
	}

	p->next = NULL;
	free(q);
	
	return head;
}


// Deletion at the Given Value (First Occurance)
struct Node * DeleteAtValue(struct Node * head, int value){
	struct Node *p = head;
	struct Node *q = head->next;

	while (q->data != value && q->next != NULL){
		p = p->next;
		q = q->next;
	}

	if (q->data == value){
		p->next = q->next;
		free(q);
	}
	
	return head;
}

/**************** Function Calls ****************/
head = DeleteAtValue(head, 23);