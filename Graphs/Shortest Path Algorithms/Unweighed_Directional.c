/*********** Using Queues ***********/

void UnweighedShortestPath (struct Graph *G, int s){
	struct Queue *Q = Create_Queue();
	int v, w;
	EnQueue(Q, s);

	for (int i = 0; i < G->V; i++)
		Distance[i] = -1;
	Distance[s] = 0;

	while (!isEmpty(Q)){
		v = DeQueue(Q);

		// For each w adjacent to v
		for(){
			if (Distance[w] == -1){ // Each vertex examined only once
				Distance[w] = Distance[v] + 1;
				Path[w] = v;
				EnQueue(Q, w); // Each verte enqueued at most once
			}
		}
	}
}