#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[]);
void print_list(struct nodo* head);
int delete(struct nodo** head, int x);

int main(){
    int v1[]={2,2,5,6,7,9,-1};
    struct nodo* headlist1=build_list(v1);
    print_list(headlist1);

    int mul=delete(&headlist1, 3);
    printf("Output: %d\n", mul);
    print_list(headlist1);
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

int delete(struct nodo** head, int x){
    struct nodo* tmp=NULL;
    if(*head==NULL)
        return 0;

    if((*head)->data%x==0){
        tmp=*head;
        *head=(*head)->next;
        free(tmp);
        return 1+delete(&(*head), x);
    }
    else
        return delete(&(*head)->next, x);
}

