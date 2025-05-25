#include <stdio.h>
#include <omp.h>

float f(int x) {
    return x * 1.0f;  // convert int to float
}

int main()
{
    float result = 0.0;

    #pragma omp parallel
    {
        float B;
        int i, id, nthreads;

        id = omp_get_thread_num();
        nthreads = omp_get_num_threads();

        for (i = id; i < nthreads; i++) {
            B = f(i);

            // Critical Section - Only one thread can execute this block at a time
            #pragma omp critical
            {
                result += B;
            }
        }
    }
    printf("Final result: %f\n", result);
    return 0;
}
