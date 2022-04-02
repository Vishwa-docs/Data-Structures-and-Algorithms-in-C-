#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};


// The default flow is from parent to child and we dont consider backward traversal, hence it is not mandatory to show directed branches

struct BinaryTreeNode * Create_Node(int data){
	struct BinaryTreeNode *newNode; // Create Node pointer
	newNode = (struct BinaryTreeNode *) malloc (sizeof(struct BinaryTreeNode)); // Allocate memory in the heap
	// For multiple nodes, use size * sizeof and create

	newNode->data = data;
	// Assume the left and right children are NULL. These are linked later
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

int main(){
	/*
	// Manually constructing the node
	struct BinaryTreeNode *root;
	root = (struct BinaryTreeNode *) malloc (sizeof(struct BinaryTreeNode));
	root->data = 5;
	root->left = NULL;
	root->right = NULL;
	*/

	// Creating nodes using Functions : 

	struct node *root = Create_Node(5);
	struct node *child1 = Create_Node(1);
	struct node *child2 = Create_Node(6);

	// Linking the nodes : 
	root->left = child1;
	root->right = child2;
	return 0;
}
