# Hashing:
Hashing turns any data into a fixed-size fingerprint.

## The Big Idea:
**Problem:** 
+ You have a million student records. Someone asks, "Find the record for roll number 48213."

+ Scanning every record one by one is slow O(n)
+ Sorting and binary searching is better O(nlogn) but needs sorted data and is awkward when data changes.

**Hashing's promise:** 
+ Jump directly to where the record lives, in about one step (O(1) on average).

**Analogy:**
You hand your bag to the clerk. Instead of storing it anywhere, the clerk applies a rule to your name to get to the locker number 7, and puts the bag there. When you return the clerk applies the same rule to your name, gets 7 again and walks straight to locker 7. No searching.

+ The ***rule*** is the hash function.
+ The ***locker*** is the hash value or hash code.
+ The ***wall of lockers*** is the hash table.

## What is a hash function?
+ A hash function takes input of any size (a string, a file, an object) and produces a fixed size number.

+ **Deterministic:** Same input always gives the same output.
+ **Fast:** Computing it must be cheap.
+ **Fixed Size output:** Output length does not depend on input length.
+ **Uniform spread:** Different inputs should scatter evenly across possible outputs.

+ ***Important:*** hashing is one-way in practice. You go from input to hash easily, but you cannot reliably go from hash back to input, because many inputs squeeze into few outputs (information is lost).

## Example:
+ ASCII Values: c = 99, a = 97, t = 116
+ Key: "cat"
+ Sum of char: 99 + 97 + 116 = 312
+ Sum mod 10: 312 mod 10 = 2
+ Locker = 2

+ The mode step (called compression) is what forces any huge number into the valid range 0...size - 1

+ So the table looks like:
+ Index: 0 1  2     3  4   5 6  7    8 9
         - - cat    - dog  - - bird  - -
+ Lookup for "dog" computes 314 mod 10 = 4, go to index 4, found. One step.'

# Hash Table:
+ A hash table is an array + a hash function deciding which slot each goges in.

## Options:
+ put(key, value): i = hash(key) mod size; store(key, value) at slot i
+ get(key):        i = hash(key) mod size; read slot i
+ remove(key):     i = hash(key) mod size; clear slot i
+ Each is O(1) on average because computing the hash and indexing an array are both constant-time.

# Collisions:
## Example:
+ ASCII Values: c = 99, a = 97, t = 116
+ Key: "cat"
+ Sum of char: 99 + 97 + 116 = 312
+ Sum mod 10: 312 mod 10 = 2
+ Locker = 2

+ Insert "act" in the table. Its letters are the same as "cat":
+ a + c + t = 97 + 99 + 116 = 312 mod 10 = 2
+ Locker 2 is already holding "cat". That is a collision.

# Fixing Collisions:
1) Seprate Chaining: (Each slot holds a list)
    + Each slot stores a linked list (or a small list/tree) of all entires tgat landed there.
    + ### Example:
        + index 2:  [cat] -> [act] -> [tac]
        + index 4:  [dog]
        + index 7:  [bird]

    + put: hash, go to slot, append to its list.
    + get: hash, go to slot, walk the short list comparing keys with equals.
    + If lists stay short, operations stay about O(1). If everything lands in one slot, it degrades to O(n).

2) Open Addressing: (Everything stays in the array)
    + When the slot is taken, probe for another free slot.
    + Linear probing: try slot i, then i+1, i+2, ... (wrapping around).

    + ### Example:
        + Insert "cat" → slot 2 is free → placed at 2.
        + Insert "act" → slot 2 taken → try 3 → free → placed at 3.
        + Insert "dog" → slot 4 free → placed at 4.

        + Lookup "act": start at 2 (it's cat, not a match), move to 3 (it's act, match). Found.
        + Deletion gotcha: if you simply empty slot 2 after removing "cat", then searching for "act" would start at 2, see empty, and wrongly conclude "not present".
        + Real implementations place a tombstone marker meaning "deleted, keep probing".
        + Other probing styles: quadratic probing (i+1², i+2², ...) and double hashing (use a second hash for the step size). They reduce clustering (long runs of occupied slots that linear probing creates).

# Load Factor and Resizing:
1) Load factor = number of entries ÷ number of slots.
    + 5 entries in 10 slots → load factor 0.5.
    + Low load factor: fewer collisions, more wasted memory.
    + High load factor: more collisions, slower.

2) Resizing: 
    + To keep things fast, hash tables resize when the load factor passes a threshold:
    + Allocate a bigger array (usually double).
    + Rehash every entry into the new array (the table size changed, so hash mod size changes, and entries move).

**Note:** Resizing costs O(n), but it happens rarely, so the amortized cost per insert stays O(1). (Same reasoning as ArrayList growing.)

# What makes a good hash function:
### Goals: Fast, deterministic, evenly distributed, and sensitive to every part of the input (including order).

1) The Polynomial Hash:
    + Instead of just adding characters, multiply the running total by a constant before adding the next character
    
    ***
        hash = 0
        for each character c:
            hash = hash * 31 + c
    ***
    
    ### Example:
    + "ab": a = 97, b = 98
    + Start: 0
    + After a: 0 x 31 + 97 = 97
    + After b: 97 x 31 + 98 = 3007 + 98 = 3105

    + Now "ba" 3135
    + Different from "ab". Anagrams no longer collide automatically, because position matters (earlier characters get multiplied by more 31s).


     
    
    
    