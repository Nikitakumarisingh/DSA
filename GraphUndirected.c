//QUESTION: Detect a cycle in an undirected graph.
//CODE:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Graph structure
struct Graph {
    int V;                  // Number of vertices
    int adj[MAX][MAX];      // Adjacency matrix
};

// Function to create a new graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph->adj[i][j] = 0;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;  // Since the graph is undirected
}

// Utility function for DFS to detect a cycle
bool isCyclicUtil(struct Graph* graph, int v, bool visited[], int parent) {
    visited[v] = true;

    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i]) { // If there is an edge
            if (!visited[i]) {
                // Recur for all the vertices adjacent to this vertex
                if (isCyclicUtil(graph, i, visited, v))
                    return true;
            } else if (i != parent) {
                // If an adjacent vertex is visited and not parent of current vertex, then there is a cycle
                return true;
            }
        }
    }
    return false;
}

// Function to detect a cycle in an undirected graph
bool isCyclic(struct Graph* graph) {
    bool visited[MAX] = {false};

    // Call the recursive helper function to detect cycle in different DFS trees
    for (int u = 0; u < graph->V; u++) {
        if (!visited[u]) { // Don't recur for u if it is already visited
            if (isCyclicUtil(graph, u, visited, -1))
                return true;
        }
    }
    return false;
}

// Main function
int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 1);

    if (isCyclic(graph))
        printf("Graph contains cycle\n");
    else
        printf("Graph doesn't contain cycle\n");

    free(graph);
    return 0;
}
