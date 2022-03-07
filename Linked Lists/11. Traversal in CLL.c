// LinkedList Traversal, Count and Printing
int CLLTraversal(struct CLLNode *head){
	struct CLLNode *current = head;
	int count = 0;

	if (head == NULL)
		return 0;

	do {
		count++; // Number of elements
		printf("Element %d\n", current->data); // Element data
		current = current->next; // Go to next element
	} while (current != head);

	return count;
}