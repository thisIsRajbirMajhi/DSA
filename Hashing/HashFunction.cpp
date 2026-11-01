#include <functional>
#include <iostream>
#include <string>
using namespace std;

// Hash Function 
// Sum of bytes. Order-insensitive. Anagrams collide.
size_t toy_hash(const string &s){
    size_t sum = 0;
    for (unsigned char c: s){
        sum += c;
    }
    return sum;
}

// XOR of Bytes. Order-Insensitive. Duplicate bytes cancel out.
size_t hash_xor(const string &s){
    size_t h = 0;
    for(unsigned char c: s) h ^= c;
    return h;
}

size_t poly_hash(const string &s){
    size_t h = 0;
    for(unsigned char c: s){
        h = h * 31 + c;
    }
    return h;
}

// Better polynomial hash: LArger basae + unsigned 64 bit wraparound
size_t poly_hash_better(const string &s){
    size_t h = 1469598103934665603ull; // FNV offset basis
    for(unsigned char c: s){
        h ^= c;
        h *= 1099511628211ull; // FNV Prime
    }
    return h;
}

// Dan Bernstein. Seed 5381, multiplier 33.
size_t hash_djb2(const string &s) {
    size_t h = 5381;
    for (unsigned char c : s) h = h * 33 + c;
    return h;
}

// djb2 XOR variant
size_t hash_djb2_xor(const string &s) {
    size_t h = 5381;
    for (unsigned char c : s) h = (h * 33) ^ c;
    return h;
}

// sdbm.  h = c + (h<<6) + (h<<16) - h  ==  c + h*65599.
size_t hash_sdbm(const string &s) {
    size_t h = 0;
    for (unsigned char c : s)
        h = c + (h << 6) + (h << 16) - h;
    return h;
}

// FNV-1a 64-bit. XOR first, then multiply by FNV prime.
size_t hash_fnv1a(const string &s) {
    size_t h = 14695981039346656037ull;   // FNV offset basis
    for (unsigned char c : s) {
        h ^= c;
        h *= 1099511628211ull;            // FNV prime
    }
    return h;
}

// FNV-1 64-bit. Multiply first, then XOR.
size_t hash_fnv1(const string &s) {
    size_t h = 14695981039346656037ull;
    for (unsigned char c : s) {
        h *= 1099511628211ull;
        h ^= c;
    }
    return h;
}

void show_slots(const vector<size_t> &sizes, const vector<string> &words){
    for(size_t N: sizes){
        cout << "Table Size: " << N << endl;
        for(const string &w: words){
            size_t t = toy_hash(w);
            size_t p = poly_hash(w);
            cout << " " << w
                 << " toy = " << t << " -> slot " << t % N
                 << " | poly = " << p << " -> slot " << p % N << endl;
        }
    }
}

/*
    * Toy hash collides on every anagram, at any table size. It is a poor hash function.
    * Poly hash gives different numbers, so the hash function itself did its job.
    
    ! Rules every hash function must follow:
    * Deterministic: Same key, same number, always.
    * Equal keys must produce equal hashes.
    * Fast to compute
    * Spread keys evenly across the range.
    * Fixed Output Size: The output of a hash function should have a fixed size, regardless of the size of the input.
    * Avalanche Effect: A small change in the input should produce a significantly different hash value.
    * Collision Resistance: It should be difficult to find two different inputs that produce the same hash value.
    * 

*/



int main()
{
    show_slots({123, 111}, {"cat", "act", "tac", "dog", "cow"});
    return 0;
}