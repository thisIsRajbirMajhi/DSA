#include <stdio.h>
#include <stdlib.h>  // DMM
#include <ctype.h>   // character handling
#include <string.h>  // string handling
#include <limits.h>  // data type limits
#include <stdbool.h> // boolean support
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion(int arr[], int *size, int pos, int value){
    for(int i = *size; i > pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
}

void deletion(int arr[], int *size, int pos){
    for(int i = pos; i < *size - 1; i++){
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void reverse(int arr[], int size){
    int start = 0;
    int end = size - 1;
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Find Min and Max:
//? Iterative Approach (Sorted + Unsorted)
void MinMax_Iterative(int arr[], int size){
    int min = arr[0];
    int max = arr[0];

    for(int i = 1; i < size; i ++){
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    printf("Min: %d\n", (min));
    printf("Max: %d\n", (max));
}

// Counting occurances: 
//? Using frequency array
void count_freqArray(int arr[], int size){
    int freq[100] = {0};
    for(int i = 0; i < size; i++){
        freq[arr[i]]++;
    }
    for(int i = 0; i < size; i++){
        if(freq[i] > 0){
            printf("%d occurs %d times\n", i, freq[i]);
        }
    }
}   

//? Brute Force
void count_bruteForce(int arr[], int size){
    int visited[size];
    for(int i = 0; i < size; i++){
        visited[i] = 0;
    }
    for(int i = 0; i < size; i++){
        if(visited[i]) continue;;
        int count = 1;
        for(int j = i + 1; j < size; j++){
            if(arr[i] == arr[j]){
                count++;
                visited[j] = 1;
            }
        }
        printf("%d occurs %d times\n", arr[i], count);
    }
}

//? Using Hash Table (unordered_map)
void count_hashTable(int arr[], int size){
    unordered_map<int, int> freq; 
    map<int, int> count;
    for(int i = 0; i < size; i++){
        freq[arr[i]]++;
        count[arr[i]]++;
    }
    for(auto it: freq){
        cout << it.first << " occurs " << it.second << " times" << endl;
    }
    cout << endl;
    for(auto it: count){
        cout << it.first << " occurs " << it.second << " times" << endl;
    }
    cout << endl;
}


int main() {
    int arr[] = {25, 11, 10, 10, 10, 11, 20, 40, 40, 50, 25, 25};
    int size = sizeof(arr) / sizeof(arr[0]);

    count_hashTable(arr, size);


    return 0;
}