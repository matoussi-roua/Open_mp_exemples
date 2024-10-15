#include <stdio.h>
#include <omp.h>

#define RANGE 100000 // Adjust this for different ranges (10, 100, 1000, 10000, 100000)

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not primes
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int count = 0; // To count the number of primes
    double start_time, end_time;

    start_time = omp_get_wtime(); // Start timing

    // Parallel region
    #pragma omp parallel for reduction(+:count)
    for (int i = 2; i <= RANGE; i++) {
        if (is_prime(i)) {
            count++; // Increment count for each prime found
        }
    }

    end_time = omp_get_wtime(); // End timing

    printf("Number of prime numbers in the range [2, %d]: %d\n", RANGE, count);
    printf("Time taken: %f seconds\n", end_time - start_time);

    return 0;
}
