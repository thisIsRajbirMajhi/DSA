#include <stdio.h>
#include <stdlib.h>

// Array notation: Decays to pointer
void method_one(int arr[], int size){
    for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
}

// Passing with fixed size: same
void method_two(int arr[5], int size){
    for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
}

// Pointer notation
void method_three(int *arr, int n){
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
}

int main() {

    return 0;
}