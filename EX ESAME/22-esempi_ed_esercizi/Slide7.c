#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[]);
int sequenza(struct nodo* head);
void print_list(struct nodo* head);

int main(){
    int v[]={1,1,2,1,7,1,2,2,2,1,2,1,1,1,1,1,8,-1};
    struct nodo* headlist=build_list(v);
    print_list(headlist);
    printf("La sequenza piu' lunga vale: %d\n", sequenza(headlist));
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

int sequenza(struct nodo* head){
    int c=1, max=0;

    while(head->next!=NULL){
        if(head->data==head->next->data){
            c++;
        }
        head=head->next;
        if(head->data!=head->next->data){
            if(c>max)
                max=c;
            c=1;
            head=head->next;
        }
    }
    return max;
}