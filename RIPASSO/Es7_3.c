#include <stdio.h>
#include <string.h>

#define DIM 30

int main(){
    char parola[DIM];

    printf("Inserire la parola da cercare: ");
    scanf("%s", parola);

    FILE* fp = fopen("stringa.txt", "r");

    int n=0;
    while(!feof(fp)){
        char s[DIM];
        fscanf(fp, "%s", s);
        if(!strcmp(s, parola))
            n++;
    }
    fclose(fp);
    printf("Parola trovato %d volte\n", n);
}