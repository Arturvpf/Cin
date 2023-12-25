#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101

typedef struct Node {
    char* key;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* list[TABLE_SIZE];
} HashTable;

unsigned int hash(char* key) {
    unsigned int h = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        h += (i + 1) * key[i];
    }
    return h % TABLE_SIZE;
}

Node* createNode(char* key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->next = NULL;
    return newNode;
}

void insert(HashTable* table, char* key) {
    unsigned int index = hash(key);
    Node* newNode = createNode(key);
    newNode->next = table->list[index];
    table->list[index] = newNode;
}

Node* search(HashTable* table, char* key) {
    unsigned int index = hash(key);
    Node* temp = table->list[index];
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = table->list[i];
        printf("Index %d: ", i);
        while (temp != NULL) {
            printf("%s -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}