#include <stdio.h> 
#include <limits.h>
#define V 5 // Number of locations in the city (nodes) int minDistance(int dist[], int visited[]) {
int min = INT_MAX, idx = -1;
// Find the unvisited node with the minimum distance for (int i = 0; i < V; i++) {
if (!visited[i] && dist[i] < min) { min = dist[i];
idx = i;
}
}
return idx;
}
void dijkstra(int graph[V][V], int src) {
int dist[V], visited[V] = {0}; // Initialize distance and visited arrays for (int i = 0; i < V; i++) {
dist[i] = INT_MAX; // Set initial distances to infinity
}
dist[src] = 0; // Distance from the source to itself is 0
// Calculate the shortest path for all nodes for (int count = 0; count < V - 1; count++) {
int u = minDistance(dist, visited); // Find the node with the smallest distance visited[u] = 1; // Mark this node as visited
// Update distances for adjacent nodes for (int v = 0; v < V; v++) {
if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
dist[v] = dist[u] + graph[u][v]; // Update the distance if a shorter path is
found
}
}
}
// Print the shortest distances from the source node for (int i = 0; i < V; i++) {
printf("Shortest time from Home (A) to Node %c = %d minutes\n", 'A' + i,

dist[i]);
}
}

int main() {
// Representing the city map as an adjacency matrix
// graph[i][j] stores the travel time between location i and location j int graph[V][V] = {
{0, 4, 2, 0, 0}, // A: Home
{0, 0, 0, 8, 5}, // B
{0, 0, 0, 0, 0}, // C
{0, 0, 0, 0, 0}, // D
{0, 0, 0, 0, 0}	// E
};
// Call the Dijkstra function to find the shortest paths from 'Home (A)' dijkstra(graph, 0); // 0 represents 'Home (A)'
return 0;
}
