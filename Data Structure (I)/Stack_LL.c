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

node *top = NULL;

void push(int value){
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode == NULL){
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

int pop(){
    if(top == NULL) return -1;
    node *temp = top;
    int popped = temp->data;
    top = temp->next;
    free(temp);
    return popped;
}

int peek(){
    if(top == NULL) return -1;
    return top->data;
}

void display(){
    if(top == NULL) return;
    node *temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    
    return 0;
}