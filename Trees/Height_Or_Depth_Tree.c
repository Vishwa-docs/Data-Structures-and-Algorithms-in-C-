// Assign height as max of subtree + 1 (DFS of Graph)

int Height_Or_Depth(struct BinaryTreeNode *root){
	int leftHeight, rightHeight, max = 0;

	if (!root)
		return -1;

	else {
		// Find depth of each subtree
		leftHeight = Height_Or_Depth(root->left);
		rightHeight = Height_Or_Depth(root->right);

		(leftHeight > rightHeight) ? return (leftHeight + 1 ) : return (rightHeight + 1);

		// Time and Space O(n)
	}
}


// Non-Recursively, we can use LevelOrder (BFS). End of a level is identified with NULL
