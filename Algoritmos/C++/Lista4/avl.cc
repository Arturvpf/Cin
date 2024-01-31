#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};
int search(Node* root, int key, int depth = 0);
int getHeight(Node* node);
int getBalanceFactor(Node* node);
Node* rotateRight(Node* y);
Node* rotateLeft(Node* x);
Node* insert(Node* node, int data);
void inorderTraversal(Node* node);

int main(){
    Node* root=nullptr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x1;
        int x2;
        cin>>x1>>x2;
        
        if(x1==1)
        {
            root=insert(root,x2);
        }
        else
        {
            if(search(root,x2,0)==-1)
                cout<<"Data tidak ada"<<endl;

            else
                cout<<search(root,x2,0)<<endl;
        }
    }

}

int search(Node* root, int key, int depth) {
    // Base case: root is null or key is present at root
    if (root == nullptr)
       return -1;
    if (root->data == key)
       return depth+1;

    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key, depth + 1);

    // Key is smaller than root's key
    return search(root->left, key, depth + 1);
}
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int data) {
    if (node == nullptr) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node; // Duplicates are not allowed
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balanceFactor = getBalanceFactor(node);

    // Left Left Case
    if (balanceFactor > 1 && data < node->left->data) {
        return rotateRight(node);
    }

    // Right Right Case
    if (balanceFactor < -1 && data > node->right->data) {
        return rotateLeft(node);
    }

    // Left Right Case
    if (balanceFactor > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balanceFactor < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorderTraversal(Node* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
}


