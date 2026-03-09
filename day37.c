#include <stdio.h>
#include <string.h>

int pq[100];
int size = 0;

void insert(int x) {
    pq[size++] = x;
}

int deleteMin() {
    if (size == 0)
        return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex])
            minIndex = i;
    }

    int minValue = pq[minIndex];
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
    return minValue;
}

int peek() {
    if (size == 0)
        return -1;

    int minValue = pq[0];
    for (int i = 1; i < size; i++) {
        if (pq[i] < minValue)
            minValue = pq[i];
    }
    return minValue;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}