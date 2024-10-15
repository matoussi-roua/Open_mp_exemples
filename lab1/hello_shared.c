 // hello_world_basic.c
#include <stdio.h>
#include <omp.h>

int main() {
    printf("Hello from the master thread.\n");
    int cores = omp_get_num_procs();
    printf("Number of available processors: %d\n", cores);

    int thread_id = 1000;
    printf("Thread id initialized with : 1000.\n Inside parallel region : \n");
    #pragma omp parallel shared(thread_id)
    {
        thread_id += omp_get_thread_num();
        printf("Thread %d, thread_id = %d\n", omp_get_thread_num(), thread_id);
    }
    printf("Outside parallel region, thread_id = %d\n", thread_id); // thread_id is changed outside
    return 0;
}
