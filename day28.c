#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Create circular linked list */
struct Node* createCLL(int n) {
    if (n == 0) return NULL;

    int x;
    scanf("%d", &x);

    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->data = x;
    head->next = head;

    struct Node *temp = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = head;

        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

/* Traverse circular linked list */
void display(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createCLL(n);

    display(head);

    return 0;
}