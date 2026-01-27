#include <stdio.h>
#include <stdlib.h>  // DMM
#include <ctype.h>   // character handling
#include <string.h>  // string handling
#include <limits.h>  // data type limits
#include <stdbool.h> // boolean support

const int size = 50;
int stack[size];
int top = -1;

bool is_empty(){
    return top == -1;
}

bool is_full(){
    return top == size - 1;
}

int peek(){
    return stack[top];
}

void push(int value){
    if(is_full()) return;
    stack[++top] = value;
    printf("Pushed: %d\n", value);
}

void pop(){
    if(is_full()) return;
    int popped_value = stack[top--];
    printf("Popped: %d\n", popped_value);
}

void display(){
    if(is_empty()) return;
    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    return 0;
}