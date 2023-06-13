#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[]);
void print_list(struct nodo* head);
void delete_fr(struct nodo** head, int k);

int main(){
    int v[]={11,1,3,9,7,10,4,-1};
    struct nodo* headlist=build_list(v);
    print_list(headlist);

    delete_fr(&headlist, 10);
    print_list(headlist);

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

void delete_fr(struct nodo** head, int k){
    struct nodo* tmp=NULL;
    if(*head!=NULL){
        if((*head)->data==k){
        tmp=*head;
        *head=(*head)->next;
        free(tmp);
        return;
        }
        delete_fr(&(*head)->next, k);
    }
}