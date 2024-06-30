# STL Sets and Maps

## Introduction to Balanced BSTs
Balanced Binary Search Trees (BSTs) are data structures that maintain sorted data for fast retrieval, insertion, and deletion. Common balanced BSTs include AVL trees, Splay trees, Red-Black trees, Scapegoat trees, and Treaps.

## Balanced BSTs in STL: set and map
- `vector` and `list` STL classes are inefficient for search operations.
- `set` and `map` STL classes guarantee logarithmic time complexity for insertion, deletion, and search operations.
- Internally, these classes use Red-Black trees.

## STL set Class
- The `set` class is an ordered container that does not allow duplicates.
- Provides iterators and related methods: `begin`, `end`, `empty`, and `size`.
- Supports `insert`, `erase`, and `find`.

### Set Insertion
The `insert` method adds an item to the set and returns an iterator to it.
```cpp
pair<iterator,bool> insert(const Object & x);
```

- If the set does not allow duplicates, insert may fail and return an iterator to the existing item. The method returns a pair containing the iterator and a Boolean indicating success.

### Example: Set Insert and Print
```cpp
set<int> s;
// insert
for (int i = 0; i < 1000; i++) {
    s.insert(i);
}
// print
for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    cout << *it << " " << endl;
}
```
- The elements will be printed in sorted order.

### Set Deletion
- The `erase` method removes an item if found and returns the number of items deleted (0 or 1).
```cpp
int erase(const Object & x);
```
- It can also remove objects at a specific iterator position or within a range of iterators.
```cpp
iterator erase(iterator itr);
iterator erase(iterator start, iterator end);
```

### Set Search
- The `find` method returns an iterator to the object (or `end` if not found).
```cpp
iterator find(const Object & x) const;
```
- This method runs in logarithmic time.

## STL map Class
The `map` class is an associative container that stores items as key-value pairs. Items are stored sorted by key. The `map` class is similar to the `set` class but includes a value associated with each key. Keys must be unique, and if duplicates are needed, the `multimap` class is used.

#### Example: Map Insert and Access
```cpp
map<string, double> salaries;
salaries["Pat"] = 75000.0;
cout << "Pat's salary: " << salaries["Pat"] << endl;
```

### Map Operations
- The `insert` method adds a key-value pair to the map.
- The `find` method searches for a key and returns an iterator to the key-value pair.
- The `erase` method removes a key-value pair from the map.

#### Example: Map Find and Iterate

```cpp
map<const char*, int, ltstr> months;
months["january"] = 31;
months["february"] = 28;
// print
for (map<const char*, int, ltstr>::iterator it = months.begin(); it != months.end(); it++) {
    cout << it->first << " -> " << it->second << endl;
}
```

#### Implementation of set and map
- Both `set` and `map` support insertion, deletion, and search in worst-case logarithmic time using balanced binary search trees (Red-Black trees). Iterators are supported, and tree nodes point to their predecessor and successor for in-order traversal.

#### When to use set and when to use map
- Use `set` when the entire record structure is used as the key.
- Use `map` when the record structure has fields other than the key, such as an employee record where the key is an ID, and the value includes other information like name and salary.

## Summary: Trees in STL
Trees are ubiquitous in software and important for fast search operations.
Balanced trees like those used in set and map classes support logarithmic insert, delete, and search operations.
STL set and map classes use balanced Red-Black trees for their implementation.

---

### [Next Section: (9) Trees - Red & Black](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(9)%20Trees%20-%20Red-Black)
