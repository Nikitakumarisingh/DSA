#Given an undirected graph 
#𝐺=(𝑉,𝐸)G=(V,E) with 𝑉 V vertices and 𝐸
#E edges, determine whether there exists a Hamiltonian cycle—a cycle that visits every vertex exactly once and returns to the starting vertex.
#solution :
#include <iostream>
#include <vector>
using namespace std;

#define V 5  // Number of vertices

// Function to check if vertex v can be added to Hamiltonian Cycle
bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int pos) {
    // Check if edge exists
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if vertex is already included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Backtracking function to find Hamiltonian Cycle
bool hamCycleUtil(vector<vector<int>> &graph, vector<int> &path, int pos) {
    // If all vertices are in cycle
    if (pos == V) {
        // Check if last vertex connects to the first
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Try adding vertices to cycle
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;  // Backtrack
        }
    }

    return false;
}

// Function to check for Hamiltonian Cycle
bool findHamiltonianCycle(vector<vector<int>> &graph) {
    vector<int> path(V, -1);
    path[0] = 0; // Start from first vertex

    if (!hamCycleUtil(graph, path, 1)) {
        cout << "No Hamiltonian Cycle exists\n";
        return false;
    }

    // Print the Hamiltonian Cycle
    cout << "Hamiltonian Cycle found: ";
    for (int v : path)
        cout << v << " ";
    cout << path[0] << endl; // Close the cycle

    return true;
}

// Driver code
int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    findHamiltonianCycle(graph);
    return 0;
}
