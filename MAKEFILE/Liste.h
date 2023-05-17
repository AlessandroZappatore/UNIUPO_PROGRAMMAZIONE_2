#ifndef _LISTS_H
#define _LISTS_H

typedef struct nodo {
    int data;
    struct nodo *next;
} Nodo;

void tailinsert(Nodo *head, int x);
Nodo *lista_crea(int n);
int conta_lista(Nodo *head);
Nodo *inverti_lista(Nodo *head, Nodo *next);
Nodo *elimina_nodo(Nodo *head, int x);
void visualizza_lista(Nodo *head);
void tailinsert(struct nodo *head, int x);
void node_insert(Nodo *head, int x, int p, int i);
void print_kesimo(Nodo *head, int k, int p);
int palindroma(Nodo *head, Nodo *inv);
int prodotto(Nodo* head);
Nodo *elimina_dispari(Nodo *head);
Nodo *nuova_lista(Nodo *head, Nodo *newhead, int x);
Nodo* newnode(void);
Nodo* cancella_k_rc(Nodo* head, int k, int p);
//void delx(Nodo **head, int x);

#endif