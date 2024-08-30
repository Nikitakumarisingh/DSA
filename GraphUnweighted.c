//QUESTION: Find the shortest path in an unweighted graph.
//CODE: 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100  // Define the maximum number of nodes

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// Structure for the queue node
typedef struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Function to print the shortest path
void printPath(int parent[], int vertex) {
    if (vertex == -1)
        return;
    printPath(parent, parent[vertex]);
    printf("%d ", vertex);
}

// Function to perform BFS and find the shortest path
void bfs(Graph* graph, int startVertex, int endVertex) {
    Queue* q = createQueue();
    int parent[MAX_NODES];  // Array to store the shortest path tree
    for (int i = 0; i < graph->numVertices; i++) {
        parent[i] = -1;
    }

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                parent[adjVertex] = currentVertex;  // Set parent for the path
                enqueue(q, adjVertex);

                // Stop BFS if we reached the end vertex
                if (adjVertex == endVertex) {
                    printf("Shortest path from %d to %d: ", startVertex, endVertex);
                    printPath(parent, endVertex);
                    printf("\n");
                    return;
                }
            }
            temp = temp->next;
        }
    }

    printf("No path found from %d to %d\n", startVertex, endVertex);
}

int main() {
    int vertices = 6;  // Number of vertices
    Graph* graph = createGraph(vertices);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    int startVertex = 0;
    int endVertex = 5;
    bfs(graph, startVertex, endVertex);

    return 0;
}
