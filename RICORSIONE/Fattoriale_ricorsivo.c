#include <stdio.h>

typedef unsigned long long int bigint;

bigint fattoriale(unsigned int n){
    if(n<=1)
        return 1;
    
    return n * fattoriale(n-1);
}

int main(){
    bigint n;

    printf("Inserire il numero: ");
    scanf("%u", &n);

    n=fattoriale(n);
    printf("Il fattoriale vale: %llu\n", n);
}