# Abstract Data Types Summary

## Common Topics

### Abstract Data Types (ADTs)
- **Definition**: ADT is a set of objects with a set of operations. Abstract in implementation details.
- **Examples**: Lists, Stacks, Queues
- **Operations**: Insert, delete, search, sort

### Lists
- **Array-Based Lists**
  - Operations: 
    - `insert(X,k)` – O(N)
    - `remove(k)` – O(N)
    - `find(X)` – O(N)
    - `findKth(k)` – O(1)
    - `printList()` – O(N)
- **Linked Lists**
  - Singly Linked List: Nodes with data and next pointer
  - Doubly Linked List: Nodes with data, next, and previous pointers
  - Operations:
    - `insert(X,A)` – O(1)
    - `remove(A)` – O(1)
    - `find(X)` – O(N)
    - `findKth(k)` – O(N)
    - `printList()` – O(N)
- **Sentinel Nodes**: Dummy head and tail nodes to avoid special cases at the ends of the list

### Stacks
- **Definition**: A list where insert and remove operations occur at the "top".
- **Operations**:
  - `Push (insert)` – O(1)
  - `Pop (remove)` – O(1)
  - `Top` – O(1)
- **Principle**: LIFO (Last In First Out)

### Queues
- **Definition**: A list where insert occurs at the back and remove occurs at the front.
- **Operations**:
  - `Enqueue (insert)` – O(1)
  - `Dequeue (remove)` – O(1)
- **Principle**: FIFO (First In First Out)

### C++ Standard Template Library (STL)
- **Implementation of common data structures**: list, stack, queue, vector
- **Methods**:
  - `push_back`, `pop_back`, `front`, `back`, `empty`, `size`
  - `insert`, `erase`
  - **Iterators**: `begin()`, `end()`, `++itr`, `*itr`, `==`, `!=`

## Unique Topics in `adt (1).pdf`

### Container Methods in STL
- `size()`, `clear()`, `empty()`
- **Iterators**: 
  - `iterator begin()`
  - `iterator end()`
  - `++itr`, `*itr`, `itr1 == itr2`, `itr1 != itr2`
- **Example**: `printList`

```cpp
template <typename Container>
void printList(const Container& lst) {
    for (typename Container::const_iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        cout << *itr << endl;
    }
}
```
### Stack Applications
- Balancing Symbols: ((()())(()))
- Postfix Expressions
- Function Calls: Programming languages use stacks to keep track of function calls.

### Queue Applications
- Job Scheduling
- Graph Traversals
- Queuing Theory

### Unique Topics in `2_data_structure_review_adt.pdf`
#### Detailed Example Implementations
- ADTs and Operations in C++
  - Linked Lists and Vector Operations
  - Differences in implementations using linked lists vs vectors.

### Abstract Data Type vs Primitive Data Types
- Difference Between ADT and Primitive Data Types
  - Interface vs Implementation
  - Example: int, float (primitive) vs List, Stack (ADT)


### Example: Stack Implementation in C++
```cpp
template <typename Object>
class stack {
public:
    stack() {}
    void push(Object& x) { s.push_back(x); }
    void pop() { s.pop_back(); }
    Object& top() { return s.back(); }
private:
    vector<Object> s;
};

```

### Example: Queue Implementation in C++
```cpp 
template <typename Object>
class queue {
public:
    queue() {}
    void enqueue(Object& x) { q.push_back(x); }
    Object& dequeue() {
        Object& x = q.front();
        q.pop_front();
        return x;
    }
private:
    list<Object> q;
};
```



---

### [Next Section: (3) The Big Fives ](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(3)%20The%20Big%20Five)
