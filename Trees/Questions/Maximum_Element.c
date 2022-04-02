// Maximum Element in a Binary Tree

// Find the minimum in the right subtree, min in left and comapre with root node

int Maximum_Recursion(struct BinaryTreeNode *root){
	int root_val, left, right, max = 0;
	if (root != NULL){
		root_val = root->data;
		left = Maximum_Recursion(root->left);
		right = Maximum_Recursion(root->right);


		max = root_val > left ? (root_val > right ? root_val : right) : (left > right ? left : right) ;

		return max;
		// Time and Space : O(n)
	}
}

// Or, traverse the tree and store the max element in another variable

int LevelOrder_Max(struct BinaryTreeNode *root){
	struct BinaryTreeNode *temp;
	int max = 0;
	struct Queue *Q = Create_Queue();

	EnQueue(Q, root);
	while (!isEmpty(Q)){
		temp = DeQueue(Q);

		if (max < temp->data)
			max = temp->data;

		if (temp->left)
			EnQueue(Q, temp->left);

		if (temp->right)
			EnQueue(Q, temp->right);
	}
	Delete_Queue(Q);
	return max;
	// Time and Space : O(n)
}