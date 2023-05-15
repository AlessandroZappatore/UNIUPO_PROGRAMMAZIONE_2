#include <stdio.h>
#include <stdlib.h>
int main () {
int *a,
*b;
int n,i;
printf("Inserisci la dimensione dell'array \n");
scanf("%d",&n);
a = (int *) calloc(n,sizeof(int));
for(i=0;i<n;i++) {
a[i] = 1000*i;
printf("a[%d] = %d \n" ,i,a[i]);
}
free(a);
b = (int *) calloc(n,sizeof(int));
for(i=0;i<n;i++) {
printf("b[%d] = %d \n" ,i,b[i]);
}
free(b);
return 0;
}