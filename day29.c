#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Create linked list */
struct Node* createList(int n) {
    if (n == 0) return NULL;

    int x;
    scanf("%d", &x);

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = x;
    head->next = NULL;

    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

/* Rotate right by k */
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: find length and last node
    struct Node* temp = head;
    int n = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Step 2: make circular
    temp->next = head;

    // Step 3: reduce k
    k = k % n;
    int steps = n - k;

    // Step 4: move to new tail
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // Step 5: break circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

/* Print list */
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createList(n);

    int k;
    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}