#include <stdio.h>
#include <omp.h>

int fib(int n) {
    if (n < 2)
        return n;
    int i, j;
    #pragma omp task shared(i)
    i = fib(n - 1);

    #pragma omp task shared(j)
    j = fib(n - 2);
    #pragma omp taskwait
    return i + j;
}
int main() {
    int n;
    printf("Enter the Fibonacci number to calculate: ");
    scanf("%d", &n);

    omp_set_dynamic(0);
    omp_set_num_threads(4);

    int result;
    #pragma omp parallel shared(n)
    {
        #pragma omp single
        result = fib(n);
    }

    printf("fib(%d) = %d\n", n, result);
    return 0;
}
