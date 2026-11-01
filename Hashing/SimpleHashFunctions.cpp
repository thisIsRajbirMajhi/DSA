#include <iostream>
#include <functional>
#include <string>
#include <utility>
using namespace std;

using HashFn = function<size_t(const string &)>;

size_t toy_hash(const string &s){
    size_t sum = 0;
    for(unsigned char c: s) sum += c;
    return sum;
}

size_t poly_hash_simple(const string &s){
    size_t h = 0;
    for(unsigned char c: s) h * 31 + c;
    return h;
}

size_t poly_hash_better(const string &s){
    size_t h = 14695981039346656037ull;
    for(unsigned char c: s) {
        h ^= c;
        h *= 1099511628211ull;
    }
    return h;
}

size_t dan_bernstein_simple(const string &s){
    size_t h = 5381;
    for(unsigned char c: s) h = h * 33 + c;
    return h;
}

size_t dan_berstein_better(const string &s){
    size_t h = 5381;
    for(unsigned char c: s) h = (h * 33) ^ c;
    return h;
}

void compare_hashes(const vector<size_t> &sizes,
    const vector<string> &words,
    const vector<pair<string, HashFn>> &hashes) {
    for (size_t N : sizes) {
        cout << "Table Size: " << N << "\n";
        for (const string &w : words) {
            cout << " " << w;
            for (const auto &[name, fn] : hashes) {
                size_t h = fn(w);                       
                cout << " | " << name << " = " << h << " -> Slot: " << h % N;
            }
            cout << "\n";
        }
    }
}

int main()
{
    compare_hashes(
        {10, 20},
        {"cat", "act", "tic", "tac", "toe", "dog", "god", "hello", "world"},
        {
            {"Toy",              toy_hash},
            {"Poly Simple",      poly_hash_simple},
            {"Poly Better",      poly_hash_better},
            {"Bernstein Simple", dan_bernstein_simple},
            {"Bernstein Better", dan_berstein_better},
        });
    return 0;
}