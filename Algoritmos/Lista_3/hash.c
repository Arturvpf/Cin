#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 101
#define max_s 16

typedef struct {
    int index;
    char key[max_s + 1];
} Element;

int Hash(char* key) {
    int h = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        h += (i + 1) * key[i];
    }
    return (19 * h) % TABLE_SIZE;
}

void insert(Element table[], char* key) {
    int index = Hash(key);
    int j = 0;
    while (j < 20) { 
        int pos = (index + j * j + 23 * j) % TABLE_SIZE;
        if (table[pos].index == -1) {
            table[pos].index = pos;
            strncpy(table[pos].key, key, sizeof(table[pos].key) - 1);
            table[pos].key[sizeof(table[pos].key) - 1] = '\0'; 
            return;
        } else if (strcmp(table[pos].key, key) == 0) {
            
            return;
        }
        j++;
    }
}

void delete(Element table[], char* key) {
    int index = Hash(key);
    int j = 0;
    while (j < 20) {
        int pos = (index + j * j + 23 * j) % TABLE_SIZE;
        if (strcmp(table[pos].key, key) == 0) {
            
            table[pos].index = -1;
            table[pos].key[0] = '\0'; 
            return;
        }
        j++;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    int j=0;
    while (j<t) {
        Element table[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i].index = -1;
        }
        int n;
        scanf("%d", &n);
        char op[max_s + 5]; 
        while (n--) {
            scanf("%s", op);
            char* key = op + 4; 
            if (strncmp(op, "ADD:", 4) == 0) {
                insert(table, key);
            } else if (strncmp(op, "DEL:", 4) == 0) {
                delete(table, key);
            }
        }
        int count = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].index != -1) {
                count++;
            }
        }
        printf("%d", count);
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].index != -1) {
                printf("\n%d:%s", i, table[i].key);
            }
        }
        j++;
    }
    return 0;
}