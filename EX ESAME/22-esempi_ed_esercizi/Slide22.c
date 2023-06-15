#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list_rc(int v[], int i);
void print_list(struct nodo* head);
int max_max(struct nodo* head, int max);
void find_max(struct nodo* head, int *max);
int crescente(struct nodo* head);

int main(){
    int v[]={4,4,23,8,6,23,86,86,23,87,-1};
    struct nodo* headlist=build_list_rc(v, 0);
    print_list(headlist);

    int max=0;
    find_max(headlist, &max);
    printf("Il numero di volte in cui e' stato trovato il valore massimo e': %d\n", max_max(headlist, max));

    int v2[]={1,2,2,4,-1};
    struct nodo* headlist2=build_list_rc(v2, 0);
    print_list(headlist2);
    if(crescente(headlist2))
        printf("Lista in ordine\n");
    else
        printf("Lista non in ordine\n");
    return 0;
}

struct nodo* build_list_rc(int v[], int i){
    if(v[i]==-1)
        return NULL;
    
    struct nodo* head=(struct nodo*)malloc(sizeof(struct nodo));
    head->data=v[i];
    head->next=build_list_rc(v, i+1);
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

int max_max(struct nodo* head, int max){
    if(head==NULL)
        return 0;
    
    if(head->data==max)
        return 1+max_max(head->next, max);
    else
        return max_max(head->next, max);
}

void find_max(struct nodo* head, int *max){
    if(head==NULL)
        return;

    if(head->data>(*max)){
        (*max)=head->data;
    }
    find_max(head->next, max);
}

int crescente(struct nodo* head){
    if(head->next==NULL)
        return 1;
    if(head->data>=head->next->data)
        return 0;

    return crescente(head->next);
}