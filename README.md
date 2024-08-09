> [!IMPORTANT]  
> I dont have access to Exam Material, If studying for exam, try looking at coursehero or some other format. I have a few midterm questions that may be helpful. 


### Question 1
**What is the time complexity of fun()?**

```c
int fun(int n)
{
    int count = 0;
    for (int i = n; i > 0; i /= 2)
        for (int j = 0; j < i; j++)
            count += 1;
    return count;
}
```
#### Possible Answers:
- O(log(n) log(n) n)
- O(log(n) n)
- O(log(n))
- O(n^2)
- O(n)
  
`Correct Answer: O(n)`

#### **Explanation**: This function consists of two nested loops. The outer loop has a variable i that starts from n and is halved each iteration (i /= 2), running until i is greater than 0. The inner loop iterates from j = 0 to j < i, incrementing count in each iteration.

##### To determine the time complexity, we need to look at the number of times count is incremented:
- In the first iteration of the outer loop, the inner loop runs n times.
- In the second iteration, it runs n/2 times.
- In the third iteration, n/4 times, and so on.
- The sum of this series is n + n/2 + n/4 + n/8 + ..., which is a geometric series converging towards 2n. Therefore, the total number of operations (or increments of count) is proportional to n, making the time complexity O(n). This is due to the fact that the series, while halving each term, still sums up to a constant multiple of n, reflecting that the overall number of inner loop iterations scales linearly with n.

---

### Question 2
**Which of the following is not O(n^2)?**

- **Possible Answers**:
  - (2^20) * n^2 + 1234 * n
  - (n^3 + 1000) / n
  - (n^5 + n^2 + 1000 * n) / (n^2)
  - (15^10) * n^2 + 1000000

`Correct Answer: (n^5 + n^2 + 1000 * n) / (n^2)`

#### **Explanation**: The given expression simplifies to n^3 + 1 + 1000/n. The term n^3 dominates the other terms for large values of n. Thus, the asymptotic complexity of the expression is O(n^3), not O(n^2). 

- (2^20) * n^2 + 1234 * n simplifies to a constant times n^2 plus a linear term, which is still O(n^2) since n^2 dominates the linear term as n grows larger.
- (n^3 + 1000) / n simplifies to n^2 + 1000/n, which is clearly O(n^2) because n^2 is the highest degree term.
- (n^5 + n^2 + 1000 * n) / (n^2) as already mentioned, simplifies to n^3 + 1 + 1000/n, which is O(n^3) because the n^3 term grows faster than n^2 as n increases.
- (15^10) * n^2 + 1000000 is straightforwardly O(n^2) because it is a constant multiplied by n^2 plus another constant.

--- 

### Question 3
**What is the time complexity of fun()?**

```c
int fun(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j > 0; j--)
            count += 1;
    return count;
}
```

#### Possible Answers:
- Theta(log(n))
- Theta(n)
- Theta(log(n) log(n) n)
- Theta(n^2)
- Theta(log(n) n)
  
`Correct Answer: Theta(n^2)`

#### **Explanation**: The function includes two nested loops. The outer loop iterates n times from i = 0 to n-1. The inner loop, however, iterates i times, decrementing j starting from i. The number of iterations for the inner loop increases linearly with each iteration of the outer loop. This results in a total number of operations equivalent to the sum of the first n natural numbers, which is (n(n+1))/2, leading to a complexity of Theta(n^2), as this sum simplifies to an n^2 term dominating the growth.

---

### Question 4
#### Choose all correct statements.

#### Possible Answers:
- In the options of the command line program g++, -o is the one that tells g++ the name of the generated executable program.
- Make is a tool to help build software that specifies the compilation details, e.g., the dependencies.
- CMake is a platform-dependent building system generator that generates MakeFile for Make and it cannot be used across different platforms or operating systems.
- Git is a useful distributed version control system. When you use "git commit," it means that you are going to switch between different branches.
- UNIX filesystem is in a tree structure with / as the root node.

#### Correct Answers:

- In the options of the command line program g++, -o is the one that tells g++ the name of the generated executable program.
- Make is a tool to help build software that specifies the compilation details, e.g., the dependencies.
- UNIX filesystem is in a tree structure with / as the root node.

#### Explanation:
- The `-o` option in g++ specifies the name of the output file.
- `Make` indeed is used to manage dependencies and orchestrate build processes, but it does not detail the specific compilation commands without a Makefile.
- `CMake` is incorrect because it is not platform-dependent; rather, it is designed to work across different platforms.
- The statement about `git commit` is incorrect; this command commits changes to the current branch, not switches between branches.
- The UNIX filesystem is indeed structured as a tree with `/` as the root, which is fundamental to its design.

--- 

