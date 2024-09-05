//QUESTION: Find all strongly connected components in a graph.

//Algorithm used: Kosaraju's Algorithm, which is efficient, with a time complexity of O(V + E), where V is the number of vertices and E is the number of edges in the graph.
//The algorithm involves two main steps:
// 1. Perform a DFS on the original graph to fill a stack with vertices based on their finishing times.
// 2. Transpose the graph (reverse all edges) and perform a DFS based on the vertices' order in the stack to find SCCs.

//CODE:
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Graph structure using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

// Function to create a node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to create a stack
Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Stack functions
void push(Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// DFS function
void dfs(Graph* graph, int vertex, Stack* stack) {
    graph->visited[vertex] = 1;
    Node* temp = graph->adjLists[vertex];

    while (temp) {
        int connectedVertex = temp->vertex;
        if (!graph->visited[connectedVertex]) {
            dfs(graph, connectedVertex, stack);
        }
        temp = temp->next;
    }
    push(stack, vertex);
}

// Function to transpose the graph
Graph* transposeGraph(Graph* graph) {
    Graph* transpose = createGraph(graph->numVertices);
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        while (temp) {
            addEdge(transpose, temp->vertex, v);
            temp = temp->next;
        }
    }
    return transpose;
}

// Function to print SCC
void printSCC(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int connectedVertex = temp->vertex;
        if (!graph->visited[connectedVertex]) {
            printSCC(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Function to find and print all SCCs
void findSCCs(Graph* graph) {
    Stack* stack = createStack();

    // Step 1: Fill vertices in stack according to their finishing times
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            dfs(graph, i, stack);
        }
    }

    // Step 2: Create a transposed graph
    Graph* transpose = transposeGraph(graph);

    // Step 3: Initialize visited array for the transposed graph
    for (int i = 0; i < graph->numVertices; i++) {
        transpose->visited[i] = 0;
    }

    // Step 4: Process all vertices in order defined by Stack
    while (!isEmpty(stack)) {
        int vertex = pop(stack);

        // Print SCC of the popped vertex
        if (!transpose->visited[vertex]) {
            printSCC(transpose, vertex);
            printf("\n");
        }
    }
}

// Main function
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 2);
    addEdge(graph, 2, 1);
    addEdge(graph, 1, 0);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 4);

    printf("Strongly Connected Components in the graph are:\n");
    findSCCs(graph);

    return 0;
}

