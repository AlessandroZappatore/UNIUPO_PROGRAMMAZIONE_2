#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void tailinsert(Nodo *head, int x)
{
    struct nodo *new_node = (struct nodo *)malloc(sizeof(struct nodo));
    if (new_node == NULL)
    {
        fprintf(stderr, "Could not allocate memory\n!");
        return;
    }
    new_node->data = x;
    new_node->next = NULL;
    while (head->next != NULL)
    {

        head = head->next;
    }
    head->next = new_node;
}
void node_insert(Nodo *head, int x, int p, int i)
{
    if (head == NULL)
        fprintf(stderr, "Node insert error\n");
    if (i == p - 1)
    {
        Nodo *new = head->next;
        Nodo *p = newnode();
        p->data = x;
        p->next = new;
        head->next = p;
    }
    else
        node_insert(head->next, x, p, i + 1);
}

void print_kesimo(Nodo *head, int k, int p)
{
    if (head == NULL)
    {
        return;
    }
    if (p == k)
        printf("Valore in posizione %d: %d\n", k, head->data);

    print_kesimo(head->next, k, p + 1);
}

int palindroma(Nodo *head, Nodo *inv)
{
    if (head == NULL && inv == NULL)
        return 1;

    if (head->data != inv->data)
        return 0;
    else
        return palindroma(head->next, inv->next);
}

int prodotto(Nodo *head)
{
    if (head == NULL)
        return 1;

    return head->data * prodotto(head->next);
}

Nodo *elimina_dispari(Nodo *head)
{
    if (head == NULL)
        return NULL;

    head->next = elimina_dispari(head->next);

    if (head->data % 2 != 0)
    {
        Nodo *head2 = head->next;
        free(head);
        return head2;
    }

    return head;
}

Nodo *nuova_lista(Nodo *head, Nodo *newhead, int x)
{
    if (head == NULL)
        return NULL;

    if (head->data < x)
    {
        newhead = (Nodo *)malloc(sizeof(Nodo));
        newhead->data = head->data;
        newhead->next = nuova_lista(head->next, newhead, x);
        return newhead;
    }
    return nuova_lista(head->next, newhead, x);
}
Nodo *lista_crea(int n)
{
    Nodo *head;

    if (n == 0)
        return NULL;

    head = (Nodo *)malloc(sizeof(Nodo));
    if (head == NULL)
        return NULL;
    else
    {
        int num = rand() % 101;
        head->data = num;
        head->next = lista_crea(n - 1);
    }
    return head;
}

int conta_lista(Nodo *head)
{
    if (head == NULL)
        return 0;

    return 1 + conta_lista(head->next);
}

Nodo *inverti_lista(Nodo *head, Nodo *next)
{
    Nodo *ptrNext = head->next;
    head->next = next;

    if (ptrNext == NULL)
        return head;
    return inverti_lista(ptrNext, head);
}

Nodo *elimina_nodo(Nodo *head, int x)
{
    if (head == NULL)
        return NULL;

    if (head->data == x)
    {
        Nodo *head2 = head->next;
        free(head);
        return head2;
    }

    head->next = elimina_nodo(head->next, x);
    return head;
}

void visualizza_lista(Nodo *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }
    else
    {
        printf("(%d)->", head->data);
        visualizza_lista(head->next);
    }
}

Nodo *newnode(void)
{
    return malloc(sizeof(Nodo));
}

Nodo *cancella_k_rc(Nodo *head, int k, int p)
{
    if (head == NULL)
        return NULL;

    head->next = cancella_k_rc(head->next, k, p + 1);

    if ((p % 2 == 0) && (head->data == k))
    {
        Nodo *new_head = head->next;
        free(head);
        return new_head;
    }
    return head;
}

/*void delx(Nodo **head, int x){
    Nodo* p;
    if(*head!=NULL){
        if((*head)->data==x){
            p=(*head);
            (*head)=(*head)->next;
            free(p);
            delx((*head), x);
        }
        delx((*head)->next, x);
    }
}*/