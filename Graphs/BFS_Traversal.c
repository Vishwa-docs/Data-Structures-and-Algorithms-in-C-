/*************** USING ADJACENCY MATRIX ***************/

void BFS_AdjMatrix(int adj[][no_vertices], int start){
	int visited[no_vertices],queue[no_vertices],front = -1,rear = -1;

	// Initially initialize to 0
	for(int i = 0; i < no_vertices ;i++)
		visited[i] = 0;

	front++; // Point to first element
	queue[++rear] = start; // Starting from the given node, so insert first
	visited[start] = 1; // Visited the first element

	while(front <= rear) { // While the queue is not empty
		start = queue[front++];
		printf("%d\t", start);

		for(int i = 0; i < no_vertices; i++) { // Traverse hte other vertices
			if(adj[start][i]==1 && visited[i] != 1) { // If there is an edge from node and not visited
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}