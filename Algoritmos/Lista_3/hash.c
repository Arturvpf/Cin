#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101
#define MAX_KEY_LEN 15

typedef struct {
    int index;
    char key[MAX_KEY_LEN + 1];
} Element;

Element table[TABLE_SIZE];

int Hash(char* key);

int findi(char *key);
void insert(char* key) {  
    int index = (Hash(key));
    int pos = index;  //funcao hashing
    int attempts = 1;
    if(findi(key) == -1)
    {
        if (table[pos].index == -1 ) 
        {  
            table[pos].index = pos;  
            strcpy(table[pos].key, key);
            return;
        }
        else
        {
            while (attempts <= 19) 
            { 

                pos=(Hash(key)+(attempts*attempts)+23*attempts)%101;
                if (table[pos].index == -1 ) 
                {  
                    table[pos].index = pos;  
                    strcpy(table[pos].key, key);
                    return;
                }
                attempts++;
            }
        }
    }
    else return;
}

int findi(char*key){
    int index=0;
    while(index < TABLE_SIZE)
    {
        if(strcmp(table[index].key, key) == 0)
        {
            return index;
        }
        else{
            index++;
        }
    }
    return -1;

}

void delkey(char* key) {
    int pos = findi(key);
    if (pos != -1) { //isso aq
        table[pos].index = -1;
        strcpy(table[pos].key,"Cstiliyedas");
    }
}

int Hash(char* key) {
    long long int h = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        h += (i + 1) * key[i];
    }
    h = h * 19;
    long long int hashValue = h;
    
    return hashValue%101;
}
void resetTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].index = -1;
        strcpy(table[i].key, "");
    }
}




int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i].index = -1; 
        }

        int n;
        scanf("%d", &n);

        while (n--) {
            char operation[4];
            char key[MAX_KEY_LEN + 1];
            scanf("%3s:%15s", operation, key);

            if (strcmp(operation, "ADD") == 0) {
                insert(key);
            } else if (strcmp(operation, "DEL") == 0) {
                delkey(key);
            }
        }

        int count = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].index >= 0) {
                count++;
            }
        }
        
            printf("%d\n", count);
            for (int i = 0; i < TABLE_SIZE; i++) {
                if (table[i].index >= 0) {
                    printf("%d:%s\n", table[i].index, table[i].key);
                }
            }
        resetTable();
    }

    return 0;
}