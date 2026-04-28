/*
    * A heap is a complete binary tree that satisfies a specific ordering property.

    ? Structural Property: 
    -> All levels are filled except possibly last
    -> Last level filled from left to right
    -> Enables array representation

    ? Types:
    -> Min Heap: Parent < Children (Root = Minimum element)
    -> Max Heap: Parent > Children (Root = Maximum element)

    ? Array Representation:
    Left Child = 2 * i + 1
    Right Child = 2 * i + 2
    Parent = (i - 1) / 2

    ? Core Operations:
    1) Insertion: 
    -> Insert new element at the end (to maintain complete tree)
    -> Apply Heapify Up:
        -> Compare with its parent
        -> If heap property is violated -> Swap
        -> Repeat until property is satisfied or root is reached
    -> O(log n)

    2) Deletion:
    -> Remove the root (min or max)
    -> Replace root with last element
    -> Apply Heapify Down:
        -> Always compare with smaller/larger child based on heap type (min or max)
        -> Compare node with both children
        -> If child is smaller -> Swap
        -> Move downward
    -> O(log n)

    ? Heapify:
    It is a restoration algorithm, not an operation
*/
#include <stdio.h>
#define MAX 100

/*
    * ==================================== *
    * =                                  = *
    * =            MIN HEAP              = *
    * =                                  = *
    * ==================================== *
*/

typedef struct {
    int arr[MAX];
    int size;
}minHeap;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Min_Heapify_Up(minHeap *h, int idx){
    while(idx > 0){
        int parent = (idx - 1) / 2;
        if(h->arr[parent] > h->arr[idx]){
            swap(&h->arr[parent], &h->arr[idx]);
            idx = parent;
        } else {
            break;
        }
    }
}

void Min_Heapify_Down(minHeap *h, int idx){
    while(1){
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if(left < h->size && h->arr[left] < h->arr[smallest]) smallest = left;
        if(right < h->size && h->arr[right] < h->arr[smallest]) smallest = right;
        if(smallest != idx){
            swap(&h->arr[idx], &h->arr[smallest]);
            idx = smallest;
        }else {
            break;
        }
    }
}

// Insert Into Min Heap
void Min_Insert(minHeap *h, int value){
    if(h->size == MAX){
        printf("Min Heap Overflow!");
        return;
    }
    h->arr[h->size] = value;
    h->size++;
    Min_Heapify_Up(h, h->size - 1);
}

// Delete (Root)
int Min_Delete(minHeap *h){
    if(h->size == 0){
        printf("Min Heap Underflow\n");
        return -1;
    }

    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    Min_Heapify_Down(h, 0);
    return root;
}

int Min_Peek(minHeap *h){
    if(h->size == 0) return -1;
    return h->arr[0];
}

// Print
void Print_Min_Heap(minHeap *h){
    for(int i = 0; i < h->size; i++){
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}
int main(){
    minHeap mh1;
    mh1.size = 0;

    int values[] = {10, 5, 20, 2, 30, 15};
    int n = sizeof(values)/sizeof(values[0]);

    for(int i = 0; i < n; i++){
        Min_Insert(&mh1, values[i]);
    }

    printf("Min Heap: ");
    Print_Min_Heap(&mh1);

    printf("Deleted: %d\n", Min_Delete(&mh1));
    Print_Min_Heap(&mh1);

    printf("Peek: %d\n", Min_Peek(&mh1));

    return 0;
}
