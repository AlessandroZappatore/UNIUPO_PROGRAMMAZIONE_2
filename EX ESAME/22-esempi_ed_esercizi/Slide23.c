#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[], int i);
void print_list(struct nodo* head);
int uguali(struct nodo* L1, struct nodo* L2);
struct nodo* new_list(struct nodo* L1, struct nodo* L2, int i);

int main(){
    int v[]={3,4,3,7,8,6,1,-1};
    struct nodo* L1=build_list(v, 0);
    printf("L1: ");
    print_list(L1);
    int v1[]={1,4,2,7,2,12,2,16,7,2,-1};
    struct nodo* L2=build_list(v1, 0);
    printf("L2: ");
    print_list(L2);
    printf("Numero di nodi uguali: %d\n", uguali(L1, L2));

    struct nodo* L3=new_list(L1, L2, 1);
    printf("L3: ");
    print_list(L3);
    return 0;
}

struct nodo* build_list(int v[], int i){
    struct nodo* head=NULL;
    if(v[i]==-1)
        return NULL;

    head=(struct nodo*)malloc(sizeof(struct nodo));
    head->data=v[i];
    head->next=build_list(v, i+1);
    return head;
}

void print_list(struct nodo* head){
    if(head==NULL){
        printf("NULL\n");
        return;
    }

    printf("%d -> ", head->data);
    print_list(head->next);
}

int uguali(struct nodo* L1, struct nodo* L2){
    if(L1==NULL||L2==NULL)
        return 0;

    if(L1->data==L2->data)
        return 1+uguali(L1->next, L2->next);
    else
        return uguali(L1->next, L2->next);
}

struct nodo* new_list(struct nodo* L1, struct nodo* L2, int i){
    struct nodo* tmp=NULL;

    if(L1==NULL||L2==NULL)
        return NULL;

    if((L1->data-L2->data)%i==0){
        tmp=(struct nodo*)malloc(sizeof(struct nodo));
        tmp->data=L1->data-L2->data;
        tmp->next=new_list(L1->next, L2->next, i+1);
        return tmp;
    }
    else
        return new_list(L1->next, L2->next, i+1);
}