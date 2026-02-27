#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = x;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    struct Node* p1 = head1;
    while (p1 != NULL) {
        struct Node* p2 = head2;
        while (p2 != NULL) {
            if (p1->data == p2->data) {
                printf("%d", p1->data);
                return 0;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    printf("No Intersection");
    return 0;
}