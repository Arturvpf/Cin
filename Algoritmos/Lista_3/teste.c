#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int key[16];
    struct Node* next;
} Node;

// Define the structure for the linked list
typedef struct List {
    Node* head;
}List;
typedef struct Dictionary{
    int m;
    int cnt;
    List *H;
    int h;
}Dictionary;
int h(char *key){
    int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue += (i + 1) * key[i];
    }
    return 19 * hashValue;
}
Dictionary createDictionary(int size,int h) {
    Dictionary d;
    d.m = size;
    d.cnt = 0;
    d.H = (List*)malloc(size * sizeof(List));

    for (int i = 0; i < size; i++) {
        d.H[i] = *createList();
    }
    d.h=h;

    // Implemente a função de hash, se necessário

    return d;
}
List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

// Insert an element at the beginning of the list
void insert(List* list, char *value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, value);
    newNode->next = list->head;
    list->head = newNode;
}

// Remove an element from the list
void removeElement(List* list, int value) {
    Node* currentNode = list->head;
    Node* prevNode = NULL;

    while (currentNode != NULL && currentNode->key!= value) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode != NULL) {
        if (prevNode == NULL) {
            list->head = currentNode->next;
        } else {
            prevNode->next = currentNode->next;
        }
        free(currentNode);
    }
}

// Print the elements in the list
void displayList(List* list) {
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->key);
        currentNode = currentNode->next;
    }
}

// Clear the entire list
void clearList(List* list) {
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    list->head = NULL;
}

int main() {
    List* myList = createList();
    int n;
    scanf("%d",&n);
    char 
    for(int i=0;i<n;i++){

    }
    

    return 0;
}
