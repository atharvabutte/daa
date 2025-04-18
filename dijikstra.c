#include <stdio.h>
#include <limits.h>

#define V 3

#define true 1
#define false 0

typedef int bool;

int min_v(int dist[V], bool set[V]) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < V; i++) {
        if (!set[i] && dist[i] <= min) {
            min_index = i;
            min = dist[i];
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool set[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        set[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = min_v(dist, set);
        set[u] = true;

        for (int v = 0; v < V; v++) {
            if (!set[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V];
    printf("Enter the adjacency matrix (enter 0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Enter weight for edge %d -> %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &source);

    dijkstra(graph, source);
    return 0;
}
