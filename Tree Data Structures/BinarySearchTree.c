#include <stdio.h>
#include <stdlib.h>  // DMM
// #include <ctype.h>   // character handling
// #include <string.h>  // string handling
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
// Utility function to do inorder traversal of BST 
void inorder(node *root){
    if(root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

// Find minimum value node (Inorder Successor)
node *MinValueNode(node *root){
    node *current = root;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

node *delete(node *root, int key){
    // base case
    if(root == NULL) return root;

    // If key to be deleted is less than the root's key then it lies in left subtree
    if(key < root->data){
        root->left = delete(root->left, key);
    }

    // if the key is greater than root's key
    else if(key > root->data){
        root->right = delete(root->right, key);
    }

    // if the key is same as root's key
    else {
        // node with only one child or no child
        if(root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: inorder successor
        node *temp = MinValueNode(root->right);
        // copy the inorder to this node
        root->data = temp->data;
        // delete the inorder 
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main() {
    
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nDelete 20\n");
    root = delete(root, 20);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nDelete 30\n");
    root = delete(root, 30);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nDelete 50\n");
    root = delete(root, 50);
    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}