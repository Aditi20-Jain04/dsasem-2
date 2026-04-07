#include <stdio.h>

#define MAX 100

int main()
{
    int n, m;
    int u, v;
    int choice;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize adjacency matrix with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter 1 for Directed graph\n");
    printf("Enter 2 for Undirected graph\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;

        if (choice == 2)   // undirected
            adj[v][u] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}