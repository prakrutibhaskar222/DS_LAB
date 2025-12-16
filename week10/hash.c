#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m;

/* Function to insert a key using Linear Probing */
void insert(int key) {
    int index = key % m;   // Hash function H(K) = K mod m
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % m;

        if (index == startIndex) {
            printf("Hash Table is full. Cannot insert key %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
}

/* Function to display hash table */
void display() {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] == -1)
            printf("HT[%d] --> EMPTY\n", i);
        else
            printf("HT[%d] --> %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;

    printf("Enter size of Hash Table (m): ");
    scanf("%d", &m);

    // Initialize hash table
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
