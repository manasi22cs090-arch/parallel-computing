#include <stdio.h>
#include <time.h>

int main() {
    int n;
    long long sum = 0;
    clock_t start, end;

    printf("Enter n: ");
    scanf("%d", &n);

    start = clock();
    for (int i = 1; i <= n; i++) sum += i;
    end = clock();
    printf("Sum = %lld\n", sum);
    printf("Time = %.6f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
