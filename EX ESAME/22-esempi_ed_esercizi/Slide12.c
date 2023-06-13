#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[]);
void print_list(struct nodo* head);
void somma(struct nodo* lis1, struct nodo* lis2, int *sum1, int *sum2);

int main(){
    int v1[]={1,1,2,1,7,1,2,-1};
    int v2[]={2,2,1,2,1,1,1,1,1,8,-1};
    struct nodo* headlist1=build_list(v1);
    print_list(headlist1);
    struct nodo* headlist2=build_list(v2);
    print_list(headlist2);

    int sum1=0, sum2=0;
    somma(headlist1, headlist2, &sum1, &sum2);
    if(sum1>sum2)
        printf("Output: %d\n", sum1);
    else
        printf("Output: %d\n", sum2);

    return 0;
}

struct nodo* build_list(int v[]){
    struct nodo* head=NULL;
    struct nodo* tail=NULL;
    struct nodo* tmp=NULL;

    head=(struct nodo*) malloc(sizeof(struct nodo));
    head->data=v[0];
    head->next=NULL;
    tail=head;

    for(int i=1; v[i]!=-1; i++){
        tmp=(struct nodo*) malloc(sizeof(struct nodo));
        tmp->data=v[i];
        tmp->next=NULL;
        tail->next=tmp;
        tail=tmp;
    }

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

void somma(struct nodo* lis1, struct nodo* lis2, int *sum1, int *sum2){
    if(lis1==NULL&&lis2==NULL){
        return;
    }

    if(lis1!=NULL&&lis2!=NULL){
        *sum1+=lis1->data;
        *sum2+=lis2->data;
         somma(lis1->next, lis2->next,sum1, sum2);
    }
    if(lis1==NULL&&lis2!=NULL){
        *sum2+=lis2->data;
         somma(lis1, lis2->next, sum1, sum2);
    }
    if(lis1!=NULL&&lis2==NULL){
        *sum1+=lis1->data;        
         somma(lis1->next, lis2, sum1, sum2);
    }
}

