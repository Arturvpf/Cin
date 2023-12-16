#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left;
  struct node *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf(" %d", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

void printPreOrder(struct node *root) {
  if (root != NULL) {
    printf(" %d", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}
void postorder(struct node *root){
    if(root !=NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d",root->key);
    }
}
// Driver code
int main() {
  struct node *root = NULL;
  int n;
    scanf("%d",&n);
    int vet;
    for(int i=0;i<n;i++){
        scanf("%d",&vet);
        root=insert(root,vet);
    }
    printf("Pre order :");
    printPreOrder(root);
    printf("\nIn order  :");
    inorder(root);
    printf("\nPost order:");
    postorder(root);
}
