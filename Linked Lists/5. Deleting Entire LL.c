void DeleteLL(struct Node **head){
	struct Node *auxilaryNode, *iterator;
	iterator = *head;

	while (iterator) { // iterator != NULL
		auxilaryNode = iterator -> next;
		free(iterator);
		iterator = auxilaryNode;
	}

	*head = NULL;  // To affect the real head back in the function call
}