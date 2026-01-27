#include <stdio.h>
#include <stdlib.h>  // DMM
#include <ctype.h>   // character handling
#include <string.h>  // string handling
#include <limits.h>  // data type limits
#include <stdbool.h> // boolean support

const int size = 50;
int queue[size];
int front = -1, rear = -1;

void enqueue(int value){
    if((rear + 1) % size == front) return;
    if(front == -1) front = 0;
    rear = (rear + 1) % size;
    queue[rear] = value;
}

void dequeue(){
    if(front == -1) return;
    if(front == rear) front = rear = -1;
    else {
        front = (front + 1) % size;
    }
}

void display(){
    int i;
    if(front == -1) return;
    i = front;
    while(1){
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    
    return 0;
}