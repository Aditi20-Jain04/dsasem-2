#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    return dummy.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* node = createNode(x);
        if (head1 == NULL)
            head1 = tail1 = node;
        else {
            tail1->next = node;
            tail1 = node;
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        struct Node* node = createNode(x);
        if (head2 == NULL)
            head2 = tail2 = node;
        else {
            tail2->next = node;
            tail2 = node;
        }
    }

    struct Node* mergedHead = mergeLists(head1, head2);
    printList(mergedHead);

    return 0;
}