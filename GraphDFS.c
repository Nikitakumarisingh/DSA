//QUESTION: Implement DFS.
//CODE: 
#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// A structure to represent an adjacency list
struct Graph {
    int numVertices;
    struct Node** adjLists; // Array of adjacency lists
    int* visited; // Array to track visited vertices
};

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'n' vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists and a visited array
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    // Initialize each adjacency list as empty and visited array as 0
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS algorithm
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    // Create a graph with 5 vertices
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);
    
    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Perform DFS starting from vertex 0
    printf("Depth First Traversal starting from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}
