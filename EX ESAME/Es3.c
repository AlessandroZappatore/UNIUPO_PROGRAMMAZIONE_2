/*Scrivere una funzione buildlist per generare una lista di N elementi con valori
random compresi tra 0 e 100 (2pt)
● Generare due liste di dimensione uguale e scrivere una funzione iterativa
dot_prod per calcolare il prodotto scalare (somma dei prodotti degli elementi)
(2pt)
● Scrivere una funzione iterativa list_duplicate che restituisca una nuova lista
contenente i valori che appaiono più di una volta (4pt)
*/
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int data;
    struct nodo *next;
};

struct nodo *buidlist(int n)
{
    struct nodo *head;
    struct nodo *temp;

    head = (struct nodo *)malloc(sizeof(struct nodo));
    head->data = rand() % 20;
    head->next = NULL;
    int i = 0;
    while (i < n - 1)
    {
        temp = (struct nodo *)malloc(sizeof(struct nodo));
        temp->data = rand() % 20;
        temp->next = head;
        head = temp;
        i++;
    }
    return head;
}

void print_list(struct nodo *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int trovato(struct nodo *head, int x)
{
    while (head != NULL)
    {
        if (head->data == x)
            return 1;
        else
            head = head->next;
    }
    return 0;
}
struct nodo *list_duplicate(struct nodo *head)
{
    struct nodo *head2=NULL;
    struct nodo *temp=NULL;

    
    head=head->next;
    while (head->next != NULL)
    {
        if(head2==NULL){
            if (trovato(head->next, head->data))
        {
            head2 = (struct nodo*)malloc(sizeof(struct nodo));
            head2->data = head->data;
            head2->next = NULL;
        }
        }
        if (trovato(head->next, head->data))
        {
            if(!trovato(head2, head->data)){
            temp = (struct nodo*)malloc(sizeof(struct nodo));
            temp->data = head->data;
            temp->next = head2;
            head2 = temp;
            }
        }
        head=head->next;
    }
    return head2;
}

int dot_prod(struct nodo *head1, struct nodo *head2)
{
    int prod = 0;

    while (head1 != NULL)
    {
        prod += head1->data * head2->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return prod;
}

int main()
{
    struct nodo *headlist1 = buidlist(40);
    struct nodo *headlist2 = buidlist(40);

    print_list(headlist1);
    //print_list(headlist2);

    int prod;
    printf("Il prodotto vettoriale vale: %d\n", dot_prod(headlist1, headlist2));

    struct nodo* headdup=list_duplicate(headlist1);
    print_list(headdup);
    return 0;
}