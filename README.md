# Open_mp_exemples
This project aims to explore the use of OpenMP for parallel programming through three labs that progressively introduce OpenMP's features. Each lab focuses on a different concept, such as handling variables with OpenMP directives, using reduction to optimize performance, and efficiently calculating prime numbers in parallel.
Project Title: Exploring Parallel Computing with OpenMP: Lab Series
# Project Overview

This project aims to explore the use of OpenMP for parallel programming through three labs that progressively introduce OpenMP's features. Each lab focuses on a different concept, such as handling variables with OpenMP directives, using reduction to optimize performance, and efficiently calculating prime numbers in parallel.

The three parts of this project are:

- **Lab 1**: [Introduction to OpenMP, focusing on variable handling with different OpenMP clauses](#lab-1-helloworld-with-openmp-clauses).
- **Lab 2**: [Optimization of array sum computation using parallel reduction and comparison with other synchronization methods](#lab-2-array-sum-with-reduction-atomic-and-critical).
- **Lab 3**: [Efficient prime number calculation in parallel, testing with various ranges of numbers and analyzing the performance](#lab-3-parallel-prime-number-calculation).

---

## Lab 1: HelloWorld with OpenMP Clauses

### Objective
Learn the basic syntax and features of OpenMP and how to control variable visibility and scoping through different clauses: `private`, `firstprivate`, and `shared`. The goal is to understand how variables are handled inside and outside parallel regions.

   - **private**: Each thread gets its own uninitialized copy. Changes made to the variable do not affect the original value outside the parallel region.
   - **firstprivate**: Each thread gets its own copy initialized with the value of the variable before the parallel region. Changes inside the region are not reflected outside.
   - **shared**: All threads share the same variable. Changes made by one thread affect all others, and changes persist outside the region.
   - **No Clauses**: The behavior depends on the default settings of the OpenMP implementation. If variables are treated as shared, race conditions may occur.

---

## Lab 2: Array Sum with Reduction, Atomic, and Critical

### Objective
Explore the use of OpenMP's `reduction` clause to compute the sum of values in an array. Compare the performance of `reduction` with other synchronization techniques such as `atomic` and `critical`.

   - **Reduction**: OpenMP internally optimizes the summation across threads, and the reduction clause ensures efficient handling of race conditions. This method is expected to be the fastest in most cases.
   - **Atomic**: The atomic clause ensures that only one thread at a time updates the shared sum variable, but it introduces some performance overhead compared to reduction.
   - **Critical**: The critical section is the most restrictive in terms of parallelism. It forces all threads to take turns updating the sum, which usually leads to the slowest execution time.


### Conclusion
Reduction should be preferred for summation tasks due to its balance of speed and safety.
Atomic is useful when fine-grained locking is needed, though it still incurs some performance overhead.
Critical should be avoided for simple summation due to its poor performance, as it serializes access to the shared variable.

---

## Lab 3: Parallel Prime Number Calculation

### Objective
Implement parallel code to compute prime numbers in different ranges. Measure and compare the total time taken for prime number calculations with different ranges (10, 100, 1000, 10,000, 100,000).

### Explanation
Outer Parallel Loop: The #pragma omp parallel for around the outer loop (for (int r = 0; r < num_ranges; r++)) allows each range (like 10, 100, etc.) to be processed in parallel by different threads.
Inner Parallel Loop: Inside the loop, for each range, there's another parallel #pragma omp parallel for that calculates the number of primes in the range. This uses reduction(+:count) to safely update the number of primes found.
Storing Results: The number of primes found for each range is stored in the results[] array, which is printed at the end.
