#include <iostream>
#include <string>
#include<algorithm>

using namespace std; // Adicione esta linha

#define TABLE_SIZE 101
#define MAX_KEY_LEN 15

struct Element {
    int index;
    string key; // Agora você pode omitir 
};

Element table[TABLE_SIZE];


int Hash(const string& key); // Agora você pode omitir 

int findi(const string& key);
void insert(const string& key) {  
    int index = Hash(key);
    int pos = index;
    int attempts = 1;
    if (findi(key) == -1) {
        if (table[pos].index == -1) {  
            table[pos].index = pos;  
            table[pos].key = key;
            return;
        } else {
            while (attempts <= 19) {
                pos = (Hash(key) + (attempts * attempts) + 23 * attempts) % 101;
                if (table[pos].index == -1) {  
                    table[pos].index = pos;  
                    table[pos].key = key;
                    return;
                }
                attempts++;
            }
        }
    } else {
        return;
    }
}

int findi(const string& key) {
    int index = 0;
    while (index < TABLE_SIZE) 
    {
        if (table[index].key == key) 
        {
            return index;
        }
        index++;
    }
    return -1;
}

void delkey(const string& key) {
    int pos = findi(key);
    if (pos != -1) {
        table[pos].index = -1;
        table[pos].key = "Cstiliyedas";
    }
}

int Hash(const string& key) {
    long long int h = 0;
    for (int i = 0; i < key.length(); i++) {
        h += (i + 1) * key[i];
    }
    h = h * 19;
    
    return h % 101;
}

void resetTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].index = -1;
        table[i].key = "";
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i].index = -1; 
        }

        int n;
        cin >> n;

        while (n--) {
            string str;
            string operation;
            string key;
            cin >> str;
            size_t pos = str.find(':');
            operation = str.substr(0, pos);
            key = str.substr(pos + 1);
            if (operation == "ADD") {
                insert(key);
            } else if (operation == "DEL") {
                delkey(key);
            }
        }

        int count = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].index >= 0) {
                count++;
            }
        }
        
        cout << count << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].index >= 0) {
                cout << table[i].index << ":" << table[i].key << endl;
            }
        }
        resetTable();
    }

    return 0;
}
