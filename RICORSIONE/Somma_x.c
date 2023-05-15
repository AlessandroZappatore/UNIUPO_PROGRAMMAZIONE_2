#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

struct linked_list {
DATA d;
struct linked_list *next;
};

typedef struct linked_list ELEMENT;

typedef ELEMENT * LINK;

LINK newnode(void) {
return malloc(sizeof(ELEMENT));
}

LINK buildlis_alt(int a[], int x, int n) {
    LINK p;
    if (x> n) return NULL;
    else {
        p=newnode();
        p->d = a[x];
        p->next = buildlis_alt(a, x+1,n);
        return p;
    }
}

void somma_x(LINK lis, int *sum, int pos, int x){
    if(lis!=NULL){
        if(pos%x==0) *sum+=lis->d;
        somma_x(lis->next, sum, pos+1, x);
    }
}

int somma_l(LINK lis, int pos, int l){
    if(lis==NULL) return 0;
    else
        if(pos<=l)  return lis->d+somma_l(lis->next, pos+1, l);
        else    return 0;
}

int main(){
    LINK a;
    int pos=1, sum, x;

    int arr[10] ={5,4,3,4,5,3,2,7,5,1};
    a = buildlis_alt(arr,0,9);


    printf("Inserire il valore: ");
    scanf("%d", &x);

    //somma_x(a, &sum, pos, x);
    sum=somma_l(a, pos, x);
    //printf("La somma vale: %d\n", sum);
    printf("La somma dei valori inferiori di %d vale: %d\n", x, sum);
    return 0;
}