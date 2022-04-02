void Insertion(struct BinaryTreeNode *root){
	struct Queue *Q;
	struct BinaryTreeNode *temp;
	struct BinaryTreeNode *newNode;

	newNode = (struct BinaryTreeNode *) malloc (sizeof(struct BinaryTreeNode));

	newNode->left = newNode->right = NULL;

	if (!newNode)
		return;

	if (!root){
		root = newNode;
		return;
	}

	Q = Create_Queue();
	EnQueue(Q, root);

	while (!isEmpty(Q)){
		temp = DeQueue(Q);

		if (temp->left){
			EnQueue(Q, temp->left);
		} else {
			temp->left = newNode;
			Delete_Queue(Q);
			return;
		}

		if (temp->right){
			EnQueue(Q, temp->right);
		} else {
			temp->right = newNode;
			Delete_Queue(Q);
			return;
		}
	}
	Delete_Queue(Q);
}