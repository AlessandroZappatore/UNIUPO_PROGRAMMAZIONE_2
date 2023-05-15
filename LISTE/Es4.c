#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int num;
    struct node *next;
};

typedef struct node Nodo;

void buildlist(Nodo **headlist, int n)
{
    srand(time(NULL));
    Nodo *head = NULL;
    Nodo *tail = NULL;
    Nodo *tmp = NULL;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = malloc(sizeof(Nodo));
            if (head != NULL)
            {
                tail = head;
                head->num = rand() % 51;
                head->next = NULL;
            }
            else
            {
                printf("Impossibile creare il nodo testa\n");
                head = NULL;
            }
        }
        else
        {
            tmp = malloc(sizeof(Nodo));
            if (tmp != NULL)
            {
                tail->next = tmp;
                tail = tmp;
                tail->num = rand() % 51;
                tail->next = NULL;
            }
            else
            {
                printf("Impossibile creare il nodo temp\n");
                head = NULL;
            }
        }
    }
    *headlist = head;
}

void tailinsert(Nodo* head, int x){
    Nodo *new_node = (Nodo*)malloc(sizeof(Nodo));
    if(new_node == NULL){
        fprintf(stderr, "ERRORE\n");
        return;
    }
    new_node->num = x;
    new_node->next = NULL;

    while(head->next!=NULL)
        head= head->next;

    head->next = new_node;
}

void print_list(Nodo *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->num);
        head = head->next;
    }
    printf("NULL");
    printf("\n");
}


int main(int argc, char **argv)
{
    if(argc==2){
    Nodo *headlist = NULL;
    int n;
    n=atoi(argv[1]);
    buildlist(&headlist, n);
    print_list(headlist);

    Nodo *headlist2 = malloc(sizeof(Nodo));
    Nodo *headlist3 = malloc(sizeof(Nodo));

    Nodo *temp = headlist;
    int i, j;

    for(i=0, j=0; temp!=NULL;){
        if(temp->num%2==0){
        if(i==0)
            headlist2->num=temp->num;
        else
            tailinsert(headlist2, temp->num);
        i++;
        }
        else{ 
            if(j==0)
                headlist3->num=temp->num;
            else
                tailinsert(headlist3, temp->num);
            j++;
        }
    temp = temp->next;
    }

    print_list(headlist2);
    print_list(headlist3);

    }
    else{
        printf("Numero di parametri errato\n");
    }
}