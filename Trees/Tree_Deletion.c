// Use Postorder Traversal as we need to delete the child before deleting the parent and Postorder doesnt store anything
// NOTE DOWN THE ORDER OF DELETION

void Delete_Binary_Tree(struct BinaryTreeNode *root){
	if (root == NULL)
		return;

	// Delete the Subtrees
	Delete_Binary_Tree(root->left);
	Delete_Binary_Tree(root->right);

	// Delete current node
	free(root);
}