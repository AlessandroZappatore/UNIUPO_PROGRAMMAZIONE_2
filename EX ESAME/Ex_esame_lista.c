// Leggere un file contenente nomi di persone (dati.txt)
// Salvare i nomi in una lista
// Visualizzare la lista (ricorsivamente)
// Per ogni nodo (quindi per ogni stringa), contare le vocali
// Andrea: 3 -> Maria: 3 -> Gianna: 3 -> Susanna: 3 -> ...
// Scrivere una funzione specifica che ritorna il numero di vocali di una stringa

// ESERCIZIO
// Chiedere in input nel main una lettere
// Es. M
// Cancellare dalla lista tutti i nodi che hanno una stringa che inizia per la lettera letta in input
// Visualizzare la lista
// Andrea -> Gianna -> Susanna
// Scrivere la lista aggiornata sul file dati_aggiornati.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
    char *nome;
    struct nodo* next;
};

int main(){

    return 0;
}