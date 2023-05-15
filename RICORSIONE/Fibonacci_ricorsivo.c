#include <stdio.h>

typedef unsigned long long int bigint;

bigint fibonacci(unsigned int n);

int main()
{
    bigint n;

    printf("Inserire il numero: ");
    scanf("%u", &n);

    
    n = fibonacci(n);

    printf("La serie di fibonacci vale: %llu\n", n);
}

bigint fibonacci(unsigned int n)
{
    if (n == 0 || n == 1)
        return n;

    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}