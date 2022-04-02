#include "Stacks/Simple_Array_Implementation.c"

void PreOrder(struct BinaryTreeNode *root){
	/*
	To simulare recursion, we process the corrent node and push it in a stack before going to the left subtree
	After completing the left subtree processing, pop the element and go to its right subtree
	Continue until stack is non empty
	*/ 

	struct Stack *S = Create_Stack();

	while(1){
		while (root) {
			// Process current Node
			printf("%d", root->data);
			Push(S, root);

			// If left subtree exists, add to stack
			root = root->left;
		}

		if (isEmpty(S)){
			break;
		}
		root = Pop(S);

		// Indicates completion of left subtree and current node, so now go to right subtree
		root = root->right;
	}
	Delete_Stack(S);
}


void PreOrder_Recursive(struct BinaryTreeNode *root){
	if (root){
		printf("%d", root->data);
		PreOrder_Recursive(root->left);
		PreOrder_Recursive(root->right);
	}
}

/************************************************************/

void InOder(struct BinaryTreeNode *root){
	// Same as Preorder, but instead of processing the node before going to left subtree, process it after popping (indicated by completion of left subtree processing)
	struct Stack *S = Create_Stack();

	while(1){
		while (root) {
			Push(S, root);
			// Go to left subtree and keep on adding to stack
			root = root->left;
		}

		if (isEmpty(S)){
			break;
		}
		root = Pop(S);

		printf("%d", root->data); // After popping, the current node is processed

		// Indicates completion of left subtree and current node, so now go to right subtree
		root = root->right;
	}
	Delete_Stack(S);
}

void InOrder_Recursive(struct BinaryTreeNode *root){
	if (root){
		InOrder_Recursive(root->left);
		printf("%d", root->data);
		InOrder_Recursive(root->right);
	}
}


/************************************************************/
void PostOrder(struct BinaryTreeNode *root){
	/*
	In PostOrder, each node is visited twice, but we should process the node only during the second visit
	Using a previous variable
	*/

	struct Stack *S = Create_Stack();
	struct BinaryTreeNode *previous = NULL;

	do{
		while (root != NULL){
			Push(S, root);
			root = root->left;
		}

		while (root == NULL && !isEmpty(S)){
			root = PEEK_Stack_Top(S);
			if (root->right == NULL || root->right == previous){
				printf("%d ", root->data);
				Pop(S);
				previous = root;
				root = NULL;
			} else {
				root = root->right;
			}
		}
	} while (!isEmpty(S));
}

void PostOrder_Recursive(struct BinaryTreeNode *root){
	while(root){
		PostOrder_Recursive(root->left);
		PostOrder_Recursive(root->right);
		printf("%d", root->data);
	}
}



/************************************************************/
void LevelOrder(struct BinaryTreeNode *root){
	struct BinaryTreeNode *temp;
	struct Queue *Q = Create_Queue();

	if (!root)
		return;

	EnQueue(Q, root);
	while (!isEmpty(Q)){
		temp = DeQueue(Q);

		// Process the current node
		printf("%d", temp->data);

		if (temp->left)
			EnQueue(Q, temp->left);

		if (temp->right)
			EnQueue(Q, temp->right);
	}
	Delete_Queue(Q);
}