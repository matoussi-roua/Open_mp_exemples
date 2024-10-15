// hello_world_basic.c
#include <stdio.h>
#include <omp.h>

int main() {
    printf("Hello from the master thread. First exemple with private variable thread_id\n");
    int cores = omp_get_num_procs();
    printf("Number of available processors: %d\n", cores);

    int thread_id = 0;
    printf("Inside parallel region : \n");
    #pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num();
        printf("Hello from thread %d\n", thread_id);
    }
    printf("Outside parallel region, thread_id = %d\n", thread_id); // x remains unchanged outside
    return 0;
}
