#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file = fopen("numeri.txt", "r");
    if(file==NULL){
        printf("ERRORE\n");
        return -1;
    }
int* arr=NULL;
int n;
int num;
    while(!feof(file)){
    fscanf(file, "%d ", &n);
    if(arr==NULL){
        arr = malloc(sizeof(int));
    }
    else{
        arr=realloc(arr,sizeof(int)*(num+1));
    }
    arr[num]=n;
    num++;
    }

    for(int i=0; i<num; i++)   
        printf("%d:%d\n", i, arr[i]);
    fclose(file);
    free(arr);
    return 0;
}