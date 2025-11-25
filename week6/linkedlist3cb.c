#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create Linked List
void createList(int n) {
    struct Node *newNode, *temp = NULL;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode; // first node
        } else {
            temp->next = newNode; // link
        }
        temp = newNode;
    }

    printf("\nLinked list created.\n");
}

// Bubble sort
void sort() {
    if (head == NULL) return;

    int swapped;
    struct Node* ptr;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;

    } while (swapped);

    printf("List sorted.\n");
}

// Reverse linked list
void reverse() {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    printf("List reversed.\n");
}

// Concatenate another list
void concat() {
    int n, data;
    struct Node *newNode, *head2 = NULL, *temp2 = NULL;

    printf("Enter number of nodes for second list: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Second list is empty. Nothing to concatenate.\n");
        return;
    }

    // Create second list
    for (int i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head2 == NULL)
            head2 = newNode;
        else
            temp2->next = newNode;

        temp2 = newNode;
    }

    // If first list is empty
    if (head == NULL) {
        head = head2;
        printf("Lists concatenated.\n");
        return;
    }

    // Otherwise, attach list 2 at end of list 1
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    printf("Lists concatenated.\n");
}


// Display
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
    int choice, n;

    printf("\n--- Singly Linked List Operations ---\n");
    printf("1. CREATE\n");
    printf("2. SORTING\n");
    printf("3. REVERSING\n");
    printf("4. CONCATENATION\n");
    printf("5. DISPLAY\n");
    printf("6. EXIT\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                sort();
                break;

            case 3:
                reverse();
                break;

            case 4:
                concat();
                break;

            case 5:
                displayList();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
