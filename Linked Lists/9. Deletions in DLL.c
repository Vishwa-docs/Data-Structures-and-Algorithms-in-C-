// Deletion Operations
void DLLDeletions(struct DLLNode **head, int position){
	struct DLLNode *temp, *temp2, temp = *head;
	int k = 1;

	if (*head == NULL){
		printf("List is empty");
		return;
	}

	// Deletion at Beginning
	if (position == 1){
		*head = (*head)->next;

		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return;
	}

	while ((k < position - 1) && (temp->next != NULL)){
		temp = temp->next;
		k++;
	}

	if (k != position-1){
		printf("Desired Position Does not exist\n");
	}

	temp2 = temp->prev;
	temp2->ext = temp->next;

	if (temp->next) // Intermediate Deletion
		temp->next->prev = temp2;

	free(temp);
	return;
}

/**************** Individual Functions ****************/