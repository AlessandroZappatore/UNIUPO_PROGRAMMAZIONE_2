#include <stdio.h>
#define DIM 30

typedef struct{
        char nome[DIM];
        char cognome[DIM];
        unsigned int eta;
    } persona;

int main(){

     persona persona1, persona2;

        printf("Inserire il nome della prima persona: ");
        scanf("%s", persona1.nome);
        printf("Inserire il cognome della prima persona: ");
        scanf("%s", persona1.cognome);
        printf("Inserire l'eta' della prima persona: ");
        scanf("%d", &persona1.eta);
        printf("Inserire il nome della seconda persona: ");
        scanf("%s", persona1.nome);
        printf("Inserire il cognome della seconda persona: ");
        scanf("%s", persona1.cognome);
        printf("Inserire l'eta' della seconda persona: ");
        scanf("%d", &persona1.eta);

        if(persona1.eta>persona2.eta)
            printf("La persona piu' anziana e': %s\n", persona1.nome); 
        if(persona1.eta<persona2.eta)
                printf("La persona piu' anziana e': %s\n", persona2.nome);
        if(persona1.eta==persona2.eta)
                printf("Le due persone hanno la stessa eta'\n");
    return 0;
}