### Question 5
**Big Omega defines**

- **Possible Answers**:
  - None of them
  - Lower bound
  - Middle bound
  - Upper bound

`Correct Answer: Lower bound`

**Explanation**: Big Omega (Ω) is used in computational complexity theory to describe the asymptotic lower bound of an algorithm, indicating the minimum resources needed regardless of input size. It represents the best case under any circumstances for a given algorithm, providing a guarantee that the algorithm will not perform worse than the Omega bound.

---

### Question 6
**Given two lists, which both include N integers without duplicate elements. Suppose one list is sorted, while the other one is unsorted. If we are going to determine whether the two lists contain exactly all the same values using nested for-loops (assume that we cannot sort the unsorted list), what is the possible time complexity for the worst-case running?**

- **Possible Answers**:
  - O(N)
  - O(N * log(N) * log(N))
  - O(N + log(N))
  - O(N * log(N))

`Correct Answer**: O(N * log(N))`

**Explanation**: The correct strategy involves performing a binary search for each element of the unsorted list within the sorted list. Since binary search has a time complexity of O(log(N)) and we need to perform this search for each of the N elements in the unsorted list, the total time complexity becomes O(N * log(N)). This accounts for the fact that for every element in the unsorted list, we perform a search operation in the sorted list, and these searches accumulate multiplicatively in terms of computational cost.

---

### Question 7
**In a competition, four different functions are observed. All the functions use a single loop and within the loop, the same set of statements are executed. Consider the following for loops: if n is the size of input (positive), which function is most efficient (if the task to be performed is not an issue)?**

- **Possible Answers**:
  - for(i = 0; i < n; i++)
  - for(i = 0; i < n; i += 2)
  - for(i = n; i > -1; i /= 2)
  - for(i = 1; n; i *= 2)

`Correct Answer: for(i = 1; n; i *= 2)`

**Explanation**: The loop `for(i = 1; n; i *= 2)` increases exponentially, effectively halving the number of iterations compared to linear growth. This makes it the most efficient loop in terms of the number of iterations. It runs approximately log(n) times because each iteration doubles the value of `i`, reaching `n` exponentially faster than linear increments or decrements.

---

### Question 8
**Suppose we have an algorithm with the recurrence for the worst-case runtime as T(n) = T(n/2) + O(1) and T(1) = 1. What is the time complexity in big-O notation in the simplest format?**

- **Possible Answers**:
  - O(n^3)
  - O(log(n))
  - O(log(n) n)
  - O(n)
  - O(n^2)

`Correct Answer: O(log(n))`

**Explanation**: This algorithm exhibits a divide-and-conquer strategy, where each recursive call processes half of the input size (n/2) plus a constant time operation (O(1)). The recurrence relation, T(n) = T(n/2) + O(1), leads to a solution that requires O(log(n)) steps, as each step halves the size of the problem until reaching the base case. This is typical of binary search-type algorithms and other similar divide-and-conquer approaches.

---

### Question 9
**Recursive function: given any problem, if there are two algorithms to solve it (i) using a loop, and (ii) using a recursive function, then we can conclude that (i) is always slower than (ii). Is this conclusion TRUE or FALSE?**

- **Possible Answers**:
  - True
  - False

`Correct Answer: False`

**Explanation**: The statement is a generalization that does not hold in all cases. Whether an iterative (loop) or recursive implementation is faster depends on the specific problem, the algorithm used, and how each is implemented. Some problems are more naturally suited to recursion (like tree traversals), while others are more efficiently solved using iterative approaches. Additionally, recursive functions can lead to performance issues like stack overflow if not carefully managed or if tail recursion is not used when appropriate.

---

### Question 10
**The increasing order of the following functions in terms of their complexity is (smallest complexity in the first position; largest complexity in the last position):**

- **Possible Answers**:
  - f2(n), f1(n), f4(n), f3(n)
  - f1(n), f2(n), f4(n), f3(n)
  - f1(n), f2(n), f3(n), f4(n)
  - f1(n), f4(n), f2(n), f3(n)

`Correct Answer: f1(n), f2(n), f4(n), f3(n)`

**Explanation**: Analyzing the functions:
- f1(n) = n^0.9 is essentially sublinear, growing slower than any linear function.
- f2(n) = 1000000 * n is a linear function, just with a large coefficient.
- f4(n) = n^2 is a quadratic function, growing faster than any linear function.
- f3(n) = 1.000001^n is exponential, growing faster than any polynomial function.

The increasing order of complexity based on the functions' growth rates is:
1. Sublinear (f1)
2. Linear (f2)
3. Quadratic (f4)
4. Exponential (f3)

This order reflects the typical hierarchy in computational complexity where exponential growth far exceeds polynomial growth rates.

