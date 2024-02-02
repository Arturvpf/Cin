#include <iostream>
using namespace std;

// Create Node
struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
    int rank;
};

int max(int a, int b);

void updateRank(Node* node) {
    node->rank = 1;  // conta o próprio nó
    if (node->left != NULL) {
        node->rank += node->left->rank;
    }
    if (node->right != NULL) {
        node->rank += node->right->rank;
    }
}

int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node *newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    node->rank = 1; // Inicializa o rank com 1
    return (node);
}

Node *rightRotate(struct Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Atualiza ranks após a rotação
    updateRank(y);
    updateRank(x);

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Atualiza ranks após a rotação
    updateRank(x);
    updateRank(y);

    return y;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insertNode(Node *node, int key) {
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else
        node->right = insertNode(node->right, key);

    // Atualiza rank após a inserção
    updateRank(node);

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key >= node->right->key)
        return leftRotate(node);

    if (balance > 1 && key >= node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int calcularRank(Node *node, int key, int rankAtual = 1) {
    if (node == NULL) {
        return -1; // chave não encontrada
    }

    if (key < node->key) {
        return calcularRank(node->left, key, rankAtual); // continue procurando à esquerda
    } else if (key > node->key) {
        int rankEsquerda = (node->left != NULL) ? node->left->rank : 0;
        if (node->right != NULL) {
            rankAtual += rankEsquerda + 1; // Adiciona o rank da subárvore esquerda e a raiz atual
        } else {
            rankAtual += rankEsquerda;
        }
        return calcularRank(node->right, key, rankAtual); // continue procurando à direita
    } else {
        // Chave encontrada
        return rankAtual + ((node->left != NULL) ? node->left->rank : 0);
    }
}

int main() {
    Node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1;
        int x2;
        cin >> x1 >> x2;

        if (x1 == 1) {
            root = insertNode(root, x2);
        } else {
            int index = calcularRank(root, x2);
            if (index != -1) {
                cout << index << endl; // imprime o índice corrigido
            } else {
                cout << "Data tidak ada" << endl;
            }
        }
    }

    return 0;
}
