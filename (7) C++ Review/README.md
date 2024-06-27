# C++ Review

## Purpose of Review
- Review some basic C++
- Familiarize us with Weiss’s style
- Introduce specific constructs useful for implementing data structures


## Class
- The Class defines the data structure and the operations that access and manipulate it
  - Member data
  - Member functions or methods
- Encapsulation = data + methods
- Information hiding
  - Public vs. private

## Extra Syntax
- Default parameters
- Initializer list
- Explicit constructor
- Accessor methods
- Constant member function, add: `const`
- Mutator methods


## Default Parameters
- Initializer List
- Explicit Constructor
- Accessor

```cpp
IntCell obj;
obj = 37;
```
- Mutator

## Separation of Interface and Implementation
- Interface (.h) file
  - Defines class and its member data and functions
- Implementation (.cc or .cpp) file
  - Provides implementations of member functions

## Example Files
- IntCell class interface in file IntCell.h.
  - Preprocessor Directives
- IntCell class implementation in file IntCell.cpp.
  - Preprocessor Directives
  - Scoping Operator
  - ClassName::member
- Program using IntCell class in file TestIntCell.cpp.
  - Preprocessor Directives

## C++ Details
- Pointers
- Parameter passing
- Return passing
- Reference variables
- Destructor, copy constructor, operator=

## Pointers
- Address-of operator: `&`
```cpp
IntCell icObj;
IntCell *m = &icObj;
```
- No automatic garbage collection in C++

## Parameter Passing
- Call by value
  - Small objects not altered by function
- Call by constant reference
  - Large objects not altered by function
- Call by reference
  - Objects altered by function
```cpp
double avg (const vector<int> & arr, int n, bool & errorFlag);
```

## Return Passing
- Make sure the object returned will persist after returning from the function call.

## Reference Variables
- Can be used for parameter passing
- Also used as synonyms for the objects they reference
- Avoid cost of copying

```cpp
string x = findMax (a);
cout << x << endl;

const string & x = findMax (a);
cout << x << endl;
``` 

## Destructor, Copy Constructor, operator=
- Default definitions for all classes
- Destructor
  - Called when object goes out of scope or subject to a delete
  - By default, calls destructor on all data members
  - Can use to delete objects created using new
  - Can use to close any opened files.

## Destructor, Copy Constructor, operator=
- Copy constructor
  - Declaration with initialization
```cpp
IntCell B = C;
IntCell B (C);
```
- Object passed using call by value (instead of by `&` or `const &`)
- Object returned by value (instead of by `&` or `const &`)
- Simple assignment for all members with primitive data types (e.g., int, double, …)
- Calls copy constructors on all member objects

## Destructor, Copy Constructor, operator=
- Copy assignment operator: operator=
  - Called when objects on both sides of assignment already constructed
  - By default, operator= called on each data member of objects
```cpp
IntCell B(0);
IntCell C(1);
B = C;
```

## Templates
- Designing type-independent data structures and algorithms
- Function templates
- Class templates

## Operator Overloading
- Define the meaning of a built-in operator
```cpp
class IntCell {
public:
  bool operator< (const IntCell & rhs) const {
    return storedValue < rhs.storedValue;
  }

  void print (ostream & out) const {
    out << " IntCell(" << storedValue << ")";
  }

  ...
}

ostream & operator<< (ostream & out, const IntCell & rhs) {
  rhs.print(out); 
  return out;
}
```

## Summary 
- Basic C++
- Templates
- Tools for easing the 

---

### [First Section: CMake Installation & Example](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Helpful-Material/(1)%20CMake%20Installation%20%26%20Example)



