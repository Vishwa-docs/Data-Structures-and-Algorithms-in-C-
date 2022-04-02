// Printing the Level Order Traversal in Reverse
// Use stacks and pop after adding from the tree

void LevelOrder_Reverse(struct BinaryTreeNode *root){
	struct Queue *Q = Create_Queue();
	struct Stack *S = Create_Stack();

	struct BinaryTreeNode *temp;

	if (!root)
		return;

	EnQueue(Q, root);
	while (!isEmpty(Q)){
		temp = DeQueue(Q);

		if (temp->left)
			EnQueue(Q, temp->left);

		if (temp->right)
			EnQueue(Q, temp->right);

		Push(S, temp);
	}
	while (!isEmpty(S))
		printf("%d", Pop(S)->data);
}