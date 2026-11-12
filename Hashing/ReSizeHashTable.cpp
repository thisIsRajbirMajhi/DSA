#include <iostream>
#include <functional>
#include <string>
#include <list>
#include <utility>
using namespace std;

typedef struct Node {
    string key;
    int value;
    Node *next;
} node;

node** table = nullptr;
int tableSize = 4;
int itemCount = 0;
const double MAX_LOAD = 0.75;

// Hash Function
size_t myHash(const string &key){
    size_t h = 5381;
    for(unsigned char c: key) h = h * 33 + c;
    return h;
}

void initTable(){
    table = new node* [tableSize]();
}

// Grow the table to double the size and move every node
void resize(){
    int newSize = tableSize * 2;
    node **newTable = new node *[newSize]();
    for(int i = 0; i < tableSize; i++){
        node *curr = table[i];
        while(curr != nullptr){
            node *next = curr->next; // Save before new change
            size_t j = myHash(curr->key) % newSize; // NEW index with NEW size
            curr->next = newTable[j]; // push curr onto the front of box j
            newTable[j] = curr;
            curr = next; 
        }
    }

    delete[] table;
    table = newTable;
    tableSize = newSize;
    cout << "\n -- Resized to " << tableSize << " boxes --\n";
}

void put(const string& key, int value){
    size_t i = myHash(key) % tableSize;
    for(node *curr = table[i]; curr != nullptr; curr = curr->next){
        if(curr->key == key){
            curr->value = value;
            return;
        }
    }

    table[i] = new node{key, value, table[i]};
    itemCount++;
    if((double)itemCount / tableSize > MAX_LOAD){
        resize();
    }
}

bool get(const string& key, int& result){
    size_t idx = myHash(key) % tableSize;
    for(node* curr = table[idx]; curr != nullptr; curr = curr->next){
        if(curr->key == key){
            result = curr->value;
            return true;
        }
    }
    return false;
}

bool removeKey(const string& key) {
    size_t i = myHash(key) % tableSize;
    Node* cur = table[i];
    Node* prev = nullptr;

    while (cur != nullptr) {
        if (cur->key == key) {
            if (prev != nullptr) prev->next = cur->next;
            else table[i] = cur->next;
            delete cur;
            itemCount--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void printTable() {
    cout << "items=" << itemCount << " boxes=" << tableSize
         << " load=" << (double)itemCount / tableSize << "\n";
    for (int i = 0; i < tableSize; i++) {
        cout << "[" << i << "] ";
        for (Node* cur = table[i]; cur != nullptr; cur = cur->next)
            cout << "(" << cur->key << ":" << cur->value << ") -> ";
        cout << "null\n";
    }
}

void clearTable() {
    for (int i = 0; i < tableSize; i++) {
        Node* cur = table[i];
        while (cur != nullptr) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }
    delete[] table;
    table = nullptr;
    itemCount = 0;
}


int main()
{
    initTable();

    string names[] = {"Alice", "Bob", "Carol", "Dave", "Eve", "Frank", "Grace", "Heidi"};

    for (int i = 0; i < 8; i++) {
        cout << "put " << names[i] << "\n";
        put(names[i], 20 + i);
    }

    printTable();

    clearTable();

    return 0;

}