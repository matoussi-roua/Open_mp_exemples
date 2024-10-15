#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define ARRAY_SIZE 500000  // Define the size of the array

int main() {
    int variable_a[ARRAY_SIZE];  // Define the array
    long long sum = 0;  // Variable to store the sum
    double start_time, end_time;

    // Initialize the array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        variable_a[i] = i + 1;
    }
    printf("array size of variable_a: %d\n", ARRAY_SIZE);
    // Parallel sum using critical
    start_time = omp_get_wtime();  // Start time
    #pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; i++) {
        #pragma omp critical
	{
        sum += variable_a[i];  // Sum the elements
        }
    }
    
    end_time = omp_get_wtime();  // End time

    printf("Sum using critical: %lld\n", sum);
    printf("Time taken using critical: %f seconds\n", end_time - start_time);

    return 0;
}
