#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack node structure
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value = (*top)->data;
    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i] != '\0') {

        // If operand, push to stack
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        }

        // If operator
        else if (exp[i] == '+' || exp[i] == '-' ||
                 exp[i] == '*' || exp[i] == '/') {

            int op2 = pop(&stack);
            int op1 = pop(&stack);

            switch (exp[i]) {
                case '+': push(&stack, op1 + op2); break;
                case '-': push(&stack, op1 - op2); break;
                case '*': push(&stack, op1 * op2); break;
                case '/': push(&stack, op1 / op2); break;
            }
        }
        i++;
    }
    return pop(&stack);
}

// Main function
int main() {
    char exp[100];

    printf("Enter postfix expression (no spaces): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result: %d", result);

    return 0;
}