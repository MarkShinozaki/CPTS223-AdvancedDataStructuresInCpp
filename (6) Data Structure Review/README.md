# Abstract Data Types
## Topics
- Abstract Data Types (ADTs)
  - Lists
  - Stacks
  - Queues

## Abstract Data Types (ADTs)
- ADT is a set of objects together with a set of operations
- “Abstract” in that implementation of operations not specified in ADT definition
  - E.g., List
    - Insert, delete, search, sort

## Primitive Data Type vs. Abstract Data Types
**ADT:**
  - Interface (API)
**Primitive DT:**
  - e.g., int, float
  - Implementation (methods)

## Specifications of Basic ADTs
- List, Stack, Queue

## The List ADT
- List of size N: A0, A1, …, AN-1
- Each element Ak has a unique position k in the list
- Elements can be arbitrarily complex
- Operations:
  - `insert(X,k)`, `remove(k)`, `find(X)`, `findKth(k)`, `printList()`

## Stack ADT
- Stack = a list where insert and remove take place only at the “top”
- **Operations:**
  - Push (insert) element on top of stack
  - Pop (remove) element from top of stack
  - Top: return element at top of stack
  - LIFO (Last In First Out)

## Queue ADT
- Queue = a list where insert takes place at the back, but remove takes place at the front
- Operations:
  - Enqueue (insert) element at the back of the queue
  - Dequeue (remove and return) element from the front of the queue
  - FIFO (First In First Out)

## List ADT using Linked Lists
- **Operations:**
  - `insert(X,A)` – O(1)
  - `remove(A)` – O(1)
  - `find(X)` – O(N)
  - `findKth(k)` – O(N)
  - `printList()` – O(N)

## Doubly-Linked List
- Singly-linked list
  - `insert(X,A)` and `remove(X)` require pointer to node just before X
- Doubly-linked list
  - Also keep pointer to previous node

### Insert and Remove Operations
```c
// Insert
newA = new Node(A);
newA->prev = X->prev;
newA->next = X;
X->prev->next = newA;
X->prev = newA;

// Remove
X->prev->next = X->next;
X->next->prev = X->prev;
```
- Two-way traversal
- Insert/delete is faster if an existing node pointer is given

## C++ Standard Template Library (STL)
- Implementation of common data structures
  - List, stack, queue, …
  - Generally called containers
