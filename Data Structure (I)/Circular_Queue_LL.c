#include <stdio.h>
#include <stdlib.h>  // DMM
#include <ctype.h>   // character handling
#include <string.h>  // string handling
#include <limits.h>  // data type limits
#include <stdbool.h> // boolean support

typedef struct Node {
    int data;
    struct Node *next;
}node;

node *front = NULL;
node *rear = NULL;

node *create_node(int data){
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode){
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data){
    node *newNode = create_node(data);
    if(newNode == NULL){
        printf("Queue overflow (Memory Full)\n");
        return;
    }
    if(front == NULL){ // if empty and first insertion
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void dequeue(){
    if(front == NULL) return;
    if(front == rear){
        free(front);
        front = rear = NULL;
    } else {
        node *temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display(){
    node *temp = NULL;
    if(front == NULL){return;}
    temp = front;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != front);
    printf("\n");
}

int main() {
    
    return 0;
}