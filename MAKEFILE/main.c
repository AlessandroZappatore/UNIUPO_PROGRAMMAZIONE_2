#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Liste.h"
int main()
{
    int n;

    printf("Inserire il numero di nodi: ");
    scanf("%d", &n);

    Nodo *headlist = NULL;
    srand(time(NULL));

    headlist = lista_crea(n);
    visualizza_lista(headlist);

    //int l = conta_lista(headlist); ESERCIZIO 1
    //printf("La lunghezza della lista vale: %d\n", l);

    //int x; ESERCIZIO 3
    //printf("Inserire il valore del nodo da eliminare: ");
    //scanf("%d", &x);
    //headlist = elimina_nodo(headlist, x);
    //visualizza_lista(headlist);

    //Nodo *headlist_inv; ESERCIZIO 2
    //headlist_inv = inverti_lista(headlist, NULL);
    //visualizza_lista(headlist_inv);

    /*int x, p;  ESERCIZIO 4
    printf("Inserire il valore da inserire: ");
    scanf("%d", &x);
    printf("Inserire la posizione: ");
    scanf("%d", &p);
    node_insert(headlist, x, p, 0);
    visualizza_lista(headlist);

    int k; ESERCIZIO 6
    printf("Inserire la posizione da trovare: ");
    scanf("%d", &k);
    print_kesimo(headlist, k, 0);*/

    /*Nodo *headlist_inv; ESERCIZIO 5
    headlist_inv = inverti_lista(headlist, NULL);
    visualizza_lista(headlist_inv);
    int c=palindroma(headlist, headlist_inv);
    if(c==0) 
        printf("Lista non palindroma\n");
    else
        printf("La lista e' palindroma\n");*/


    /*int p; ESERCIZIO 8
    p=prodotto(headlist);
    printf("Il prodotto vale: %d\n", p);*/

    /*headlist=elimina_dispari(headlist); ESERCIZIO 9
    visualizza_lista(headlist);*/

    /*Nodo *new_headlist=NULL; //ESERCIZIO 7
    int x;
    printf("Inserire la condizione: ");
    scanf("%d", &x);
    new_headlist=nuova_lista(headlist, new_headlist, x);
    visualizza_lista(new_headlist);*/

    /*int k;
    printf("Inserire il valore da cancellare: ");
    scanf("%d", &k);
    headlist=cancella_k_rc(headlist, k, 0);
    visualizza_lista(headlist);*/
    int x;
    printf("Inserire x: ");
    scanf("%d", &x);
    delx(&headlist, x);
    visualizza_lista(headlist);
    return 0;
}




