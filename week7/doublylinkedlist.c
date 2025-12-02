#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void createList(int n) {
    if (n <= 0) {
        printf("Node count must be greater than 0\n");
        return;
    }

    struct Node *temp = NULL;

    for (int i = 1; i <= n; i++) {
        int data;
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
}

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPos(int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position not found\n");
        free(newNode);
        return;
    }

    struct Node *nextNode = temp->next;

    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = newNode;

    if (nextNode != NULL)
        nextNode->prev = newNode;
}

void insertAtLeft(int data, int pos) {
    // left of pos means insert BEFORE pos
    if (pos <= 1) {
        insertAtBeginning(data);
    } else {
        insertAtPos(data, pos - 1);
    }
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

void deleteSpecific(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp == head)
        deleteAtBeginning();
    else if (temp->next == NULL)
        deleteAtEnd();
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, data, pos;
    printf("\n--- Doubly Linked List Menu ---\n");
    printf("1. Create List\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at Position\n");
    printf("4. Insert at Left\n");
    printf("5. Insert at End\n");
    printf("6. Delete at Beginning\n");
    printf("7. Delete by Value\n");
    printf("8. Delete at End\n");
    printf("9. Display List\n");
    printf("10. Exit\n");

    while (1) {
            printf("Enter choice: ");
            scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPos(data, pos);
                break;

            case 4:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtLeft(data, pos);
                break;

            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 6:
                deleteAtBeginning();
                break;

            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteSpecific(data);
                break;

            case 8:
                deleteAtEnd();
                break;

            case 9:
                displayList();
                break;

            case 10:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
