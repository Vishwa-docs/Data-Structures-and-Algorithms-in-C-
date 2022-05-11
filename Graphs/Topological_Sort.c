/*
Algorithm  :
	Store each vertex's In-Degree in an array.
	Compute the InDegree of all the vertices, starting with InDegree 0
		Vertices which do not have any incoming lines have InDegree 0
		Enqueue these vertices into a Queue (With InDegree = 0)
	While there are vertices in the queue : 
		Dequeue vertex v from the queue 
		Decrement all the adjacent nodes' InDegree by 1
		Enqueue any new vertices whose InDegree becomes 0 to the queue

	The Topological Ordering is the Ordering in which we dequeue
*/

// Using Adjacency Matrix
#include <stdio.h>
#include <conio.h>

void TopologicalSort(int A[10][10], int n){ // Adjacency matric and number of vertices
	int InDegree[10], flag[10];
	int count = 0;

	// Initlalize to 0
	for (int i = 0; i < n; i++){
		InDegree[i] = 0;
		flag[i] = 0;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			InDegree[i] = InDegree[i] + A[j][i]; // To find the InDegree of each vertex
		}
	}

	printf("Topological Ordering is : ");

	while (count < n){
		for (int k = 0; k < n; k++){
			// If the Indegree is 0, print the 
			if (InDegree[k] == 0 && flag[k] == 0){
				printf("%d ", k + 1);
			}

			// Reduce the Indegree for adjacent vertices
			for (int i = 0; i < n; i++){
				if (A[i][k] == 1){
					InDegree[k]--;
				}
			}
		count++;
		}
	}
}