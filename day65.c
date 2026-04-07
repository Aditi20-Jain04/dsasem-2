#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];
int n;               // number of vertices

// DFS function to detect cycle
int dfs(int u, int parent)
{
    visited[u] = 1;

    for (int v = 0; v < n; v++)
    {
        if (adj[u][v])   // if edge exists
        {
            if (!visited[v])
            {
                if (dfs(v, u))
                    return 1;   // cycle found
            }
            else if (v != parent)
            {
                return 1;       // back edge → cycle
            }
        }
    }
    return 0;
}

int main()
{
    int e, u, v;
    int cycle = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // undirected graph
    }

    // initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // check all components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
            {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}