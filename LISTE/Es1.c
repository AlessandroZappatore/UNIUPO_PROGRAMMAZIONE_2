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

float media(Nodo *head)
{
    float media = 0;
    int i = 0;
    for (;head != NULL; head=head->next)
    {
        media += head->num;
        i++;
    }
    media = (float)media / i;
    return media;
}

void print_file(Nodo *head, char nome_file[])
{
    FILE *fp = fopen(nome_file, "w");

    if (fp != NULL)
    {
        while (head != NULL)
        {
            fprintf(fp, "%d\n", head->num);
            head = head->next;
        }
        printf("Copia avvenuta con successo\n");
        fclose(fp);
    }
    else
        printf("ERRORE\n");
}

int main(int argc, char **argv)
{
    if(argc==2){
    Nodo *headlist = NULL;
    int n;
    n=atoi(argv[1]);
    buildlist(&headlist, n);
    print_list(headlist);
    float med;
    med = media(headlist);
    printf("La media vale: %.2f\n", med);

    char nome_file[64];
    printf("Inserire il nome del file su cui scrivere i nodi: ");
    scanf("%s", nome_file);
    print_file(headlist, nome_file);
    }
    else{
        printf("Numero di parametri errato\n");
    }
}