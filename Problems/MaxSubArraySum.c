#include <stdio.h>
#include <stdlib.h>

// Given an array of integers, find the contiguous subarray whose elements have the largest possible sum
void brute_force(int arr[], int size){
    int maxSum = 0;
    for(int i = 0; i < size; i++){
        int currSum = 0;
        for(int j = i + 1; j < size; j++){
            currSum += arr[j];
            if(currSum > maxSum){
                maxSum = currSum;
            } 
        }
    }
    printf("Maximum Sub Array Sum = %d\n", maxSum);
}

// kadane's Algorithm
void improved(int arr[], int size){
    int currSum = arr[0];
    int maxSum = arr[0];
    for(int i = 0; i < size; i++){
        if(currSum + arr[i] > arr[i]){
            currSum = currSum + arr[i];
        }
        else {
            currSum = arr[i];
        }
        if(currSum > maxSum){
            maxSum = currSum;
        }
    }
}

int main() {

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    brute_force(arr, size);



    return 0;
}