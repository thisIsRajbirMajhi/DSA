
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

// Traversals
void InorderTraversal(node *root){ // gives sorted output for BST
    if(root == NULL) return;
    InorderTraversal(root->left);
    printf("%d -> ", root->data);
    InorderTraversal(root->right);
}

void PreorderTraversal(node *root){
    if(root == NULL) return;
    printf("%d -> ", root->data);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void PostorderTraversal(node *root){
    if(root == NULL) return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf("%d -> ", root->data);
}

void LevelOrderTraversal(node *root){
    if(root == NULL) return;
    int cap = 1000;
    node **queue = (node **)malloc(sizeof(node *) * cap);
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear)
    {
        node *curr = queue[front++];
        printf("%d -> ", curr->data);
        if(curr->left) queue[rear++] = curr->left;
        if(curr->right) queue[rear++] = curr->right;
    }
}

// Height of a tree
// Longest path from root to any leaf. At every node, you ask both subtrees "how tall are you?" and take the taller one, then add 1 for the current node.
int height(node *root){
    if(root == NULL) return 0;
    int leftHight =  height(root->left);
    int rightHight =  height(root->right);
    return 1 + (leftHight > rightHight ? leftHight : rightHight);
}

// Count number of nodes
// Every node contributes 1 to the count. Ask left and right subtrees for their counts, add them together, add 1 for yourself.
int countNode(node *root){
    if(root == NULL) return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}

// Count leaf nodes
// A leaf node is a node with no children. Detect if before recursing. If both children are null return 1 Immeadiately.
int countLeaves(node *root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);   
}

// Sum of all nodes
// Same as countNodes, just replace the 1 with root->data
int sumNodes(node *root){
    if(root == NULL) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// Mirror a tree
// At every node, swap its left and right children, then recurse into both.
void mirror(node *root){
    if(root == NULL) return;
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder successor: It is the node that comes Immeadiately after the given node in the Inorder traversal of the tree. 

/*
    BST:
    5 --> 10 --> 15 --> 20 --> 25 --> 30 --> 35
    Successor of 10 = 15
    Successor of 20 = 25

    Rule 1: If right child exists
    Go right once, then go left as much as possible

    Rule 2: If no right child
    Go upward and find the first parent where you came from the left
*/

// Find leftmost node
node *findMin(node *root){
    while(root->left != NULL) root = root->left;
    return root;
}

// Find Inorder successor
node *InorderSuccessor(node *root, node *target){
    // Rule: 1
    if(root->right != NULL) return findMin(root->right);

    // Rule: 2
    node *successor = NULL;
    while(root != NULL){
        if(target->data < root->data){
            successor = root;
            root = root->left;
        } else if(target->data > root->data){
            root = root->right;
        }else {
            break;
        }
    }

    return successor;
}

int main() {
    
    node *root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);

    printf("Inorder: "); InorderTraversal(root); printf("\n");
    printf("Preorder: "); PreorderTraversal(root); printf("\n");
    printf("Postorder: "); PostorderTraversal(root); printf("\n");
    printf("Levelorder: "); LevelOrderTraversal(root); printf("\n");
    
    printf("Height of tree: %d\n", height(root));
    printf("Number of nodes: %d\n", countNode(root));
    printf("Number of leaves: %d\n", countLeaves(root));
    printf("Sum of nodes: %d\n", sumNodes(root));
    
    mirror(root);
    
    printf("Mirror Inorder: "); InorderTraversal(root); printf("\n");
    printf("Mirror Preorder: "); PreorderTraversal(root); printf("\n");
    printf("Mirror Postorder: "); PostorderTraversal(root); printf("\n");
    printf("Mirror Levelorder: "); LevelOrderTraversal(root); printf("\n");

    return 0;
}