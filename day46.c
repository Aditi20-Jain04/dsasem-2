#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("\n");
        return 0;
    }
    
    int left[1000], right[1000], val, queue[1000];
    int front = 0, rear = 0;
    
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &val, &left[i], &right[i]);
    
    queue[rear++] = 0; // root
    
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        
        if (left[curr] != -1)
            queue[rear++] = left[curr];
        if (right[curr] != -1)
            queue[rear++] = right[curr];
    }
    
    return 0;
}