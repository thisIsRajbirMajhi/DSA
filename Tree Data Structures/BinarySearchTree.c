#include <stdio.h>
#include <stdlib.h>  // DMM
#include <ctype.h>   // character handling
#include <string.h>  // string handling
#include <limits.h>  // data type limits
#include <stdbool.h> // boolean support

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *newNode (int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insertion
// At every node, one comparision decides the direction.
// For every node all values in the left subtree are smaller and all values in the right subtree are larger.

node *insert(node *root, int value){
    if(root == NULL) return  newNode(value);
    if(value < root->data) root->left = insert(root->left, value);
    else if(value > root->data) root->right = insert(root->right, value);
    return root;
}

// Search
// Same as Insert, until you find it or hit null
node *search(node *root, int value){
    if(root == NULL || root->data == value) return root;
    if(value < root->data) return search(root->left, value);
    return search(root->right, value);
}

/*
    Deletion:     
    
    Case-1: Node to be deleted is the leaf node (simply delete)

    Case-2: Node to be deleted lies has a single child node:
    --> Replace that node with its child node
    --> Remove the child node from its original position

    Case-3: Node to be deleted has two children
    --> Get inorder successor of that node
    --> Replace the node with the inorder successor
    --> Delete the inorder successor from its original position
*/

void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
}

// Find inorder successor


int main() {
    
    return 0;
}