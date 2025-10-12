#include <stdio.h>
#define N 5

char stack[N];
int top = -1;

void push(char ch) {
    if (top == N - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
    printf("Pushed '%c' onto stack.\n", ch);
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    printf("Popped element: %c\n", stack[top--]);
}

char peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return '\0';
    }
    printf("Top element: %c\n", stack[top]);
    return stack[top];
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int main() {
    int x;
    char element;

    printf("\n1: Push  2: Peek  3: Pop  4: Display  5: Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &x);

    while (x != 5) {
        switch (x) {
            case 1:
                printf("Enter an element to push (single character): ");
                scanf(" %c", &element);  // space before %c consumes newline
                push(element);
                break;

            case 2:
                peek();
                break;

            case 3:
                pop();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Wrong choice! Please try again.\n");
                break;
        }
        printf("\n1: Push  2: Peek  3: Pop  4: Display  5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &x);
    }

    return 0;
}
