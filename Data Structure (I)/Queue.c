#include <stdio.h>
#include <stdlib.h>  // DMM
#include <ctype.h>   // character handling
#include <string.h>  // string handling
#include <limits.h>  // data type limits
#include <stdbool.h> // boolean support

const int size = 50;
int queue[size];
int front = -1, rear = -1;

int isFull(){
    return rear == size - 1;
}

int isEmpty(){
    return (front == -1 || front > rear);
}

void enqueue(int value){
    if(isFull()) return;
    if(front == -1) front = 0;
    queue[rear++] = value;
}

void dequeue(){
    if(isEmpty()) return;
    printf("Deleted: %d\n", queue[front]);
    front++;
    if(front > rear){
        front = rear = -1;
    }
}

void display(){
    if(isEmpty()) return;
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void peek(){
    if(isEmpty()) return;
    printf("Front Element: %d\n", queue[front]);
}

int main() {
    
    return 0;
}