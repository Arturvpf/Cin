#include <stdio.h>

int main() {
    // Create a sample hash table
    struct HashEntry table[100];
    for (int i = 0; i < 100; i++) {
        table[i].index = -1;
    }

    // Set the position to test
    int pos = 42;

    // Set the index to -1 to simulate an empty entry
    table[pos].index = -1;

    // Check if the index is -1
    if (table[pos].index == -1) {
        printf("The entry at position %d is empty.\n", pos);
    } else {
        printf("The entry at position %d is not empty.\n", pos);
    }

    return 0;
}