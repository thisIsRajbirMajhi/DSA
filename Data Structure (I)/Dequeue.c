#include <stdio.h>
#include <stdlib.h>  // DMM
#include <ctype.h>   // character handling
#include <string.h>  // string handling
#include <limits.h>  // data type limits
#include <stdbool.h> // boolean support

const int size = 50;
int dequeue[size];
int front = -1;
int rear = -1;

void enqueue(int value){
    // array is coccupied linearly & crircular wrap around full
    if((front == 0 && rear == size - 1) || (front == rear + 1)){
        printf("Overflow!\n");
        return;
    }   
    if(front == -1){ // empty queue
        front = rear = 0;
    } else if (front == 0) { // wrap around case
        front = size - 1;
    } else { // space exists before front
        front --;
    }
    dequeue[front] = value;
}

void insert_rear(int value){
    if((front == 0 && rear == size - 1) || (front == rear + 1)){
        printf("Overflow!\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    } else if (rear == size - 1){ // rear is at the end of the array
        rear = 0;
    } else { // sapce exists after the current rear
        rear ++;
    }
    dequeue[rear] = value;
}

void delete_front(){
    if(front == -1){
        printf("Underflow!\n");
        return;
    }
    printf("Deleted: %d\n", dequeue[front]);
    if(front == rear){ // only one element present
        front = rear = -1;
        printf("Dequeue is empty now!\n");
    } else if(front == size - 1){ // front pointer is at end of the array
        front = 0;
    } else {
        front++;
    }
}

void delete_rear(){
    if(front == -1){
        printf("Underflow!\n");
        return;
    }
    printf("Deleted: %d\n", dequeue[rear]);
    if(front == rear){
        front = rear = -1;
    } else if(rear == 0){
        rear = size - 1;
    } else {
        rear--;
    }
}


int main() {
    
    return 0;
}