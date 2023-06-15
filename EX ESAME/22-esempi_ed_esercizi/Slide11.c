#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* build_list(int v[]);
void print_list(struct nodo* head);
void delete(struct nodo** head, int n, int m);

int main(){
    int v[]={1,1,2,1,7,1,2,-1};
    struct nodo* headlist=build_list(v);
    print_list(headlist);

    delete(&headlist, 3, 5);
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

void delete(struct nodo** head, int n, int m){
    int pos=1;
    struct nodo* p;
    struct nodo* q;
    if(n==1){
        while((*head)!=NULL && pos<m){
            p=(*head);
            (*head)=(*head)->next;
            free(p);
            pos++;
        }
    } else{
        p=(*head);
        while((pos<(n-1))&&p!=NULL){
            pos++;
            p=p->next;
        }
        if(p!=NULL){
            while(pos<m&&p->next!=NULL){
                q=p->next;
                p->next=q->next;
                free(q);
                pos++;
            }
        }
    }
}
