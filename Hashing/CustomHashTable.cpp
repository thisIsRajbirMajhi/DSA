#include <iostream>
#include <functional>
#include <string>
#include <list>
#include <utility>
using namespace std;

const int SIZE = 10;

// One box item in the box's list
struct Node {
    string key;
    int value;
    Node *next;
};

// The table has 10 boxes, each starts with empty (nullptr)
Node *table[SIZE] = {nullptr};

// Hash Function
size_t myHash(const string &key){
    size_t h = 5381;
    for(unsigned char c: key) h = h * 33 + c;
    return h;
}

// PUT: Add a key or update if its already exists
void put(const string& key, int value){
    size_t idx = myHash(key) % SIZE;

    // If key already there, update it!
    for(Node *cur = table[idx]; cur != nullptr; cur = cur->next){
        if(cur->key == key){
            cur->value = value;
            return;
        }
    }

    // Insert the new key at the front of the box list
    Node *n = new Node{key, value, table[idx]};
    table[idx] = n;
}

// GET: Find a key, return true if found
bool get(const string& key, int &result){
    size_t idx = myHash(key) % SIZE;
    for(Node *cur = table[idx]; cur != nullptr; cur = cur->next){
        if(cur->key == key){
            result = cur->value;
            return true;
        }
    }
    return false;
}

// REMOVE: Delete a key and return true if it existed
bool removeKey(const string &key){
    size_t idx = myHash(key) % SIZE;

    Node* cur = table[idx];
    Node* prev = nullptr;

    while(cur != nullptr){
        if(cur->key == key){
            if(prev != nullptr){
                prev->next = cur->next;
            }
            else {
                table[idx] = cur->next;
            }
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void printTable() {
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << i << "] ";
        for (Node* cur = table[i]; cur != nullptr; cur = cur->next)
            cout << "(" << cur->key << ":" << cur->value << ") -> ";
        cout << "null\n";
    }
}

void clearTable() {
    for (int i = 0; i < SIZE; i++) {
        Node* cur = table[i];
        while (cur != nullptr) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        table[i] = nullptr;
    }
}

int main()
{

    put("Alice", 30);
    put("Bob", 40);
    put("Carol", 50);
    put("Alice", 60); // Update Alice
    put("Rushel", 70);
    put("Cat", 80);
    put("Act", 90);
    put("Tic", 100);

    printTable();
    
    


    return 0;

}