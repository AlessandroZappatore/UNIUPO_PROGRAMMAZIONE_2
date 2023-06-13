#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[]);
void print_list(struct nodo* head);
struct nodo* somma(struct nodo* lis1, struct nodo* lis2);

int main(){
    int v1[] = {2, 2, 5, 6, 7, 9, -1};
    struct nodo *headlist1 = build_list(v1);
    print_list(headlist1);
    int v2[] = {2,1,2,17,3,-1};
    struct nodo *headlist2 = build_list(v2);
    print_list(headlist2);

    struct nodo* headlist3= somma(headlist1, headlist2);
    print_list(headlist3);

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

struct nodo* somma(struct nodo* lis1, struct nodo* lis2){
    struct nodo* head=NULL;
    struct nodo* tail=NULL;
    struct nodo* tmp=NULL;

    while(lis1!=NULL&&lis2!=NULL){
        if(lis1!=NULL&&lis2!=NULL){
            if(head==NULL){
                head=(struct nodo*)malloc(sizeof(struct nodo));
                head->data=lis1->data+lis2->data;
                head->next=NULL;
                tail=head;
            }
            else{
                tmp=(struct nodo*)malloc(sizeof(struct nodo));
                tmp->data=lis1->data+lis2->data;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tmp;
            }
            lis1=lis1->next;
            lis2=lis2->next;
        }
        if(lis1!=NULL&&lis2==NULL){
            if(head==NULL){
                head=(struct nodo*)malloc(sizeof(struct nodo));
                head->data=lis1->data;
                head->next=NULL;
                tail=head;
            }
            else{
                tmp=(struct nodo*)malloc(sizeof(struct nodo));
                tmp->data=lis1->data;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tmp;
            }
            lis1=lis1->next;
        }
        if(lis1==NULL&&lis2!=NULL){
            if(head==NULL){
                head=(struct nodo*)malloc(sizeof(struct nodo));
                head->data=lis2->data;
                head->next=NULL;
                tail=head;
            }
            else{
                tmp=(struct nodo*)malloc(sizeof(struct nodo));
                tmp->data=lis2->data;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tmp;
            }
            lis2=lis2->next;
        }
    }
    return head;
}
