void DeleteFromLast (struct CLLNode **head){
	struct CLLNode *temp = *head, *current;
	*current = *head;

	if (*head == NULL){
		printf("List is empty");
		return;
	}

	while (current -> next != *head){
		temp = current;
		current = current->next;
	}

	temp->next = current->next;
	free(current);
	return;
}

void DeleteFromBeginning (struct CLLNode **head){
	struct CLLNode *temp, *current;
	*temp, *current = *head;
	if (*head == NULL){
		printf("List Empty");
		return;
	}

	while (current->next != *head)
		current = current->next;
	current->next = *head->next;
	*head = *head->next;

	free (temp);
	return;
}