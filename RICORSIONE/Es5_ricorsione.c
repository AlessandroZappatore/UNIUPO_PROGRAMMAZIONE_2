#include <stdio.h>

int potenza(int n, int p);

int main(){
    int n, p;

    printf("Inserire la base: ");
    scanf("%d", &n);
    printf("Inserire l'esponente: ");
    scanf("%d", &p);

    n=potenza(n, p);
    printf("Il risultato e': %d\n", n);
    return 0;
}

int potenza(int n, int p){
    if(p<=0)
        return 1;
    
    return n*potenza(n, p-1);
}