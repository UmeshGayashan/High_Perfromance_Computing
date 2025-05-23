#include<stdio.h>
#include<omp.h>

int main()
{
    int A[1000];
    int B = 150;
    #pragma omp parallel num_threads(4) shared(A) private(B)
    {
        int ID = omp_get_thread_num();
        B = A[ID];
        printf("value of B is %d  Thread %d\n", B, ID); 
    }
    printf("value of B is %d\n", B);
    return 0;
}