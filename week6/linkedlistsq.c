#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void Pop() {
    struct Node *temp;
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = head;
        head = temp->next;
        free(temp);
        printf("\nNode deleted from the beginning...\n");
    }
}

void displayList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    int element;
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to push (integer): ");
                scanf("%d", &element);
                push(&head, element);   // FIXED
                break;

            case 2:
                Pop();   // FIXED - correct function name
                break;

            case 3:
                displayList();   // FIXED name
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Wrong choice! Please try again.\n");
                break;
        }
    }
    return 0;
}
