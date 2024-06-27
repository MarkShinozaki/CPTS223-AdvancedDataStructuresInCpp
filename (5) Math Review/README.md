# Math Review

## Why do we need math in a data structures course?

- To analyze data structures and algorithms
- Deriving formulae for time and memory requirements
- Will the solution scale?
- Quantify the results
- Proving algorithm correctness


## Definition: Let T(n) denote the time taken by an algorithm on an input of size n.
### Examples – how much “time” does each of these algorithms take?


```c
// Assume A is an integer array of size n
Algorithm1 (A,n)
    max = -infinity
    for (i=1 to n) {
        if(A[i]>max) max=A[i];
    }
    Output max;

Algorithm2 (A, start, end)  
    if (n<2) return
    mid = floor(n/2)
    if (condition#1) 
        Algorithm2 (A,1,mid)
    else 
        Algorithm2 (A,mid+1,n)

Algorithm3 (A, start, end)  
    if (n<2) return
    mid = floor(n/2)
    Algorithm3 (A,1,mid)
    Algorithm3 (A,mid+1,n)
```

- O(lg n) for Algorithm2, and
- O(n) for Algorithm3


## Asymptotic Notations
- O-notation: Upper bound of the algorithm’s running time. For example, O(n), O(log n)
- Ω-notation: Lower bound of the algorithm’s running time.
- θ-notation: Both upper and lower bound of the algorithm’s running time.

## Definition of O-notation
- T(n) is O(f(n)) if there exist constants c > 0 and n0 such that T(n) ≤ c*f(n) for all n ≥ n0

## Example
- 3n+5 is O(n) for c=4 and n0=1

## Floor and Ceiling

### Floor Function
- floor(x): largest integer less than or equal to x

### Ceiling Function
- ceil(x): smallest integer greater than or equal to x

### Examples
- floor(3.2) = 3
- ceil(3.2) = 4

## Logarithms and Exponents

### Properties
- log(a*b) = log(a) + log(b)
- log(a/b) = log(a) - log(b)
- log(a^b) = b*log(a)
- log(1) = 0
- log(a^0) = 0
- log_b(a) = log(a) / log(b)

### Examples
- log_2(8) = 3 (since 2^3 = 8)
- log_10(1000) = 3 (since 10^3 = 1000)

## Series and Summations

### Arithmetic Series
- Sum of first n natural numbers: 1 + 2 + 3 + ... + n = n(n+1)/2

### Geometric Series
- Sum of first n terms of a geometric series: a + ar + ar^2 + ... + ar^(n-1) = a*(1-r^n)/(1-r) (for r ≠ 1)

## Modulo Arithmetic

### Definition
- a mod b = remainder when a is divided by b

### Examples
- 5 mod 2 = 1
- 9 mod 3 = 0
- 14 mod 5 = 4

## Proofs by Mathematical Induction
### Three-step process

1. Base case: Show hypothesis is true for some initial conditions
2. Inductive hypothesis: Assume hypothesis is true for all values ≤ k
3. Inductive step: Show hypothesis is true for the next larger value (typically k+1)

### Example
- Prove arithmetic series: Σ(i from 1 to N) = N(N+1)/2

```
Base case: Show true for N=1
    1 = 1(1+1)/2 = 1

Inductive hypothesis: Assume true for all N<=k
    Assume Σ(i from 1 to k) = k(k+1)/2

Inductive step: Now see if it is true for N=k+1
    Σ(i from 1 to k+1) = (k+1) + Σ(i from 1 to k)
                       = (k+1) + k(k+1)/2
                       = (k+1)(k+2)/2
```

## Proof by Counterexample
### Definition
- Prove hypothesis is not true by giving an example that doesn’t work
### Example
- Hypothesis: 2N > N^2 ?
- Proof: N=2 (or 3 or 4)

```
Proof by example?
Proof by lots of examples?
Proof by all possible examples?

Empirical proof
Hard when input size and contents can vary arbitrarily
```

