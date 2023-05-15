#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int DATA;
struct linked_list
{
    DATA d;
    struct linked_list *next;
};
typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;

LINK newnode(void)
{
    return malloc(sizeof(ELEMENT));
}

void delfirsts_rt(int x, LINK *lis)
{
    LINK p;
    if ((*lis) != NULL)
    {
        if ((*lis)->d == x)
        {
            p = *lis;
            *lis = (*lis)->next;
            delfirsts_rt(x, lis);
            free(p);
        }
        else
            delfirsts_rt(x, &((*lis)->next));
    }
}

LINK lista_crea(int n)
{
    LINK head;

    if (n == 0)
        return NULL;

    head = (LINK)malloc(sizeof(LINK));
    if (head == NULL)
        return NULL;
    else
    {
        int num = rand() % 10;
        head->d = num;
        head->next = lista_crea(n - 1);
    }
    return head;
}

void visualizza_lista(LINK head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return;
    }
    else
    {
        printf("(%d)->", head->d);
        visualizza_lista(head->next);
    }
}

void buildsumlis_long_rt(LINK l1, LINK l2, LINK *head, LINK *tail)
{
    /* *head, *tail inizializzati a NULL */
    LINK p;
    /* if ((l1==NULL)&&(l2==NULL)) ; nel caso di ricorsione di coda, il caso base
    non fa nulla, e puo’ essere quindi omesso */
    if ((l1 == NULL) && (l2 != NULL))
    {
        p = newnode();
        p->d = l2->d;
        p->next = NULL;
        if ((*head) == NULL)
        {
            (*head) = p;
            (*tail) = p;
        }
        else
        {
            (*tail)->next = p;
            (*tail) = p;
        }
        buildsumlis_long_rt(l1, l2->next, head, tail);
    }
    else if ((l1 != NULL) && (l2 == NULL))
    {
        p = newnode();
        p->d = l1->d;
        p->next = NULL;
        if ((*head) == NULL)
        {
            (*head) = p;
            (*tail) = p;
        }
        else
        {
            (*tail)->next = p;
            (*tail) = p;
        }
        buildsumlis_long_rt(l1->next, l2, head, tail);
    }
    else if ((l1 != NULL) && (l2 != NULL))
    {
        p = newnode();
        p->d = l1->d + l2->d;
        p->next = NULL;
        if ((*head) == NULL)
        {
            (*head) = p;
            (*tail) = p;
        }
        else
        {
            (*tail)->next = p;
            (*tail) = p;
        }
        buildsumlis_long_rt(l1->next, l2->next, head, tail);
    }
}

int main()
{
    srand(time(NULL));
    int x;
    LINK list = NULL, list2 = NULL;
    list = lista_crea(10);
    list2 = lista_crea(15);
    visualizza_lista(list);
    visualizza_lista(list2);
    LINK list_sum = NULL;
    LINK tail=NULL;
    buildsumlis_long_rt(list, list2, &list_sum, &tail);
    visualizza_lista(list_sum);
}