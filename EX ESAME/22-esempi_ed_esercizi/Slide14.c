#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int data;
    struct nodo *next;
};

struct nodo *build_list(int v[]);
void print_list(struct nodo *head);
int confronto(struct nodo *lis1, struct nodo *lis2, int n, int i);

int main()
{
    int v1[] = {2, 2, 5, 6, 7, 9, -1};
    struct nodo *headlist1 = build_list(v1);
    print_list(headlist1);
    int v2[] = {2, 51, 16, 6, 7, 9, -1};
    struct nodo *headlist2 = build_list(v2);
    print_list(headlist2);

    int c = confronto(headlist1, headlist2, 3, 0);
    if (c)
        printf("Liste uguali\n");
    else
        printf("Liste diverse\n");

    return 0;
}

struct nodo *build_list(int v[])
{
    struct nodo *head = NULL;
    struct nodo *tail = NULL;
    struct nodo *tmp = NULL;

    head = (struct nodo *)malloc(sizeof(struct nodo));
    head->data = v[0];
    head->next = NULL;
    tail = head;

    for (int i = 1; v[i] != -1; i++)
    {
        tmp = (struct nodo *)malloc(sizeof(struct nodo));
        tmp->data = v[i];
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
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

int confronto(struct nodo *lis1, struct nodo *lis2, int n, int i)
{
    if (lis1 == NULL && lis2 == NULL)
        return 1;
    if (lis1 == NULL && lis2 != NULL)
        return 0;
    if (lis1 != NULL && lis2 == NULL)
        return 0;

    if (i >= n)
    {
        if (lis1->data != lis2->data)
            return 0;
        else
            return confronto(lis1->next, lis2->next, n, i + 1);
    }
    else
        return confronto(lis1->next, lis2->next, n, i + 1);
}