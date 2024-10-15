#include <stdio.h>
#include <omp.h>

int main() {
    int thread_id = 100; // Variable defined outside parallel region

    #pragma omp parallel firstprivate(thread_id)
    {
        thread_id += omp_get_thread_num(); // Each thread gets its own copy initialized to 100
        printf("Thread %d, thread_id = %d\n", omp_get_thread_num(), thread_id);
    }

    printf("Outside parallel region, thread_id = %d\n", thread_id); // thread_id remains unchanged outside
    return 0;
}
