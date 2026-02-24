#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x, count = 0;
    struct Node *head = NULL, *tail = NULL, *temp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = x;
        temp->next = NULL;

        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}