// Insertion Operations
void Insertions(struct Node **head, int data, int position){
	int k = 1;
	struct Node *p, *q, *newNode;
	newNode = (struct Node *) malloc (sizeof(struct Node));

	if (!newNode){
		printf("Memory Error");
		return;
	}

	newNode->data = data;
	p = *head;

	// Insertion at Beginning
	if (position == 1){
		newNode->next = p;
		*head = newNode;
	}

	else {
		// Traverse until the position you want to insert
		while ((p != NULL) && (k < position)){
			k++;
			q = p;
			p = p->next;
		}
		q->next = newNode; // More optimal way to do it
		newNode->next = p;
	}
}

/**************** Individual Functions ****************/

// Insertion at the Beginning
struct Node * InsertAtFirst (struct Node *head, int data){
	struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
	ptr->data = data;
	ptr->data = head;
	return ptr; // New Head
}


// Insertion at Index 
struct Node * InsertAtIndex (struct Node *head, int data, int index){
	struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
	struct Node *p = head;
	int i = 0;

	while (i != index - 1)	{
		p = p->next;
		i++;
	}

	ptr->data = data;
	ptr->next = p->next;
	p->next = ptr;

	return head;
}

// Insertion at end
struct Node * InsertAtEnd (struct Node *head, int data){
	struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
	ptr->data = data;
	struct Node *p = head;

	while (p->next != NULL){
		p = p->next;
	}

	p->next = ptr;
	ptr->next = NULL;

	return head;
}

// Insert after Node
struct Node * InsertAtEnd (struct Node *head, struct Node *prevNode, int data){
	struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
	ptr->data = data;

	ptr->next = prevNode->next;	
	prevNode->next = ptr;

	return head;
}


/**************** Function Calls ****************/
head = InsertAtFirst(head, 23);