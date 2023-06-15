#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[]);
void print_list(struct nodo* head);
void delete_mul(struct nodo** lis1, struct nodo* lis2, int n);

int main(){
    int v1[]={4,5,11,3,4,8,7,-1};
    struct nodo* headlist1=build_list(v1);
    printf("L1: ");
    print_list(headlist1);
    int v2[]={5,1,5,1,5,-1};
    struct nodo* headlist2=build_list(v2);
    printf("L2: ");
    print_list(headlist2);

    delete_mul(&headlist1, headlist2, 2);
    printf("L3: ");
    print_list(headlist1);
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

void delete_mul(struct nodo** lis1, struct nodo* lis2, int n) {
    if (*lis1 == NULL) {
        return;
    }
    
    struct nodo* current1 = *lis1;
    struct nodo* prev = NULL;
    
    while (current1 != NULL) {
        int sum;
        if (lis2 != NULL) {
            sum = current1->data + lis2->data;
            lis2 = lis2->next;
        } else {
            sum = current1->data;
        }
        
        if (sum % n == 0) {
            if (prev == NULL) {
                *lis1 = current1->next;
                } else {
                prev->next = current1->next;
            }
            struct nodo* temp = current1;
            current1 = current1->next;
            free(temp);
        } else {
            prev = current1;
            current1 = current1->next;
        }
    }
}
