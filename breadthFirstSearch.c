// breadth first search using linked lists as adjacency lists
// scott banyard 25/10/15

#include <stdio.h>
#include <stdlib.h>


struct Edge {
	int vertex;
	struct Edge* next;
} Edge;

// inserts node to linked list by head insertion
// returns address of head which is the newly created node
struct Edge* addEdge(struct Edge* currentHead, int newVertex) {
	struct Edge* newHead = (struct Edge*) malloc(sizeof(struct Edge));
	newHead->vertex = newVertex;
	newHead->next = currentHead;

	return newHead;
}

void BFS(struct Edge* adjacencyList[], int vertices, int parent[], int level[], int startVertex) {
	struct Edge * traverse;
	int par, lev, flag = 1;
	// lev is level to be assigned, par is parent to be assigned, flag used to indicate if graph has been exhausted

	lev = 0;
	level[startVertex] = lev;
	// sets level of startVertex to 0

	while (flag) {
		flag = 0;
		for (int i = 1; i <= vertices; i++) {
			if (level[i] == lev) {
				flag = 1;
				traverse = adjacencyList[i];
				par = i;

				while (traverse != NULL) {
					if (level[traverse->vertex] != -1) {
						traverse = traverse->next;
						continue;
					}

					level[traverse->vertex] = lev + 1;
					parent[traverse->vertex] = par;
					traverse = traverse->next;
				}
			}
		}

		lev++;
	}

}

int main() {
	int vertices, edges, v1, v2;

	printf("Enter the number of vertices: \n");
	scanf("%d", &vertices);

	printf("Enter the number of edges: \n");
	scanf("%d", &edges);

	// create adjacency list of size vertices + 1 so can array as 1 indexed
	struct Edge* adjacencyList[vertices + 1];

	// set max sizes of parent/level arrays
	int parent[vertices + 1];
	int level[vertices + 1];

	// initialize array
	for (int i = 0; i <= vertices; i++) {
		adjacencyList[i] = NULL;
		parent[i] = 0;
		level[i] = -1;
	}

	printf("Enter both vertices of edge for %d edges: \n", edges);
	for (int i = 1; i <= edges; i++) {
		scanf("%d%d", &v1, &v2);

		// adding edge v1 --> v2
		adjacencyList[v1] = addEdge(adjacencyList[v1], v2);

		// adding edge v2 --> v1 : add this if want an undirected graph
		//adjacencyList[v2] = addEdge(adjacencyList[v2], v1);
	}

	// print adjacency list
	printf("\nAdjacency List: \n\n");
	for (int i = 1; i <= vertices; i++) {
		printf("adjacencyList[%d] -> ", i);

		struct Edge* traverse = adjacencyList[i];

		while (traverse != NULL) {
			printf("%d -> ", traverse->vertex);
			traverse = traverse->next;
		}

		printf("NULL\n");
	}

	printf("Enter starting vertex: ");
	scanf("%d", &v1);

	BFS(adjacencyList, vertices, parent, level, v1);

	// printing level and parent arrays
	printf("\nLevel and Parent Arrays: \n");
	for (int i = 1; i <= vertices; i++) {
		printf("Level of Vertex %d is %d, Parent is %d\n", i, level[i], parent[i]);
	}


	return 0;
}