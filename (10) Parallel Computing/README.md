# Parallel Computing

## Introduction to Parallel Programming

### Why Parallel Programs
- Running multiple instances of a serial program is inefficient.
- Parallel programs are needed to make processes finish faster by leveraging multiple processors.

### Writing Parallel Programs
- **Task Parallelism**: Partition various tasks among CPU cores.
- **Data Parallelism**: Partition the data among CPU cores with each core performing similar operations on its part of the data.

### Coordination in Parallel Programs
- Cores need to coordinate their work via:
  - **Communication**: One or more cores send their current partial sums to another core.
  - **Load Balancing**: Share the work evenly among cores.
  - **Synchronization**: Ensure cores do not get too far ahead of the rest.

### Memory Models
- **Shared Memory**: All threads share a single address space.
```cpp
  // Example of shared memory architecture
  CPU core #1, CPU core #2, ... all share a common memory
```
- Distributed Memory: Each process has its own local memory, and processes communicate by sending messages.

```cpp
// Example of distributed memory architecture
Compute node 1: local memory, Compute node 2: local memory, ... interconnected via a network
```

### Foster's Methodology for Parallel Programming
1. **Partitioning**: Divide computation and data into tasks that can be executed in parallel.
2. **Communication**: Determine the necessary communication among tasks.
3. **Aggregation**: Combine tasks and communications into larger tasks.
4. **Mapping**: Assign composite tasks to processes/threads to minimize communication and balance workload.


### OpenMP for Shared Memory Multithreading

#### OpenMP Basics
- OpenMP is used for multithreading in shared memory architectures.
- It uses a primary thread that forks sub-threads to perform tasks concurrently.

#### Pragmas in OpenMP
Special preprocessor instructions (e.g., `#pragma omp parallel`) are used to define parallel regions in code.
```cpp
#pragma omp parallel
{
    // code to be run in parallel
}
```
- The `num_threads` clause specifies the number of threads.
```cpp
#pragma omp parallel num_threads(4)
{
    // code to be run by 4 threads
}
```
#### Parallel Code Template

```cpp
#include <omp.h>
int main() {
    int p = 4; // user-specified number of threads
    omp_set_num_threads(p);
    #pragma omp parallel
    {
        // parallel region code
    }
    return 0;
}
```
#### Scope in OpenMP
- **Shared Scope**: Variables accessible by all threads.
- **Private Scope**: Variables accessible by a single thread.

#### Synchronization in OpenMP
- **Critical Section**: Only one thread executes the block at a time.
```cpp
#pragma omp critical
{
    // critical section code
}
```
- **Atomic Operations**: Ensures atomicity for specific operations on shared variables.
  
```cpp
#pragma omp atomic
variable += value;
```

### Measuring Performance
#### Taking Timings
- Measure execution time to evaluate the performance of parallel programs.
  - **CPU Time**: Time spent executing user and kernel code.
  - **Wall Clock Time**: Actual elapsed time.

### Speedup and Scalability
- **Speedup: Ratio of serial execution time to parallel execution time.

```
Speedup (S) = T_serial / T_parallel
```

- **Scalability**: Ability to handle increasing problem sizes with increased resources.
  - **Strong Scaling**: Efficiency remains fixed without increasing problem size.
  - **Weak Scaling**: Efficiency remains fixed by increasing problem size proportional to the number of processors.

```cpp
// Example of studying scalability
// Input size (n) and Number of threads (p)
// n = 1,000, p = 1, 2, 4, 8, 16
// Time (s) = 800, 410, 201, 150, 100 for p = 1, 2, 4, 8, 16
```







---

### [Next Section: (11) Hashing](https://github.com/MarkShinozaki/CPTS223-AdvancedDataStructuresInCpp/tree/Lecture-Slides/(11)%20Hashing)
