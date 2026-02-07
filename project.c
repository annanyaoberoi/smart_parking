#include <stdio.h>
#include <limits.h>

#define V 5 // Number of locations in the city (nodes)

// Function to find the unvisited node with minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, idx = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

// Dijkstra algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V] = {0};

    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Calculate shortest paths
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        printf("Shortest time from Home (A) to Node %c = %d minutes\n", 'A' + i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, 2, 0, 0}, // A: Home
        {0, 0, 0, 8, 5}, // B
        {0, 0, 0, 0, 0}, // C
        {0, 0, 0, 0, 0}, // D
        {0, 0, 0, 0, 0}  // E
    };

    dijkstra(graph, 0); // Start from Home (A)
    return 0;
}
