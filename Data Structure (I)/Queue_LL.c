#include <stdio.h>
#include <stdlib.h>  // DMM
#include <ctype.h>   // character handling
#include <string.h>  // string handling
#include <limits.h>  // data type limits
#include <stdbool.h> // boolean support

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *front = NULL;
node *rear = NULL;

int isEmpty(){
    if(front == NULL){
        return 1;
    }
    return 0;
}

void enqueue(int value){
    node *newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL) return;
    newNode->data = value;
    newNode->next = NULL;
    if(rear == NULL){
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    node *temp = NULL;
    if(isEmpty()) return;
    temp = front;
    front = front->next;
    if(front == NULL) rear = NULL;
    free(temp);
}

int main() {
    
    return 0;
}