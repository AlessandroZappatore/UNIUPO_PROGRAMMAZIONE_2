#include <stdio.h>

void divisori(int n, int m);

int main()
{
    int n;

    printf("Inserire il numero: ");
    scanf("%d", &n);

    printf("I divisori di %d sono:\t ", n);
    divisori(n, n);

    return 0;
}

void divisori(int n, int m)
{
    if (n % m == 0)
        printf("%d\t", m);

    if(m==1)
        return;
        
    divisori(n, m - 1);
}