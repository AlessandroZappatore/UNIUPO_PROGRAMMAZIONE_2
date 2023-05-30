#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

struct nodo* lista_leggi_file(FILE* fp);
void lista_visualizza (struct nodo* head);
void lista_divisibili(struct nodo* head, int x);

int main(int argc, char **argv){
    if(argc==3){
        FILE* fp=fopen(argv[1], "r");
        if(fp!=NULL){
            struct nodo* headlist=lista_leggi_file(fp);
            fclose(fp);
            printf("Lista creata: ");
            lista_visualizza(headlist);

            lista_divisibili(headlist, atoi(argv[2]));
            lista_visualizza(headlist);
        }
        else{
            printf("File inesistente\n");
            return 2;
        }
    }
    else{
        printf("Numero di parametri errato\n");
        return 1;
    }

    return 0;
}

struct nodo* lista_leggi_file(FILE* fp){
    int n, temp;
    struct nodo* head=NULL;
    struct nodo* tail=NULL;
    struct nodo* tmp=NULL;
    for(n=0; !feof(fp); n++){
        if(n==0){
            head=(struct nodo*) malloc(sizeof(struct nodo));
            fscanf(fp, "%d", &temp);
            tail=head;
            head->data=temp;
            head->next=NULL;
        }
        else{
            tmp=(struct nodo*) malloc(sizeof(struct nodo));
            fscanf(fp, "%d", &temp);
            tail->next=tmp;
            tail=tmp;
            tail->data=temp;
            tail->next=NULL;
        }
    }
    return head;
    
}

void lista_visualizza (struct nodo* head){
    if(head==NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    lista_visualizza(head->next);
}

void lista_divisibili(struct nodo* head, int x){
    struct nodo* curr = head->next;
    struct nodo* next = curr->next;
    while(head->next!=NULL){
        if(head->next->data==x){
            curr = head->next;
            next = curr->next;
            free(curr);
            head->next=next;
        }
        else
            head=head->next;
    }
}

