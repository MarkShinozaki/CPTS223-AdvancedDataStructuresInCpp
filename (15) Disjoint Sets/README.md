# Disjoint Sets

## Introduction
- Disjoint sets are used for problems requiring equivalence relations.
- Determine if two elements are in the same equivalence class.
- Applications include reachability of components in a graph.

## Equivalence Relation
- A relation \( R \) on set \( S \) maps pairs of elements to true or false.
- Properties:
  - **Reflexive**: \( (a R a) \) for all \( a \in S \)
  - **Symmetric**: \( (a R b) \iff (b R a) \)
  - **Transitive**: \( (a R b) \) and \( (b R c) \rightarrow (a R c) \)

## Equivalence Class
- Given set \( S \) and equivalence relation \( R \), find subsets \( S_i \) of \( S \) such that:
  - For all \( a, b \in S_i \): \( (a R b) \)
  - For all \( a \in S_i, b \in S_j, i \neq j \): \( \neg(a R b) \)
- These \( S_i \) are the equivalence classes of \( S \) for relation \( R \).
- Example: \( S = \{1,2,3,4,5,6,7,8,9\} \), \( R \) is \( 'a \equiv b \mod 3' \).

## Disjoint Sets Operations
### Find(a)
- Returns a representative of the equivalence class containing \( a \).
```cpp
int find(int a) {
    if (s[a] < 0) return a;
    else return find(s[a]);
}


---

### [Next Section: (16) Graphs](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(16)%20Graphs)
