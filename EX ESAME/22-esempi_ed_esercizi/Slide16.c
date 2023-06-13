#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[], int i);
void print_list(struct nodo* head);
float somma(struct nodo* head);
float media(struct nodo* head);
float lunghezza(struct nodo* head);


int main(){
    int v[]={10,2,4,3,3,-1};
    struct nodo* headlist=build_list(v, 0);
    print_list(headlist);

    printf("La media vale: %.2f\n", media(headlist));

    return 0;
}

struct nodo* build_list(int v[], int i){
    struct nodo* head;
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

float somma(struct nodo* head){
    if(head==NULL){
        return 0;
    }

    return head->data+somma(head->next);
}

float lunghezza(struct nodo* head){
    if(head==NULL)
        return 0;
    
    return 1+lunghezza(head->next);
}

float media(struct nodo* head){
    float n=lunghezza(head);
    float sum=somma(head);
    sum=sum/n;
    return sum;
}

