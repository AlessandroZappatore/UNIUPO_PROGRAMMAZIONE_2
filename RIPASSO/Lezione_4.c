/*Scrivere una funzione che prenda in input un intero, e restituisca un array di interi della dimensione specificata*/

#include <stdio.h>
#include <stdlib.h>

int *alloca(int a){
    return (int*) malloc(sizeof(int)*a);
}

int main(){
   int a=10, p[a];

   alloca(a);

return 0;
}