- WWW references for STL:
- [SGI STL](http://www.sgi.com/tech/stl/)
- [cplusplus.com STL](http://www.cplusplus.com/reference/stl/) 
- [cppreference.com STL](http://www.cppreference.com/cppstl.html)

## Implemented Lists in STL
- `vector<Object>`
  - Array-based implementation
  - findKth – O(1)
  - insert and remove – O(N)
  - Unless change at end of vector
- `list<Object>`
  - Doubly-linked list with sentinel nodes
  - findKth – O(N)
  - insert and remove – O(1)
  - If position of change is known
  - Both require O(N) for search
 
## Container Methods
- `int size() const`
  - Return number of elements in container
- `void clear()`
  - Remove all elements from container
- `bool empty()`
  - Return true if container has no elements, otherwise returns false
 
## Methods for both Vector and List
- `void push_back(const Object & x)`
  - Add x to end of list
- `void pop_back()`
  - Remove object at end of list
- `const Object & back() const`
  - Return object at end of list
- `const Object & front() const`
  - Return object at front of list

## List-only Methods
- `void push_front(const Object & x)`
  - Add x to front of list
- `void pop_front()`
  - Remove object at front of list

## Vector-only Methods
- `Object & operator[](int idx)`
  - Return object at index idx in vector with no bounds-checking
- `Object & at(int idx)`
  - Return object at index idx in vector with bounds-checking
- `int capacity() const`
  - Return internal capacity of vector
- `void reserve(int newCapacity)`
  - Set new capacity for vector (avoid expansion)

## Iterators
- Represents position in container
- Getting an iterator:
- `iterator begin()`
  - Return appropriate iterator representing first item in container
- `iterator end()`
  - Return appropriate iterator representing end marker in container
  - Position after last item in container

## Iterator Methods
- `itr++` and `++itr`
  - Advance iterator itr to next location
- `*itr`
  - Return reference to object stored at iterator itr’s location
- `itr1 == itr2`
  - Return true if itr1 and itr2 refer to same location; otherwise return false
- `itr1 != itr2`
  - Return true if itr1 and itr2 refer to different locations; otherwise return false

### Example: printList
```ccp
template <typename Container>
void printList(const Container & lst)
{
  for (typename Container::const_iterator itr = lst.begin(); itr != lst.end(); ++itr)
  {
    std::cout << *itr << std::endl;
  }
}
```
## Constant Iterators
- `iterator begin()`
- `const_iterator begin() const`
- `iterator end()`
- `const_iterator end() const`
- Appropriate version above returned based on whether container is const
- If const_iterator used, then `*itr` cannot appear on left-hand side of assignment (e.g., `*itr=0`)


## Container Operations Requiring Iterators
- `iterator insert(iterator pos, const Object & x)`
  - Add x into list, prior to position given by iterator pos
  - Return iterator representing position of inserted item
  - O(1) for lists, O(N) for vectors
- `iterator erase(iterator pos)`
  - Remove object whose position is given by iterator pos
  - Return iterator representing position of item following pos
  - This operation invalidates pos
  - O(1) for lists, O(N) for vectors
- `iterator erase(iterator start, iterator end)`
  - Remove all items beginning at position start, up to, but not including end

## Stack ADT
- Stack is a list where insert and remove take place only at the “top”
- **Operations:**
  - Push (insert) element on top of stack
  - Pop (remove) element from top of stack
  - Top: return element at top of stack
  - LIFO (Last In First Out)

## Stack Implementation
### Using Vector
```cpp
template <typename Object>  
class stack
{
public:  
  stack() {}
  void push(const Object & x) { s.push_back(x); }
  void pop() { s.pop_back(); }
  Object & top() { return s.back(); }
private:
  std::vector<Object> s;
};
```
### Using Linked List
```cpp
template <typename Object>  
class stack
{
public:  
  stack() {}
  void push(const Object & x) { s.push_front(x); }
  void pop() { s.pop_front(); }
  Object & top() { return s.front(); }
private:
  std::list<Object> s;
};
```
### C++ STL Stack Class
- **Methods:**
  - Push, pop, top
  - Empty, size
```cpp
#include <stack>
std::stack<int> s;
for (int i = 0; i < 5; i++)
{
  s.push(i);
}
while (!s.empty())
{
  std::cout << s.top() << std::endl;  
  s.pop();
}
```

## Stack Applications
### Balancing Symbols
```cpp
std::stack<char> s; 
while (not end of file)
{
  read character c  
  if (c == '(')
    s.push(c);  
  if (c == ')')
    if (s.empty())
      error;  
    else 
      s.pop();
}
if (!s.empty())
  error;
else 
  okay;
```
### Postfix Expressions
- Function calls
  - Programming languages use stacks to keep track of function calls
  - When a function call occurs:
    - Push CPU registers and program counter onto stack (“activation record” or “stack frame”)
  - Upon return, restore registers and program counter from top stack frame and pop

## Queue ADT
- Queue is a list where insert takes place at the back, but remove takes place at the front
- **Operations:**
  - Enqueue (insert) element at the back of the queue
  - Dequeue (remove and return) element from the front of the queue
  - FIFO (First In First Out)

## Queue Implementation
**Using Linked List**
```cpp
template <typename Object>  
class queue
{
public:  
  queue() {}
  void enqueue(const Object & x) { q.push_back(x); }
  Object & dequeue()
  {
    Object & x = q.front();
    q.pop_front();  
    return x;
  }
private:  
  std::list<Object> q;
};
```
**Using Vector**
```cpp
template <typename Object>  
class queue
{
public:  
  queue() {}
  void enqueue(const Object & x) { q.push_back(x); }
  Object & dequeue()
  {
    Object & x = q.front();
    q.pop_front();  
    return x;
  }
private:  
  std::vector<Object> q;
};
```
## C++ STL Queue Class
- **Methods:**
  - Push (at back)
  - Pop (from front)
  - Back, front
  - Empty, size
```cpp
#include <queue>
std::queue<int> q;
for (int i = 0; i < 5; i++)
{
  q.push(i);
}
while (!q.empty())
{
  std::cout << q.front() << std::endl;  
  q.pop();
}

```
## Implementing Deques
- Double-ended queue (Deque)
  - Elements inserted or removed at either end

## Deque Methods
- `void push_front(const Object & x)`
  - Add x to front of deque
- `void push_back(const Object & x)`
  - Add x to end of deque
- `void pop_front()`
  - Remove object at front of deque
- `void pop_back()`
  - Remove object at end of deque

## C++ STL Deque Class
- Methods:
  - Push_front, push_back
  - Pop_front, pop_back
  - Front, back
  - Empty, size
 ```cpp
#include <deque>
std::deque<int> d;
for (int i = 0; i < 5; i++)
{
  d.push_back(i);
}
while (!d.empty())
{
  std::cout << d.front() << std::endl;  
  d.pop_front();
}
```
---

### [Next Section: C++ Review](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Helpful-Material/(7)%20C%2B%2B%20Review)
