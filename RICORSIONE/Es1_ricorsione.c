#include <stdio.h>

int somma(int n, int m);

int main()
{
    int n, m;

    printf("Inserire il primo numero: ");
    scanf("%d", &n);
    printf("Inserire il secondo numero: ");
    scanf("%d", &m);

    n = somma(n, m);

    printf("Il prodotto vale: %d\n", n);
}

int somma(int n, int m)
{
    if (m <= 1)
        return n;

    return n + somma(n, m - 1);
}