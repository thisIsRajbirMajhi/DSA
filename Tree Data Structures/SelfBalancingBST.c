#include <stdio.h>
#include <stdlib.h>

// Node Definition
typedef struct Node {
    int data;
    struct Node *left, *right;
    int height;
} node;

// Utility
int find_max(int a, int b) {
    return (a > b) ? a : b;
}

int height(node *n){
    if(n == NULL) return -1;
    return n->height;
}

// Create Node
node *create_node(int value){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

// Rotations
node *RightRotate(node *y){ 
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + find_max(height(y->left), height(y->right));
    x->height = 1 + find_max(height(x->left), height(x->right));

    return x;
}

node *LeftRotate(node *x){
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + find_max(height(x->left), height(x->right));
    y->height = 1 + find_max(height(y->left), height(y->right));

    return y;
}

node *LeftRightRotate(node *n){
    n->left = LeftRotate(n->left);
    return RightRotate(n);
}

node *RightLeftRotate(node *n){
    n->right = RightRotate(n->right);
    return LeftRotate(n);
}

// Balance Factor
int GetBalance(node *root){
    if(root == NULL) return 0;
    return height(root->left) - height(root->right);
}

// Insert
node *Insert(node *root, int key){
    if(root == NULL) return create_node(key);

    if(key < root->data) root->left = Insert(root->left, key);
    else if(key > root->data) root->right = Insert(root->right, key);
    else return root;

    root->height = 1 + find_max(height(root->left), height(root->right));

    int balance = GetBalance(root);
    if(balance > 1 && key < root->left->data) return RightRotate(root);
    if(balance < -1 && key > root->right->data) return LeftRotate(root);
    if(balance > 1 && key > root->left->data) return LeftRightRotate(root);
    if(balance < -1 && key < root->right->data) return RightLeftRotate(root);
    return root;
}

// Traversal
void InorderTraversal(node *root){
    if(root == NULL) return;
    InorderTraversal(root->left);
    printf("%d ", root->data);
    InorderTraversal(root->right);
}

void PreorderTraversal(node *root){
    if(root == NULL) return;
    printf("%d ", root->data);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

// Test
int main() {
    node *root = NULL;
    int arr[] = {30, 10, 20, 40, 60, 12, 50, 25, 32, 27, 70};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Inserting eleemnts:\n");
    for(int i = 0; i < n; i++){
        printf("\nInsert %d:\n", arr[i]);
        root = Insert(root, arr[i]);

        printf("Preorder: ");
        PreorderTraversal(root);
        printf("\n");
    }

    printf("\nFinal Tree\n");
    PreorderTraversal(root);
    printf("\n");
}