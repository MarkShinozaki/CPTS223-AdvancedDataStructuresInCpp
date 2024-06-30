# Hashing Basics

## Hash Table Overview
- Supports insertion, deletion, and search operations in average-case constant time.
- Implemented as an array of fixed size, indexed by keys that are mapped to array indices using a hash function.

## Hash Function
- Maps a key to an array index.
- Simple hash function: `h(key) = key % TableSize`.
- For string keys, different approaches include:
  - Summing ASCII values.
  - Treating parts of the string as integers.
  - Using all characters with a prime number base.

## Load Factor
- Load factor \( \lambda \) is defined as the number of elements \( N \) divided by the size of the table \( M \).
- A higher load factor increases the likelihood of collisions.

## Collision Resolution
### Chaining
- Store colliding keys in a linked list.

### Open Addressing
- Store colliding keys elsewhere in the table using probing techniques.

### Linear Probing
- Resolves collisions by checking the next available slot.
```cpp
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

int linearProbe(int hashValue, int i, int tableSize) {
    return (hashValue + i) % tableSize;
}
```

### Quadratic Probing
- Uses a quadratic function to find the next slot, reducing primary clustering.
```cpp
int quadraticProbe(int hashValue, int i, int tableSize) {
    return (hashValue + i * i) % tableSize;
}
```

### Double Hashing
- Uses a second hash function to determine the interval between probes.
```cpp
int doubleHash(int key, int tableSize) {
    int hash1 = key % tableSize;
    int hash2 = 7 - (key % 7); // R = 7, a prime less than tableSize
    return (hash1 + i * hash2) % tableSize;
}
```
### Rehashing
- Rehashing increases the size of the hash table when the load factor becomes too high.
- This involves creating a new larger table and reinserting all elements.
  
```cpp
void rehash() {
    // Code for rehashing
}
```

---

### [Next Section: (13) Heaps](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(13)%20Heaps)

