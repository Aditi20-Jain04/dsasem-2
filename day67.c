#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

/* DFS function */
void dfs(int v)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && !visited[i])
            dfs(i);
    }

    stack[++top] = v;   // push after visiting all neighbors
}

int main()
{
    int m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // initialize adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // initialize visited array
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    // call DFS for each vertex
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            dfs(i);
    }

    printf("Topological Order: ");
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}