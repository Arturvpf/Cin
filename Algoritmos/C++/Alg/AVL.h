#ifndef AVL_H
#define AVL_H

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

#endif // AVL_H





