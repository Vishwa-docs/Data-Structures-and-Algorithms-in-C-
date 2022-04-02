// Find the size of left and right tree and add 1
int Size_Tree(struct BinaryTreeNode *root){
	if (root == NULL)
		return 0;
	else return (Size_Tree(root->left) + 1 + Size_Tree(root->right));
}



int Size_Tree_NonRecursive(struct BinaryTreeNode *root){
	struct BinaryTreeNode *temp;
	struct Queue *Q = Create_Queue();
	int count = 0;

	if (!root)
		return -1;

	EnQueue(Q, root);
	while (!isEmpty(Q)){
		temp = DeQueue(Q);

		count++;

		if (temp->left)
			EnQueue(Q, temp->left);

		if (temp->right)
			EnQueue(Q, temp->right);
	}
	Delete_Queue(Q);
	return count;
	// Time and Space O(n)
}