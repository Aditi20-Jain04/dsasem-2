#include <stdio.h>

#define MAX 100

int n;
int adj[MAX][MAX];     // adjacency matrix
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;

// enqueue
void enqueue(int x)
{
    queue[++rear] = x;
}

// dequeue
int dequeue()
{
    return queue[front++];
}

// BFS function
void bfs(int s)
{
    visited[s] = 1;
    enqueue(s);

    while (front <= rear)
    {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] == 1 && !visited[v])
            {
                visited[v] = 1;
                enqueue(v);
            }
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

    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("BFS traversal order: ");
    bfs(s);

    return 0;
}