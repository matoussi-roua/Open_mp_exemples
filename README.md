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

### Tasks
- Implement a simple HelloWorld program with OpenMP.
- Test with/without different OpenMP clauses: `private`, `firstprivate`, and `shared`.
- Observe how the variables behave when placed inside and outside parallel regions.

### Steps
1. Write a simple HelloWorld program.
2. Use OpenMP to parallelize the printing of messages using the `#pragma omp parallel` directive.
3. Experiment with the following clauses:
   - **private**: Ensures each thread has its own local copy of a variable.
   - **firstprivate**: Similar to `private`, but the initial value is copied from the main thread.
   - **shared**: All threads access the same variable.

### Conclusion
Summarize how different clauses impact variable visibility and performance. Discuss how variables declared inside/outside the parallel region behave with each OpenMP clause.

---

## Lab 2: Array Sum with Reduction, Atomic, and Critical

### Objective
Explore the use of OpenMP's `reduction` clause to compute the sum of values in an array. Compare the performance of `reduction` with other synchronization techniques such as `atomic` and `critical`.

### Tasks
- Implement parallel code for array sum computation using the `reduction` clause.
- Compare the response time with implementations using `atomic` and `critical`.

### Steps
1. Initialize an array with a large number of elements.
2. Use OpenMP to compute the sum of the array elements using the `reduction` clause.
3. Implement the same sum calculation using `atomic` and `critical` to protect the sum variable.
4. Measure and compare the execution time for each implementation.

### Conclusion
Analyze the time taken by each method (reduction, atomic, critical) and conclude which method is most efficient for parallel sum computations.

---

## Lab 3: Parallel Prime Number Calculation

### Objective
Implement parallel code to compute prime numbers in different ranges. Measure and compare the total time taken for prime number calculations with different ranges (10, 100, 1000, 10,000, 100,000).

### Tasks
- Implement code to calculate prime numbers in parallel using OpenMP.
- Test the implementation with different number ranges.
- Measure the total time taken for each range.

### Steps
1. Write a function to check if a number is prime.
2. Use OpenMP to parallelize the process of finding prime numbers.
3. Run the code for different number ranges (e.g., 10, 100, 1000, 10,000, 100,000).
4. Record and compare the time taken for each range.

### Conclusion
Summarize the performance of the parallel prime number computation for different ranges. Discuss any potential performance bottlenecks or scalability issues.

