#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[64];
    char cognome[64];
    unsigned int eta;
    char sesso;
    double salario;
} Impiegato;

void stampa(Impiegato *Imp, int n){
    printf("\n\n");
    for(int j=0; j<n; j++){
        printf("Persona %d: \n", j);
        printf("Nome: %s\tCognome:  %s\tEta': %d\tSesso: %c\tSalario: %.2lf\n", Imp[j].nome, Imp[j].cognome, Imp[j].eta, Imp[j].sesso, Imp[j].salario);
    }
}

int leggi_impiegato(Impiegato *Imp, int i){

    printf("Inserire il nome: ");
     scanf("%s", Imp[i].nome);
     printf("Inserire il cognome: ");
     scanf("%s", Imp[i].cognome);
     printf("Inserire l'eta: ");
     scanf("%d", &Imp[i].eta);
     printf("Inserire il sesso: ");
     scanf(" %c", &Imp[i].sesso);
     printf("Inserire lo stipendio: ");
     scanf("%lf", &Imp[i].salario);
    i++;
   return i;
}

void ricerca(Impiegato *Imp, char persona[],  int n){
int trovato=0;
    for(int i=0; i<n; i++){
        if(!strcmp(Imp[i].cognome, persona)){
            printf("Persona trovata\nNome: %s\tCognome:  %s\tEta': %d\tSesso: %c\tSalario: %.2lf\n", Imp[i].nome, Imp[i].cognome, Imp[i].eta, Imp[i].sesso, Imp[i].salario);
            trovato=1;
        }
    }
    if(trovato==0)
        printf("Persona non trovata\n");
}

void modifica(Impiegato *Imp, char persona[], int n){
    int trovato=0;
    for(int i=0; i<n; i++){
        if(!strcmp(Imp[i].cognome, persona)){
            printf("Inserire il nome: ");
            scanf("%s", Imp[i].nome);
            printf("Inserire il cognome: ");
            scanf("%s", Imp[i].cognome);
            printf("Inserire l'eta: ");
            scanf("%d", &Imp[i].eta);
            printf("Inserire il sesso: ");
            scanf(" %c", &Imp[i].sesso);
            printf("Inserire lo stipendio: ");
            scanf("%lf", &Imp[i].salario);
            trovato=1;
        }
    }
    if(trovato==0)
        printf("Persona non trovata\n");
}

void salva_file(Impiegato *Imp, char nome_file[], int n){
    FILE* fp = fopen(nome_file, "w");

    for(int i=0; i<n; i++){
        fprintf(fp, "%s\t%s\t%d\t%c\t%.2lf\n", Imp[i].nome, Imp[i].cognome, Imp[i].eta, Imp[i].sesso, Imp[i].salario);
    }
    fclose(fp);
}

int carica_file(Impiegato *Imp, char nome_file[]){
    int impiegato=0;
    FILE* fp = fopen(nome_file, "r");

    if(fp!=NULL){
        for(int i=0; fscanf(fp, "%s %s %d %c %lf", Imp[i].nome, Imp[i].cognome, &Imp[i].eta, &Imp[i].sesso, &Imp[i].salario)!=EOF&&i<50; i++)
            impiegato++;
    }
    else
        printf("File inesistente\n");
    return impiegato;
}



int main() {
    Impiegato impiegati[50];
    int num_impiegati = 0;

    int choice = 0;
    do {
        printf("\n---- Scegli un'operazione:\n");
        printf("0 - Visualizza tutti i record\n");
        printf("1 - Inserisci un nuovo impiegato\n");
        printf("2 - Ricerca impiegaro\n");
        printf("3 - Modifica di un impiegato\n");
        printf("4 - salvare su file\n");
        printf("5 - Caricare da file\n");
        printf("9 - Esci\n");

        printf("Scelta: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0: 
                stampa(impiegati, num_impiegati);
                break;

            case 1: 
                num_impiegati=leggi_impiegato(impiegati, num_impiegati);
                break;

            case 2:
                char persona[64];
                printf("Inserire il cognome della persona da cercare: ");
                scanf("%s", persona);
                ricerca(impiegati, persona, num_impiegati);
            break;

            case 3:
                
                printf("Inserire il cognome della persona da cercare: ");
                scanf("%s", persona);
                modifica(impiegati, persona, num_impiegati);
                break;
            
            case 4:
                char nome_file[100];
                printf("Inserire il nome del file su cui salvare i dati: ");
                scanf("%s", nome_file);
                salva_file(impiegati, nome_file, num_impiegati);
                break;

            case 5:
                 printf("Inserire il nome del file da cui prelevare i dati: ");
                scanf("%s", nome_file);
                num_impiegati=carica_file(impiegati, nome_file);
                break;
            
            default:
                break;
        }

    } while (choice != 9);

    return 0;
}
