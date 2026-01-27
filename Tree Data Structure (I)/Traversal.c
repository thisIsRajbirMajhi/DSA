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

// structure for array based queue
typedef struct Queue {
    node** arr; // array of node pointers
    int front, rear, capacity;
}queue;

node *create_node(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//! Depth First Traversals:
//* Inorder Traversal: (Left -> Root -> Right)
//? For binary tree it gives nodes in ascending order
void inorderTraversal(node *root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

//* Preorder Traversal: (Root -> Left -> Right)
//? Creating a copy of the tree, prefix expression evaluation
void preorderTraversal(node *root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//* Postorder Traversal: (Left -> Right -> Root)
//? Deleting the tree, postfix expression evaluation
void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);     
    postorderTraversal(root->right);    
    printf("%d ", root->data);           
}

/*
    ! Breadth First Traversal: (Level Order)
    * Level Order Traversal:
    ? Level order traversal vistis tree nodes level by level, from left to right at each level. Also called breadth first search (BFS)

                      1
                     / \
                    2   3
                   / \   \
                  4   5   6
                 /
                7

    Level Order Output: 1 2 3 4 5 6 7
    Level 0: 1
    Level 1: 2, 3
    Level 2: 4, 5, 6
    Level 3: 7

    * Working:
    The algorithm uses a queue (FIFO)
    1) Start by adding the root to the queue
    2) While the queue is not empty:
        --> Remove the front node from the queue
        --> Print that node
        --> Add its left child to the queue (if exists)
        --> add its right child to the queue (if exists)
    3) Repeat until queue is empty

    * Dry Run:
    Initial: Queue = [1]

    Step 1: 
        --> Dequeue 1, print 1
        --> Enqueue children: 2, 3
        --> Queue: [2, 3]
    
    Step 2:
        --> Dequeue 2, print 2
        --> Enqueue children: 4, 5
        --> Queue: [3, 4, 5]
    
    Step 3: 
        --> Dequeue 3, print 3
        --> Enqueue children: 6
        --> Queue: [4, 5, 6]
    
    Step 4: 
        --> Dequeue 4, print 4
        --> Enqueue children: 7
        --> Queue: [5, 6, 7]
    
    Step 5:
        --> Dequeue 5, print 5
        --> No children
        --> Queue: [6, 7]

    Step 6: 
        --> Dequeue 6, print 6
        --> No children
        --> Queue = [7]

    Step 7: 
        --> Dequeue 7, print 7
        --> No children
        --> Queue = []
*/

// create queue with given capacity
queue *create_queue(int capacity){
    queue* newQueue = (queue *)malloc(sizeof(queue));
    newQueue->capacity = capacity;
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->arr = (node **)malloc(capacity * sizeof(node *));
    return newQueue;
}

// check if queue is empty
bool isEmpty(queue *q){
    return q->rear < q->front;
}

// check if full
bool isFull(queue *q){
    return q->rear == q->capacity - 1;
}

// add elements to the queue
void enqueue(queue *q, node *n){
    if(isFull(q)){
        printf("Overflow!\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = n;
}

// remove elements from the queue
node* dequeue(queue *q){
    if(isEmpty(q)){
        printf("Underflow!\n");
        return;
    }
    struct Node *n = q->arr[q->front];
    q->front++;
    return n;
}

// level order traversal







int main() {
    
    return 0;
}