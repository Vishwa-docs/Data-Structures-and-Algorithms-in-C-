// LinkedList Traversal
void LLTraversal(struct Node *head){
	struct Node *current = head;
	int count = 0;

	while (current != NULL){
		count++; // Number of elements
		printf("Element %d\n", current->data); // Element data
		current = current->next; // Go to next element
	}
	return;
}