/*Scrivere un programma che legga da
tastiera i campi di una struct di tipo impiegato e salvi i dati
su un file di testo .tsv (in modalità append). Successive
invocazioni dovranno salvare in coda i nuovi dati*/
#include <stdio.h>
typedef struct
{
char nome[64];
char cognome[64];
unsigned int eta;
char sesso;
double stipendio;
} Impiegato;

int main(){

    Impiegato impiegato1;
    FILE* fp = fopen("file.tsv", "a");
     printf("Inserire il nome: ");
     scanf("%s", impiegato1.nome);
     printf("Inserire il cognome: ");
     scanf("%s", impiegato1.cognome);
     printf("Inserire l'eta: ");
     scanf("%d", &impiegato1.eta);
     printf("Inserire il sesso: ");
     scanf(" %c", &impiegato1.sesso);
     printf("Inserire lo stipendio: ");
     scanf("%d", &impiegato1.stipendio);

    fprintf(fp, "%s\t%s\t%d\t%c\t%d\n", impiegato1.nome, impiegato1.cognome, impiegato1.eta, impiegato1.sesso, impiegato1.stipendio);

    fclose(fp);
    return 0;
}