#include <stdio.h>
#include <omp.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;  // 0 and 1 are not primes
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;  // If divisible, it's not prime
    }
    return 1;  // If no divisors found, it's prime
}

int main() {
    // Array of ranges we want to test
    int ranges[] = {10, 100, 1000, 10000, 100000};
    int num_ranges = sizeof(ranges) / sizeof(ranges[0]);  // Get the number of ranges
    int results[num_ranges];  // Array to store the prime count for each range
    double times[num_ranges];  // Array to store the time taken for each range

    // Outer loop for each range, run in parallel
    #pragma omp parallel for
    for (int r = 0; r < num_ranges; r++) {
        int range = ranges[r];
        int count = 0;
        double start_time, end_time;

        start_time = omp_get_wtime();  // Start time for this range

        // Parallel region to find primes in each range
        #pragma omp parallel for reduction(+:count)
        for (int i = 2; i <= range; i++) {
            if (is_prime(i)) {
                count++;  // Safely increment count for each prime found
            }
        }

        end_time = omp_get_wtime();  // End time for this range
        times[r] = end_time - start_time;  // Store the time taken for this range
        results[r] = count;  // Store the result for this range
    }

    // Print results and time for each range
    for (int r = 0; r < num_ranges; r++) {
        printf("Number of primes in range [2, %d]: %d\n", ranges[r], results[r]);
        printf("Time taken for range [2, %d]: %f seconds\n", ranges[r], times[r]);
    }

    return 0;
}
