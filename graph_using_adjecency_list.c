// Graph using adjecency list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int vertex;
  struct Node *next;
};

struct Graph {
  int numVertices;
  struct Node **adjLists;
};

struct Node *createNode(int v) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph *createGraph(int vertices) {
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));

  for (int i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
  }

  return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
  struct Node *newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    struct Node *temp = graph->adjLists[i];
    printf("Adjacency list of vertex %d\n", i);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main() {
  int vertices, edges;
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);
  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  struct Graph *graph = createGraph(vertices);

  printf("Enter the edges (source_vertex destination_vertex):\n");
  printf("Note: Consider vertices from 0 to (number of vertices - 1).\n");

  for (int i = 0; i < edges; i++) {
    int src, dest;
    scanf("%d %d", &src, &dest);
    addEdge(graph, src, dest);
  }

  printf("\nAdjacency list representation of the graph:\n");
  printGraph(graph);

  return 0;
}
