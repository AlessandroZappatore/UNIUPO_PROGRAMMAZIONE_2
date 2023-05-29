#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo* next;
};

void delete_node(struct nodo* head, int pos){
    for(int i=0; i<pos-1; i++){
        head=head->next;
        if(head==NULL){
            fprintf(stderr, "List too short!\n");
        }
    }
    
    struct nodo* curr = head->next;
    struct nodo* next = curr->next;
    free(curr);
    head->next=next;
}

void headisert (struct nodo** head, int x){
    struct nodo* new_node = (struct nodo*) malloc(sizeof(struct nodo));
    if(new_node==NULL){
        fpritnf(stderr, "Could not allocate memory!");
        return;
    }

    new_node->data=x;
    new_node->next=*head;
    *head=new_node;
}

void tailinsert(struct nodo* head, int x){
    struct nodo* new_node = (struct nodo*) malloc(sizeof(struct nodo));
    if(new_node==NULL){
        fpritnf(stderr, "Could not allocate memory!");
        return;
    }
    new_node->data=x;
    new_node->next=NULL;

    while(head->next!=NULL)
        head=head->next;
    
    head->next=new_node;
}

struct nodo* buildlist(int n) {
    struct nodo *head = (struct nodo*)malloc(sizeof(struct nodo));
    head->data = rand() % 51;

    struct nodo *tail = head;

    for (int i = 0; i < n-1; i++) {
        struct nodo *temp = malloc(sizeof(struct nodo));
        temp->data = rand() % 51;

        tail->next = temp;
        tail = temp;
    }

    tail->next = NULL;

    return head;
}

void list_print(struct nodo *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int lista_leggi_file(FILE* fp, struct nodo** headlist){
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
    *headlist=head;
    return n;
}

void print_list_rc(struct nodo* head){
    if(head==NULL){
        printf("NULL\n");
        return;
    }
    
    printf("%d -> ", head->data);
    print_list(head->next);    
}