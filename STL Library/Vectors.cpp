#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Passing Vector to Functions
//? pass by value (Copy)
void processVector(vector <int> v){
    v.push_back(202); // original vector unchanged
}

//? pass by reference
void modifyVector(vector <int> &v){
    v.push_back(34);
}

//? pass by constant referecne
void readVector(const vector <int> &v){
    // can read but cannot modify
    for(int num: v){
        cout << num << " ";
    }
}

//? pass by pointer
void updateVector(vector <int> *v){
    if(v != nullptr){
        v->push_back(55);
    }
}

//? pass by const reference
void displayVector(const vector <int> *v){
    if(v != nullptr){
        for(int num: *v){
            cout << num << " ";
        }
    }
}

int main(){

    // Usage:
    vector <int> v = {78, 12, 45, 90};
    processVector(v); // expensive, copies entire vector
    modifyVector(v); // efficient, no copy
    readVector(v);
    updateVector(&v); // pass address of vector
    displayVector(&v);

    // Initializations & Declarations:

    vector <int> num; // creates an empty vector
    vector <int> v1(5); // 5 elements, default: 0
    vector <int> v2(5, 100); // 5 eleemnts, default: 100
    vector <int> v3{1, 2, 3, 56, 78}; // uniform initialization with specific values
    vector <int> v4 = {67, 213, 12, 98, 42}; // list initialization
    vector <int> v5(v4); // copy constructor
    vector <int> V6 (v5.begin(), v5.end()); // range constructor

    // Adding elements:
    num.push_back(10); // add element at the end
    num.emplace_back(67); // construct elelemnt in place at the end (more efficient)
    num.insert(num.begin(), 4); // insert 5 at beginning
    num.insert(num.begin() + 2, 78); // insert 78 at index 2
    num.insert(num.begin() + 3, {12, 56, 8, 101}); // insert multiple elelemnts at index 3

    // Read Operations:
    int first = num[0]; // no bounds checking
    int second = num.at(1); // with bounds checking
    int first_element = num.front();  
    int last_element = num.back();  
    int *ptr = num.data(); // pointer to underlying array

    // Iterating:
    //? Using index
    for(size_t i = 0; i < num.size(); i++){
        cout << num[i] << " ";
    }

    //? using iterators
    for(auto i = num.begin(); i != num.end(); i++){
        cout << *i << " ";
    }

    //? ranged-based for loop
    for(int n: num){
        cout << n << " ";
    }

    //? with references to modify
    for(int &n: num){
        n = n * 2;
        cout << n << " ";
    }

    // Chcking Size/Status:
    size_t count = num.size(); // number of elements
    size_t space = num.capacity(); // allocated capacity
    bool isEmpty = num.empty(); 
    size_t max = num.max_size(); // maximum possible size

    // Searching:
    auto it = find(num.begin(), num.end(), 99);
    if(it != num.end()){
        cout << "Found at index: " << (it - num.begin());
    }

    return 0;
}