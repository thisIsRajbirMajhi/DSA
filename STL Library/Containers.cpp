// I/O
#include <iostream>
#include <iomanip>

// Data Structures
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// Algorithms
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <cfloat>

// Utilities
#include <utility>
#include <functional>

using namespace std;

int main(){
    
    /*
        ! Sequential Containers: 
        ? Vector: 
        --> Contiguous memory array with capacity management
        ? Deque (Double-ended-queue):
        --> Array of fixed-size arrays (map of blocks)
        --> Allows efficient insertion/deletion at both ends
        ? List:
        --> Doubly Linked List
        ? Forward List:
        --> Singly Linked List
        ! Associative Containers:
        ? set/multiset:
        --> Red-Black tree (self balancing bst)
        --> Maintains sorted order automatically
        ? map/multimap:
        --> Red-Black tree of key-value pairs
        ! Unordered Associative Containers:
        ? unordered_set/unordered_multiset: (hash based set)
        --> Hash table with buckets (array of linked lists)
        ? unorederd_map/unordered_multimap: (hash based map)
        --> Hash table storing key-value pairs
        ! Container Adapters:
        ? Stack: LIFO
        --> Usually wraps deque or vector
        ? Queue: FIFO
        --> Usually wraps deque
        ? Priority_Queue: Heap based priority queue
        --> Underlying binary heap
    */

    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    vec[1] = 56;
    vec.insert(vec.begin() + 1, 15);

    cout << vec.front() << endl;
    cout << vec.back() << endl;
    cout << vec.size() << endl;

    vec.pop_back();
    
    set<int> s;
    s.insert(30);
    s.insert(10); // auto sorted
    s.insert(20);
    s.insert(10); // duplicate ignored

    if(s.find(10) != s.end()){
        cout << "Found 10\n";
    }

    if(s.count(30)){
        cout << "30 exists\n";
    }

    multiset<int> ms; // sorted but duplicates allowed
    ms.insert(10);
    ms.insert(10);
    ms.insert(30);
    ms.insert(20);

    cout << ms.count(10) << endl;
    


    return 0;
}