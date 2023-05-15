#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *create_array(size_t size, int n);
void *expand_array(void *arr, size_t size, int n);
void delete_array(void *arr);
int leggi_impiegato(Impiegato *Imp, int i);
void modifica(Impiegato *Imp, char persona[], int n);
void salva_file(Impiegato *Imp, char nome_file[], int n);
int carica_file_rc(Impiegato *Imp, FILE *fp, int n);
void stampa_ricorsiva(Impiegato *Imp, int n);
int ricerca_ricorsiva(Impiegato *Imp, char persona[], int n);
int stipendio_alto_rc(Impiegato *Imp, int n, int max, int c);


void *create_array(size_t size, int n)
{
    void *buf = malloc(size * n);
    if (buf == NULL)
    {
        fprintf(stderr, "Could not allocate memory!\n");
        return NULL;
    }

    return buf;
}

void *expand_array(void *arr, size_t size, int n)
{
    arr = realloc(arr, size * n);
    if (arr == NULL)
    {
        fprintf(stderr, "Could not expand memory\n");
        return NULL;
    }

    return arr;
}

void delete_array(void *arr)
{
    free(arr);
}

typedef struct
{
    char nome[64];
    char cognome[64];
    unsigned int eta;
    char sesso;
    double salario;
} Impiegato;

int leggi_impiegato(Impiegato *Imp, int i)
{
    printf("Inserire il nome: ");
    scanf("%s", Imp[i].nome);
    printf("Inserire il cognome: ");
    scanf("%s", Imp[i].cognome);
    printf("Inserire l'eta: ");
    scanf("%u", &Imp[i].eta);
    printf("Inserire il sesso: ");
    scanf(" %c", &Imp[i].sesso);
    printf("Inserire lo stipendio: ");
    scanf("%lf", &Imp[i].salario);

    i++;
    return i;
}

void modifica(Impiegato *Imp, char persona[], int n)
{
    int trovato = 0;
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(Imp[i].cognome, persona))
        {
            printf("Inserire il nome: ");
            scanf("%s", Imp[i].nome);
            printf("Inserire il cognome: ");
            scanf("%s", Imp[i].cognome);
            printf("Inserire l'eta: ");
            scanf("%u", &Imp[i].eta);
            printf("Inserire il sesso: ");
            scanf(" %c", &Imp[i].sesso);
            printf("Inserire lo stipendio: ");
            scanf("%lf", &Imp[i].salario);
            trovato = 1;
        }
    }
    if (trovato == 0)
        printf("Persona non trovata\n");
}

void salva_file(Impiegato *Imp, char nome_file[], int n)
{
    FILE *fp = fopen(nome_file, "w");

    if (fp != NULL)
    {
        fprintf(fp, "%d\n", n);
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%s\t%s\t%d\t%c\t%.2lf\n", Imp[i].nome, Imp[i].cognome, Imp[i].eta, Imp[i].sesso, Imp[i].salario);
        }
        fclose(fp);
        printf("Salvataggio avvenuto con successo\n");
    }
    else
        printf("ERRORE durante il salvataggio\n");
}

int carica_file_rc(Impiegato *Imp, FILE *fp, int n)
{
    if (fscanf(fp, "%s %s %u %c %lf", Imp[n].nome, Imp[n].cognome, &Imp[n].eta, &Imp[n].sesso, &Imp[n].salario) == EOF)
        return n;

    return carica_file_rc(Imp, fp, n + 1);
    fscanf(fp, "%s %s %u %c %lf", Imp[n].nome, Imp[n].cognome, &Imp[n].eta, &Imp[n].sesso, &Imp[n].salario);
}

void stampa_ricorsiva(Impiegato *Imp, int n)
{
    if (n < 0)
        return;

    stampa_ricorsiva(Imp, n - 1);
    printf("%d) Nome: %s\tCognome:  %s\tEta': %d\tSesso: %c\tSalario: %.2lf\n", n, Imp[n].nome, Imp[n].cognome, Imp[n].eta, Imp[n].sesso, Imp[n].salario);
}

int ricerca_ricorsiva(Impiegato *Imp, char persona[], int n)
{
    if (!strcmp(Imp[n].cognome, persona))
    {
        printf("Persona trovata\nNome: %s\tCognome:  %s\tEta': %d\tSesso: %c\tSalario: %.2lf\n", Imp[n].nome, Imp[n].cognome, Imp[n].eta, Imp[n].sesso, Imp[n].salario);
        return 1;
    }
    else if (n <= 0)
        return 0;

    else
        return ricerca_ricorsiva(Imp, persona, n - 1);
}

int stipendio_alto_rc(Impiegato *Imp, int n, int max, int c)
{
    if (n == 0)
        return c;

    if (Imp[n].salario > max)
    {
        max = Imp[n].salario;
        c = n;
    }
    return stipendio_alto_rc(Imp, n - 1, max, c);
}

int main()
{
    Impiegato *impiegati;
    int num_impiegati = 0;
    char persona[64], nome_file[100];

    int choice = 0, trovato, max = 0, c = 0, i;
    do
    {
        printf("\n---- Scegli un'operazione:\n");
        printf("0 - Visualizza tutti i record\n");
        printf("1 - Inserisci un nuovo impiegato\n");
        printf("2 - Ricerca impiegaro\n");
        printf("3 - Modifica di un impiegato\n");
        printf("4 - salvare su file\n");
        printf("5 - Caricare da file\n");
        printf("6 - Stampa del dipendente con lo stipendio piu' alto\n");
        printf("9 - Esci\n");

        printf("Scelta: ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice)
        {
        case 0:
            stampa_ricorsiva(impiegati, num_impiegati - 1);
            break;

        case 1:
            if (num_impiegati == 0)
                impiegati = (Impiegato *)create_array(sizeof(Impiegato), 1);
            else
                expand_array(impiegati, sizeof(Impiegato), (num_impiegati + 1));

            num_impiegati = leggi_impiegato(impiegati, num_impiegati);
            break;

        case 2:

            printf("Inserire il cognome della persona da cercare: ");
            scanf("%s", persona);
            trovato = ricerca_ricorsiva(impiegati, persona, num_impiegati);
            if (!trovato)
                printf("Persona non trovata");
            break;

        case 3:

            printf("Inserire il cognome della persona da modificare: ");
            scanf("%s", persona);
            modifica(impiegati, persona, num_impiegati);
            break;

        case 4:

            printf("Inserire il nome del file su cui salvare i dati: ");
            scanf("%s", nome_file);
            salva_file(impiegati, nome_file, num_impiegati);
            break;

        case 5:
            printf("Inserire il nome del file da cui prelevare i dati: ");
            scanf("%s", nome_file);

            FILE *fp = fopen(nome_file, "r");
            int k;
            if (fp != NULL)
            {
                fscanf(fp, "%d\n", &k); // Numero di dipendenti nella prima riga del file.
                if (num_impiegati == 0)
                    impiegati = (Impiegato *)create_array(sizeof(Impiegato), k);
                else
                    expand_array(impiegati, sizeof(Impiegato), (num_impiegati + k));
                num_impiegati = carica_file_rc(impiegati, fp, num_impiegati);
                fclose(fp);
            }
            else
                printf("File inesistente");
            break;

        case 6:
            i = stipendio_alto_rc(impiegati, num_impiegati, max, c);
            printf("Il dipendente con lo stipendio piu' alto e': %s %s\n", impiegati[i].nome, impiegati[i].cognome);
            break;

        default:
            break;
        }

    } while (choice != 9);

    delete_array(impiegati);
    return 0;
}
