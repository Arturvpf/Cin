#include <iostream>
using namespace std;

struct Node 
{
    int key;
    Node* left;
    Node* right;
};

// Create a node
Node* newNode(int item) 
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

// Inorder Traversal
void inorder(Node* root) 
{
    if (root != nullptr) 
    {
        inorder(root->left);
        cout << " " << root->key;
        inorder(root->right);
    }
}

// Insert a node
Node* insert(Node* node, int key) 
{
    if (node == nullptr) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

void printPreOrder(Node* root) 
{
    if (root != nullptr)
    {
        cout << " " << root->key;
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void postorder(Node* root)
{
    if(root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << " " << root->key;
    }
}

// Driver code
int main() 
{
    Node* root = nullptr;
    int n;
    cin >> n;
    int vet;
    string str;

    for(auto i=0; i<n; i++)
    {
        cin >> vet;
        root = insert(root, vet);
    }

    cout << "Pre order :";
    printPreOrder(root);

    cout << "\nIn order  :";
    inorder(root);
    
    cout << "\nPost order:";
    postorder(root);
}