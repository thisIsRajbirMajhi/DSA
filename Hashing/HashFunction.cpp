#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Sum of bytes. Order-insensitive. Anagrams collide.
size_t toy_hash(const string &s) {
    size_t sum = 0;
    for (unsigned char c : s) sum += c;
    return sum;
}

// XOR of bytes. Order-insensitive. Duplicate bytes cancel out.
size_t hash_xor(const string &s) {
    size_t h = 0;
    for (unsigned char c : s) h ^= c;
    return h;
}

// Classic polynomial hash, base 31.
size_t poly_hash(const string &s) {
    size_t h = 0;
    for (unsigned char c : s) h = h * 31 + c;
    return h;
}

// Larger base + 64-bit wraparound (FNV-1a style).
// FIXED: the offset basis was missing a digit.
size_t poly_hash_better(const string &s) {
    size_t h = 14695981039346656037ull;   // FNV offset basis
    for (unsigned char c : s) {
        h ^= c;
        h *= 1099511628211ull;            // FNV prime
    }
    return h;
}

// Dan Bernstein djb2. Seed 5381, multiplier 33.
size_t hash_djb2(const string &s) {
    size_t h = 5381;
    for (unsigned char c : s) h = h * 33 + c;
    return h;
}

// djb2 XOR variant.
size_t hash_djb2_xor(const string &s) {
    size_t h = 5381;
    for (unsigned char c : s) h = (h * 33) ^ c;
    return h;
}

// sdbm. h = c + (h<<6) + (h<<16) - h  ==  c + h*65599.
size_t hash_sdbm(const string &s) {
    size_t h = 0;
    for (unsigned char c : s) h = c + (h << 6) + (h << 16) - h;
    return h;
}

// FNV-1a 64-bit. XOR first, then multiply by FNV prime.
size_t hash_fnv1a(const string &s) {
    size_t h = 14695981039346656037ull;
    for (unsigned char c : s) {
        h ^= c;
        h *= 1099511628211ull;
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

// Jenkins One-At-A-Time. Three-way mixing.
size_t hash_jenkins_oat(const string &s) {
    size_t h = 0;
    for (unsigned char c : s) {
        h += c;
        h += (h << 10);
        h ^= (h >> 6);
    }
    h += (h << 3);
    h ^= (h >> 11);
    h += (h << 15);
    return h;
}

int main() {
    vector<pair<string, function<size_t(const string &)>>> hashers = {
        {"Toy Hash",          toy_hash},
        {"Hash XOR",          hash_xor},
        {"Poly Hash",         poly_hash},
        {"Better Poly Hash",  poly_hash_better},
        {"Bernstein djb2",    hash_djb2},
        {"Bernstein djb2 XOR",hash_djb2_xor},
        {"SDBM",              hash_sdbm},
        {"FNV-1a 64-bit",     hash_fnv1a},
        {"FNV-1 64-bit",      hash_fnv1},
        {"Jenkins OAT",       hash_jenkins_oat}
    };

    vector<string> words = {
        "cat", "act", "tic", "tac", "toe", "dog", "god",
        "hello", "world", "a", "aa", "ab", "ba"
    };

    const size_t N = 100;
    const int NAME_W = 50;

    // ---- 1. Grid: slot number of every word under every hasher ----
    cout << "=== Slot grid (hash % " << N << ") ===\n";
    cout << left << setw(NAME_W) << "hasher";
    for (const string &w : words) cout << setw(6) << w;
    cout << "\n" << string(NAME_W + 6 * words.size(), '-') << "\n";

    for (auto &p : hashers) {
        cout << left << setw(NAME_W) << p.first;
        for (const string &w : words) cout << setw(6) << (p.second(w) % N);
        cout << "\n";
    }

    // ---- 2. Option A: which words share each slot ----
    cout << "\n=== Buckets per hasher (only non-empty slots) ===\n";
    for (auto &p : hashers) {
        vector<vector<string>> table(N);
        for (const string &w : words) table[p.second(w) % N].push_back(w);

        cout << "\n== " << p.first << " ==\n";
        for (size_t i = 0; i < N; i++) {
            if (table[i].empty()) continue;
            cout << "slot " << setw(2) << right << i << " : ";
            for (const string &w : table[i]) cout << w << " ";
            if (table[i].size() > 1) cout << "  <-- collision";
            cout << "\n";
        }
    }

    // ---- 3. Option C: compact scoreboard ----
    cout << "\n=== Collision summary (N=" << N << ", "
         << words.size() << " words) ===\n";
    cout << left << setw(NAME_W) << "Hasher"
         << setw(12) << "Collisions" << "Max bucket\n";
    cout << string(NAME_W + 12 + 10, '-') << "\n";

    for (auto &p : hashers) {
        vector<int> bucket(N, 0);
        for (const string &w : words) bucket[p.second(w) % N]++;

        int collisions = 0, maxload = 0;
        for (int b : bucket) {
            if (b > 1) collisions += b - 1;
            if (b > maxload) maxload = b;
        }
        cout << left << setw(NAME_W) << p.first
             << setw(12) << collisions << maxload << "\n";
    }

    // ---- 4. Option D: raw hash of "cat" in hex ----
    cout << "\n=== Raw hash of \"cat\" (hex) - low 4 bits decide the slot ===\n";
    for (auto &p : hashers) {
        cout << left << setw(NAME_W) << p.first
             << "0x" << hex << p.second("cat") << dec << "\n";
    }

    return 0;
}