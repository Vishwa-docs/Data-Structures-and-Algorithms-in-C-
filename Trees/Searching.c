int Search(struct BinaryTreeNode *root, int data){
	int temp;

	// Base case is an empty tree, which means data is not found
	if (root == NULL)
		return 0;

	else {
		// Check for data in node
		if (root->data == data)
			return 1;

		else {
			// Check the same using recurrance
			temp = Search(root->left, data);

			if (temp != 0)
				return temp;
			else
				return Search(root->right, data);
		}
	}

	return 0;
	// Time and Space : O(n)
}


/**************************************/
int Search_NonRecursive(struct BinaryTreeNode *root){
	struct BinaryTreeNode *temp;
	struct Queue *Q = Create_Queue();

	if (!root)
		return -1;

	EnQueue(Q, root);
	while (!isEmpty(Q)){
		temp = DeQueue(Q);

		// See if found
		if (root->data == data)
			return 1;

		if (temp->left)
			EnQueue(Q, temp->left);

		if (temp->right)
			EnQueue(Q, temp->right);
	}
	Delete_Queue(Q);
	return 0;
	// Time and Space : O(n)
}