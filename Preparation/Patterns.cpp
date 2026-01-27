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

void pattern1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern2(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern3(int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl;

}

void pattern4(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern5(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    pattern1(5);
    pattern2(5);
    pattern3(5);
    pattern4(5);
    pattern5(5);
    return 0;
}