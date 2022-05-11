#include <stdio.h>
#include <stdlib.h>

struct graph {
	int V;
	int E;
	int **Adj; // To get 2D Matrix
}

// Read Vertex names, then the pairs of vertex names (Edges)


// Reading an Undirected graph : 

// Creating a graph with adjacency matrix representation
struct graph * adjMatrix(){
	int i, u, v;
	struct graph * G = (struct graph *) malloc (sizeof(struct graph));

	if (!G){
		printf("Memory Error");
		return NULL;
	}

	scanf("Enter Number of Vertices : %d, Number of Edges : %d", &G->V, &G->E);

	G->Adj = malloc (sizeof(G->V * G->V));

	for (u = 0; u < G->V, u++){
		for (v = 0; v < G->V; v++){
			G->Adj[v][v] = 0; // 
		}
	}

	for (i = 0; i < G->E; i++){
		// Read an edge
		scanf("Reading Edge : %d %d", &u, &v);

		// For undorected graphs set both the bits
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}

	return G;
}

printf("Enter the no of vertices:\n");
scanf("%d",&n);

printf("Enter the adjacency matrix:\n");

for(i = 0; i < n; i++){
	printf("Enter row %d\n",i+1);
	for(j = 0; j < n; j++)
		scanf("%d",&a[i][j]);
}