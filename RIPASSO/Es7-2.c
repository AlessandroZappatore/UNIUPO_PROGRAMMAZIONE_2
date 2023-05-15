#include <stdio.h>
#define DIM 10

int main(){
int array[DIM];

FILE* fp = fopen("numeri.txt", "r");

int i=0;
while(!feof(fp)){
    int n;
    fscanf(fp, "%d", &n);
    array[i++]=n;
}
fclose(fp);

FILE* file = fopen("numeri2.txt", "w");
while(i>0){
    i--;
    fprintf(file, "%d\t", array[i]);
}
fclose(file);
    return 0;
}