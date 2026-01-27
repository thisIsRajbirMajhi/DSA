#include <stdio.h>
#include <stdlib.h>  // DMM
#include <ctype.h>   // character handling
#include <string.h>  // string handling
#include <limits.h>  // data type limits
#include <stdbool.h> // boolean support

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node *front = NULL;
node *rear = NULL;

node *create_node(int data){
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_front(int data){
    node *newNode = create_node(data);
    if(front == NULL){
        front = rear = newNode;
    }else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

void insert_rear(int data){
    node *newNode = create_node(data);
    if(rear == NULL){
        front = rear = newNode;
    }else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

void delete_front(){
    node *temp;
    if(front == NULL){
        return;
    }
    temp = front;
    if(front == rear){
        front = rear = NULL;
    }else {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}

void delete_rear(){
    node *temp;
    if(rear == NULL) return;
    temp = rear;
    if(front == rear){
        front = rear = NULL;
    }else {
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}

int main() {
    
    return 0;
}