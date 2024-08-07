# C++ Features & Rule of Big Five



### Separation of Interface and Implementation
Promotes better organization and maintenance of code by defining the interface in headers and implementation in source files.

### Lvalues, Rvalues, and References
- **Lvalues**: Objects that persist beyond a single expression (e.g., variables).
- **Rvalues**: Temporary objects that do not persist beyond a single expression (e.g., literals).

#### Example
```cpp
int x = 10;  // x is an lvalue, 10 is an rvalue
int &lref = x; // lref is an lvalue reference to x
int &&rref = 10; // rref is an rvalue reference to 10
```

### std::swap and std::move
- **std::swap**: Swaps two elements via lvalue references.

```cpp
template <class T>
void swap(T& a, T& b) {
    T tmp(a);
    a = b;
    b = tmp;
}
```
- **std::move**: Moves from source to target using rvalue, effectively "stealing" the contents.

```cpp
template <class T>
void swap(T& a, T& b) {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}
```

### The Big Five (Rule of Five)
- **`Destructor`**: Cleans up resources.

```cpp
~IntCell(); // Destructor
```

- **`Copy Constructor`**: Creates a new object as a copy of an existing object.
```cpp
IntCell(const IntCell &rhs); // Copy constructor
```

- **`Move Constructor`**: Creates a new object by transferring resources from an rvalue object.

```cpp
IntCell(IntCell &&rhs); // Move constructor
```

- **`Copy Assignment Operator`**: Assigns values from one object to another.
```cpp
IntCell& operator=(const IntCell &rhs); // Copy assignment operator
```

- **`Move Assignment Operator`**: Assigns values from an rvalue object to another, transferring resources.
```cpp
IntCell& operator=(IntCell &&rhs); // Move assignment operator
```

### Shallow vs Deep Copies
- Shallow Copy: Copies all member field values directly.
- Deep Copy: Copies all fields and makes copies of dynamically allocated memory.

### Destructor
- Automatically generated by the C++ compiler if not defined. Needed when managing dynamically allocated memory.

### Starting Algorithms & Analysis
- Comparing function growth rates to analyze algorithm efficiency based on input size.


---

### [Next Section: (4) Trees](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(4)%20Trees)