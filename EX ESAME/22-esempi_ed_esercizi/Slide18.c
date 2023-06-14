#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[]);
void print_list(struct nodo* head);
int conta3(struct nodo* head, int x);
void duplicate(struct nodo* head, int x, int n);

int main(){
    int v[]={2,3,1,6,1,2,2,6,1,5,5,5,5,-1};
    struct nodo* headlist=build_list(v);
    print_list(headlist);

    printf("I valori che si ripetono per tre volte sono: %d\n", conta3(headlist, 5));

    duplicate(headlist, 1, 3);
    print_list(headlist);
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

int conta3(struct nodo* head, int x){
    int c=0;

    while(head->next->next!=NULL){
        if(head->data==x&&head->data==head->next->data&&head->data==head->next->next->data)
            c++;
        head=head->next;
    }
    return c;
}

void duplicate(struct nodo* head, int x, int n){
    struct nodo* tmp=NULL;
    for(int i=1; head!=NULL; i++){
        if(head->data==x&&i%n==0){
            tmp=(struct nodo*)malloc(sizeof(struct nodo));
            tmp->data=head->data;
            tmp->next=head->next;
            head->next=tmp;
        }
        head=head->next;
    }
}