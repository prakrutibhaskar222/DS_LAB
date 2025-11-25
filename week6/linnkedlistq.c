#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void Enqueue(int item) {
    struct Node *ptr, *temp;
    ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = item;
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
        printf("\nNode inserted\n");
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        printf("\nNode inserted\n");
    }
}

void Dequeue() {
    struct Node *ptr;

    if (head == NULL) {
        printf("\n queue is empty\n");
    } else {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the beginning...\n");
    }
}

void displayList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("queue is empty.\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int x;
    int element;
    printf("\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");

    while (1) {

        printf("Enter your choice: ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                printf("Enter an element to enqueue: ");
                scanf("%d", &element);
                Enqueue(element);
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                displayList();
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
