#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to the graph (undirected)
void addEdge(struct Node* adjList[], int u, int v)
{
    // Add v to u's list
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // Add u to v's list
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// Print adjacency list
void printGraph(struct Node* adjList[], int n)
{
    for (int i = 0; i < n; i++)
    {
        struct Node* temp = adjList[i];
        printf("%d: ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int n, m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Create adjacency list
    struct Node* adjList[n];
    for (int i = 0; i < n; i++)
        adjList[i] = NULL;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }

    printf("\nAdjacency List:\n");
    printGraph(adjList, n);

    return 0;
}