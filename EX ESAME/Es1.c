#include <stdio.h>
#include <stdlib.h>

int minimo(int arr[], int l);
int massimo(int arr[], int l);
int media(int *arr, int l);

int main(){
    FILE* fp=fopen("numeri.txt", "r");
    int n, *arr, i=0;

    if(fp!=NULL){
        while(!feof(fp)){
            fscanf(fp, "%d ", &n);
            if(n>0){
            if(i==0){
                arr=(int*)malloc(sizeof(int));
                arr[i]=n;
            }
            else{
                arr=(int*)realloc(arr, sizeof(int)*(i+1));
                arr[i]=n;
            }
            i++;
            }
        }
        fclose(fp);

        int l=i;

        for(i=0; i<l; i++)
            printf("%d:%d\t", i, arr[i]);
        printf("\n");

        int min, max, med;

        printf("La media vale: %d\nIl massimo vale: %d\n Il minimo vale: %d\n", media(arr, l), massimo(arr, l), minimo(arr, l));
    }
    else
        printf("ERRORE, file inesistente\n");
    
    free(arr);
return 0;
}

int minimo(int arr[], int l){
    int min=arr[0];

    for(int i=1; i<l; i++){
        if(min>arr[i])
            min=arr[i];
    }

    return min;
}

int massimo(int arr[], int l){
    int max=arr[0];

    for(int i=0; i<l; i++){
        if(max<arr[i])
            max=arr[i];
    }

    return max;
}

int media(int *arr, int l){
    int med=0;

    for(int i=0; i<l; i++){
        med+=arr[i];
    }

    return med/l;
}