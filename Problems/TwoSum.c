#include <stdio.h>
#include <stdlib.h>

// Problem: Given an array and a target, return indices of two numbers that add up to target.
// Easy idea: For each number x, you need target - x. Have you seen it before?

// Brute Force: 
// Check every pair
// Time: O(n^2), Space: O(1)

void brute_force(int arr[], int size, int target){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] + arr[j] == target){
                printf("arr[%d] + arr[%d] = %d + %d = %d\n", i, j, arr[i], arr[j], target);
            }
        }
    }
}

// Sorting + Two Pointer
// Store the value + Original Index
// Sort --> Move the pointers

void twoSum(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;

    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            printf("arr[%d] + arr[%d] = %d + %d = %d\n",
                left, right,
                arr[left], arr[right],
                target);
            return;
        }
        else if(sum < target){
            left++;
        }
        else {
            right--;
        }
    }
    
    printf("No pair found\n");
}

int main() {

    int arr[5] = {2, 7, 11, 15};
    int target = 15;
    int size = sizeof(arr) / sizeof(arr[0]);

    brute_force(arr, size, target);
    twoSum(arr, size, target);



    return 0;
}