#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int num;
    struct nodo *next;
};

int lista_leggi_file(FILE* fp, struct nodo** head);
void print_list(struct nodo* head);
struct nodo* lista_dividi(struct nodo* head, int pos_neg);
void lista_scrivi_file(struct nodo* head, FILE* fp);

int main(int argc,char* argv[]){
    if(argc==2){
        FILE* fp=fopen(argv[1], "r");
        if(fp!=NULL){
            struct nodo* headlist;
            int n=lista_leggi_file(fp, &headlist);
            print_list(headlist);
            printf("Numero di nodi presenti: %d\n", n);
            fclose(fp);

            struct nodo* positivi=lista_dividi(headlist, 1);
            struct nodo* negativi=lista_dividi(headlist, 0);
            printf("Lista positivi: ");
            print_list(positivi);
            printf("Lista negativi: ");
            print_list(negativi);

            FILE* fp1=fopen("lista1.txt", "w");
            lista_scrivi_file(positivi, fp1);
            fclose(fp1);

            FILE* fp2=fopen("lista2.txt", "w");
            lista_scrivi_file(negativi, fp2);
            fclose(fp2);
        }
        else
        {
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
            head->num=temp;
            head->next=NULL;
        }
        else{
            tmp=(struct nodo*) malloc(sizeof(struct nodo));
            fscanf(fp, "%d", &temp);
            tail->next=tmp;
            tail=tmp;
            tail->num=temp;
            tail->next=NULL;
        }
    }
    *headlist=head;
    return n;
}

void print_list(struct nodo* head){
    if(head==NULL){
        printf("NULL\n");
        return;
    }
    
    printf("%d -> ", head->num);
    print_list(head->next);    
}

struct nodo* lista_dividi(struct nodo* headlist, int pos_neg){
    struct nodo* head=NULL;
    struct nodo* tmp=NULL;
    
    if(pos_neg){
    for(int i=0; headlist!=NULL; i++){
        if(i==0){
            if(headlist->num>0){
                head=(struct nodo*) malloc(sizeof(struct nodo));
                head->num=headlist->num;
                head->next=NULL;

                headlist=headlist->next;
            }
            else{
                headlist=headlist->next;
            }
        }
        else{
            if(headlist->num>0){
                tmp=(struct nodo*) malloc(sizeof(struct nodo));
                tmp->num=headlist->num;
                tmp->next=head;
                head=tmp;

                headlist=headlist->next;
            }
            else{
                headlist=headlist->next;
             }        
            }
      }
    }
    else{
    for(int i=0; headlist!=NULL; i++){
        if(i==0){
            if(headlist->num<0){
                head=(struct nodo*) malloc(sizeof(struct nodo));
                head->num=headlist->num;
                head->num=headlist->num;
                head->next=NULL;

                headlist=headlist->next;
            }
            else{
                headlist=headlist->next;
            }
        }
        else{
            if(headlist->num<0){
                tmp=(struct nodo*) malloc(sizeof(struct nodo));
                tmp->num=headlist->num;
                tmp->next=head;
                head=tmp;

                headlist=headlist->next;
            }
            else{
                headlist=headlist->next;
             }        
            }
      }
}
    return head;
}   

void lista_scrivi_file(struct nodo* head, FILE* fp){
    while(head!=NULL){
        fprintf(fp, "%d\n", head->num);
        head=head->next;
    }
}