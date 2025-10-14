#include <stdio.h>
#include <string.h>  // for strlen

#define N 100

char stack[N];
int top = -1;

// Stack operations
void push(char ch) {
    if (top == N - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';  // Return null character on underflow
    }
    return stack[top--];
}

int is_matching_pair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int is_balanced(char* text) {
    for (int i = 0; i < strlen(text); i++) {
        char ch = text[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)
                return 0;  // No matching opening
            char last = pop();
            if (!is_matching_pair(last, ch))
                return 0;  // Mismatch
        }
    }

    return top == -1;  // Stack should be empty if balanced
}

int main() {
    char str[100];
    printf("Enter an expression: ");
    scanf("%[^\n]", str);

    if (is_balanced(str)) {
        printf("Balanced brackets\n");
    } else {
        printf("Unbalanced brackets\n");
    }

    return 0;
}
