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
  return (node);
}

// Right rotate 
 Node *rightRotate(struct Node *y) {
   Node *x = y->left;
   Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
 Node *leftRotate( Node *x) {
   Node *y = x->right;
   Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance( Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert node
Node *insertNode( Node *node, int key) {
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else 
    node->right = insertNode(node->right, key);

    
    updateRank(node);

  node->height = 1 + max(height(node->left),
               height(node->right));

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

Node *minValueNode(Node *node) {
   Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

int findIndex(Node* root, int key, int& index) {
    if (root == NULL) {
        return -1;
    }

    int left = findIndex(root->left, key, index);
    if (left != -1) {
        return left;
    }

    if (root->key == key) {
        return index;
    }
    ++index;

    return findIndex(root->right, key, index);
}

int findKthLargest(Node* root, int k, int parentRank = 0) {
    if (root == NULL) {
        return -1;  // elemento não encontrado
    }

    // O rank do nó atual é a quantidade de nós na sua subárvore direita + 1
    int rank = root->right ? root->right->rank + 1 : 1;

    // Se o rank é k, então encontramos o k-ésimo maior
    if (rank == k) {
        return parentRank + 1;  // retorna o índice do elemento
    }

    // Se o rank é maior que k, o k-ésimo maior está na subárvore direita
    if (rank > k) {
        return findKthLargest(root->right, k, parentRank);
    }

    // Se o rank é menor que k, o k-ésimo maior está na subárvore esquerda
    // Note que precisamos ajustar k porque estamos descartando rank nós da busca
    return findKthLargest(root->left, k - rank, parentRank + rank);
}


int main() {
  Node *root = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x1;
        int x2;
        cin>>x1>>x2;
        
        if(x1==1)
        {
            root=insertNode(root,x2);
        }
        else
        {
           int index = findKthLargest(root, x2);
            if (index != -1) {
                cout <<index << endl;
            } else {
                cout << "Data tidak ada" << endl;
            }   
        }

    }


  return 0;
}
/*10
1 100
1 74
2 100
2 70
1 152
1 21
1 33
2 100
2 21
2 1*/


