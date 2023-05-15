#include <stdio.h>

int main(){
int somma=0;
FILE* fp = fopen("numeri.txt", "r");

while(!feof(fp)){
int n;
fscanf(fp, "%d", &n);
somma+=n;
}

printf("La somma vale: %d\n", somma);
    return 0;
}