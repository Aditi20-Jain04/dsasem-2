#include <stdio.h>

#define MAX 100

int n;
int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];

// DFS function
void dfs(int u)
{
    visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < n; v++)
    {
        if (adj[u][v] == 1 && !visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS traversal order: ");
    dfs(s);

    return 0;
}