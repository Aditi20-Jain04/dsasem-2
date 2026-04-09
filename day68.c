#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];     // Adjacency matrix
int indegree[MAX];     // In-degree array
int queue[MAX];        // Queue
int front = 0, rear = -1;

int main() {
    int n, m;
    int i, j;
    int u, v;
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize adjacency matrix and indegree array
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges
    printf("Enter edges (u v) format:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Insert all vertices with indegree 0 into queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    printf("Topological Order: ");

    // Kahn's Algorithm
    while (front <= rear) {
        u = queue[front++];
        printf("%d ", u);
        count++;

        for (v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[++rear] = v;
                }
            }
        }
    }

    // Check for cycle
    if (count != n) {
        printf("\nGraph contains a cycle. Topological sort not possible.\n");
    }

    return 0;
}