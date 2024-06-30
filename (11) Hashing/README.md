# Hashing

## Advanced Hashing Techniques

### Linear Probing
- Resolves collisions by checking the next available slot.
```cpp
int linearProbe(int hashValue, int i, int tableSize) {
    return (hashValue + i) % tableSize;
}
```

### Quadratic Probing
- Uses a quadratic function to find the next slot, reducing primary clustering
```cpp
int quadraticProbe(int hashValue, int i, int tableSize) {
    return (hashValue + i * i) % tableSize;
}
```
### Double Hashing
- Uses two hash functions \$( h_1 \)$ and \$( h_2 \)$ to reduce clustering.
- Example: \$( f(i) = i \times h_2(x) \)$ with \$( h_2(x) = R - (x \mod R) \)$, where \$( R \)$ is a prime number less than the table size.

```cpp
int doubleHash(int key, int tableSize) {
    int hash1 = key % tableSize;
    int hash2 = 7 - (key % 7); // R = 7, a prime less than tableSize
    return (hash1 + i * hash2) % tableSize;
}
```
### Rehashing
- Rehashing should be performed infrequently to amortize the cost over multiple insertions.
- Typically, the table size is doubled (and made prime) when the load factor threshold is reached.
```cpp
void rehash() {
    // Code for rehashing
}
```
### Hash Tables in STL
#### unordered_set
- Provides average-case \$𝑂(1)$ performance for insertion, search, and deletion.

```cpp
#include <unordered_set>
std::unordered_set<int> set;
set.insert(1);
```
#### unordered_map
- Used for associative arrays where data is stored as key-value pairs.
```cpp
#include <unordered_map>
std::unordered_map<std::string, int> map;
map["key"] = 1;
```

### Applications of Hash Tables
- Symbol tables in compilers.
- Accessing tree or graph nodes by name (e.g., city names in Google maps).
- Maintaining a transposition table in games.
- Dictionary lookups, spelling checkers, and natural language processing.









---

### [Next Section: (12) Hashing Basics](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(12)%20Hashing%20Basics)
