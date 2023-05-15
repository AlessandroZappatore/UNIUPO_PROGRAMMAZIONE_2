#include <stdio.h>

int max(int *v, int mas);

int main(){
    int v[100]={1,2,3,4,5,6,3,-1};

    int n=max(v, v[0]);
    printf("Il valore massimo e': %d\n", n);

    return 0;
}

int max(int *v, int mas){
    if(*v==-1)
        return mas;
    if(*v>mas)
        mas=*v;

    return max(++v, mas);
}