#include <stdio.h>
#include <stdlib.h>

struct graph {
	int V;
	int E;
	int *Adj; // Head Pointers to LL
}

// Nodes for LL
struct Node{
	int vertexNumber;
	struct Node * next;
}

// Creating a graph
struct graph * adjList(){
	int i, x, y;
	struct Node * temp;

	// Pointer to graph
	struct graph * G = (struct graph *) malloc (sizeof(struct graph));

	if (!G){
		printf("Memory Error");
		return;
	}

	scanf("Number of vertices : %d, Number of Edges : %d", &G->V, &G->E);

	// Create space only for the main vertices nodes as an LL
	G->Adj = malloc (G->V * sizeof(struct Node));

	// Creating another node for each vertex and poinitng it to itself
	for(i = 0; i < G->V; i++){
		G->Adj[i] = (struct Node *) malloc (sizeof(struct Node));
		G->Adj[i]->vertexNumber = i;
		G->Adj[i]->next = G->Adj[i]; // Make the nodes point to itself
	}

	for (i = 0; i < E; i++){
		// Read an edge
		scanf("Reading edge : %d %d", &x, &y);

		// Creating a new node to attact to a vertex
		temp = (struct Node *) malloc (struct Node);
		temp->vertexNumber = y; // This will be the vertex the main vertex's edge points to
		temp->next = G->Adj[x];
		G->Adj[x]->next = temp; // Create a loop

		// If x is connected to y, then y is connected to x
		temp = (struct Node *) malloc (struct Node);
		temp->vertexNumber = y; // This will be the vertex the main vertex's edge points to
		temp->next = G->Adj[y];
		G->Adj[y]->next = temp;
	}

	return G;
}