### Another Example for a proof by Counterexample
- Given N cities and costs for traveling between each pair of cities, a “least-cost tour” is one which visits every city exactly once with the least cost
- Hypothesis: Any sub-path within any least-cost tour will also be a least-cost tour for those cities included in the sub-path.

```
Least-cost tour
sub-path also least-cost
```

### Proof by counterexample
- Cost (A→B→C→D) = 40 (optimal)
- Cost (A→B→C) = 30
- Cost (A→C→B) = 20

```
A      B
|     / |
10  20 10
| /     |
D       C
```

## Proof by Contradiction
### Steps
1. Start by assuming that the hypothesis is false
2. Show this assumption could lead to a contradiction (i.e., some known property is violated)
3. Therefore, the hypothesis must be true

### Example for proof by contradiction
- Given N cities and costs for traveling between each pair of cities, find the least-cost path to go from city X to city Y
- Hypothesis: A least-cost path from X to Y contains least-cost paths from X to every city on the path
- E.g., if X→A→C→B→Y is a least-cost path from X to Y, then X→A→C→B must be a least-cost path from X to B

```
X A C B Y
```

### Proof by contradiction
- Let P be a least-cost path from X to Y
- Assume hypothesis is false: there exists C along X→Y path, such that there is a better path from X to C than the one in P
- Replace the subpath from X to C in P with this less-cost path, to create a new path P’ from X to Y
- Thus, we now have a better path from X to Y, i.e., cost(P’) < cost(P)
- But this violates the fact that P is a least-cost path from X to Y (hence a contradiction!)
- Therefore, the original hypothesis must be true

```
X C B
A Y
X→A→C is not least-cost
Condition: X→A→C→B→Y is least-cost
P1 = X→A→C
P2 = X→D→C
P1 > P2
P’=P2+P3
P = P1+P3
P’ < P
```

## Mathematical Recurrence vs. Recursion
- A recursive function or a recursive formula is defined in terms of itself

### Example
- Factorial (n)

```c
if (n = 0) then return 1
else return (n * Factorial (n-1))
```

## Basic Rules of Recursion
### Base cases
- Must always have some base cases, which can be solved without recursion
### Making progress
- Recursive calls must always make progress toward a base case
### Design rule
- Assume all recursive calls work
### Compound interest rule
- Try not to duplicate work by solving the same instance of a problem in separate recursive calls

## Example
### Fibonacci numbers

```c
F(0) = 1
F(1) = 1
F(n) = F(n-1) + F(n-2)

Fibonacci (n)
if (n ≤ 1) then return 1
else return (Fibonacci (n-1) + Fibonacci (n-2))
```

### Computation tree for: Fibonacci (5)


```
F(5)
│
├── F(4)
│   ├── F(3)
│   │   ├── F(2)
│   │   │   ├── F(1)
│   │   │   └── F(0)
│   │   └── F(1)
│   └── F(2)
│       ├── F(1)
│       └── F(0)
└── F(3)
    ├── F(2)
    │   ├── F(1)
    │   └── F(0)
    └── F(1)
```
- Runtime for the recursive code is proportional to the size of the tree and that is wasteful.
- Nodes for Depth D = 2^(D+1) - 1

### Running time for Fibonacci(n)?
- Show that T(n) > c * 1.6^n
```
Fibonacci(5)
```
### Rewrite
```
T(n) = T(n-1) + T(n-2) + O(1)
```
### Proof (continued)
```
T(n-1) + T(n-2) + O(1)
```

## Commonly used recurrences
### Binary search
- T(n) = T(n/2) + O(1) → O(lg n)
### Merge sort
- T(n) = 2T(n/2) + O(n) → O(n lg n)
### Exponential
- T(n) = T(n-1) + T(n-2) + O(1) → O(1.6^n)

---

### [Next Section: Data Structure Review](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Helpful-Material/(6)%20Data%20Structure%20Review)
