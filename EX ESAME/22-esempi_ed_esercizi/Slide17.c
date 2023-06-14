#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[]);
void print_list(struct nodo* head);
int media_pesata(struct nodo* head, int x);
int differenza(struct nodo* head, int n, int m);

int main(){
    int v[]={3,2,5,3,6,7,4,2,-1};
    struct nodo* headlist=build_list(v);
    print_list(headlist);

    printf("La media pesata vale: %d\n", media_pesata(headlist, 2));

    printf("La differenza vale: %d\n", differenza(headlist, 3, 5));
    return 0;
}

struct nodo* build_list(int v[]){
    struct nodo* head=NULL;
    struct nodo* tail=NULL;
    struct nodo* tmp=NULL;

    head=(struct nodo*)malloc(sizeof(struct nodo));
    head->data=v[0];
    head->next=NULL;
    tail=head;

    for(int i=1; v[i]!=-1; i++){
        tmp=(struct nodo*)malloc(sizeof(struct nodo));
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

int media_pesata(struct nodo* head, int x){
    int sum=0;
    for(int i=1; head!=NULL; i++){
        if(i%x==0){
            sum+=head->data*i;
        }
        head=head->next;
    }
    return sum;
}

int differenza(struct nodo* head, int n, int m){
    int sum1=0, sum2=0;

    for(int i=1; head!=NULL; i++){
        if(i<=n){
            sum1+=head->data;
        }
        else if(i>n&&i<=m){ 
            sum2+=head->data;
        }
        head=head->next;
    }
    return sum1-sum2;
}