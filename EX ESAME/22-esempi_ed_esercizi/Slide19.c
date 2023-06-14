#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[]);
void print_list(struct nodo* head);
struct nodo* dup_sum(struct nodo* head);
struct nodo* new_list(struct nodo* lis1, struct nodo* lis2, int n, int m);

int main(){
    int v[]={2,3,5,8,1,2,2,4,1,5,-1};
    struct nodo* headlist=build_list(v);
    printf("HEADLIST: ");
    print_list(headlist);

    struct nodo* head_sum=dup_sum(headlist);
    printf("HEAD SUM: ");
    print_list(head_sum);

    int v1[]={5,1,5,-1};
    struct nodo* lis1=build_list(v1);
    printf("LIS1: ");
    print_list(lis1);
    int v2[]={4,4,11,3,4,8,7,-1};
    struct nodo* lis2=build_list(v2);
    printf("LIS2: ");
    print_list(lis2);
    struct nodo* lis3=new_list(lis1, lis2, 2, 5);
    printf("LIS3: ");
    print_list(lis3);
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

struct nodo* dup_sum(struct nodo* head){
    struct nodo* lis=NULL;
    struct nodo* tmp=NULL;
    struct nodo* tail=NULL;

    while(head->next->next!=NULL){
        if(head->data+head->next->data==head->next->next->data&&lis==NULL){
            lis=(struct nodo*)malloc(sizeof(struct nodo));
            lis->data=head->next->next->data;
            lis->next=NULL;
            tail=lis;
        }
        else if(head->data+head->next->data==head->next->next->data&&lis!=NULL){
            tmp=(struct nodo*)malloc(sizeof(struct nodo));
            tmp->data=head->next->next->data;
            tmp->next=NULL;
            tail->next=tmp;
            tail=tmp;
        }
        head=head->next;
    }
    return lis;
}

struct nodo* new_list(struct nodo* lis1, struct nodo* lis2, int n, int m){
    struct nodo* head=NULL;
    struct nodo* tail=NULL;
    struct nodo* tmp=NULL;

    for(int i=1; lis1!=NULL||lis2!=NULL; i++){
        if(i<=n){
            if(head==NULL){
                head=(struct nodo*)malloc(sizeof(struct nodo));
                head->data=lis1->data;
                head->next=NULL;
                tail=head;
            }else{
                tmp=(struct nodo*)malloc(sizeof(struct nodo));
                tmp->data=lis1->data;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tmp;
            }
            lis1=lis1->next;
            lis2=lis2->next;
        }
        if(i>n&&i<m){
            if(lis1==NULL&&lis2!=NULL){
                printf("QUI\n");
                tmp=(struct nodo*)malloc(sizeof(struct nodo));
                tmp->data=lis2->data;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tmp;
                lis2=lis2->next;
            }
            else if(lis1!=NULL&&lis2==NULL){
                tmp=(struct nodo*)malloc(sizeof(struct nodo));
                tmp->data=lis1->data;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tmp;
                lis1=lis1->next;
            }else{
                tmp=(struct nodo*)malloc(sizeof(struct nodo));
                tmp->data=lis1->data+lis2->data;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tmp;
                lis1=lis1->next;
                lis2=lis2->next;
            }
        }
        if(i>=m){
            tmp=(struct nodo*)malloc(sizeof(struct nodo));
            tmp->data=lis2->data;
            tmp->next=NULL;
            tail->next=tmp;
            tail=tmp;
            lis2=lis2->next;
        }
    }
    return head;
}