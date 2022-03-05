// DLL Traversals
void DLL_Forward_Traversal(struct DLLNode *head){
	struct DLLNode *ptr = head;
	int count = 0;

	while (ptr != NULL){
		count++;
		printf("Element: %d\n", ptr->data);
		ptr = ptr->next;
	}
	return;
}

// Tail need not be mentioned, so check before doing reverse traversal
void DLL_Reverse_Traversal(struct DLLNode *tail){
	struct DLLNode *ptr = tail;
	int count = 0;

	while (ptr != NULL){
		count++;
		printf("Element: %d\n", ptr->data);
		ptr = ptr->prev;
	}
	return;
}


/**************** Function Calls ****************/
DLL_Forward_Traversal(head);
printf("\n\n\n");
DLL_Reverse_Traversal(tail);