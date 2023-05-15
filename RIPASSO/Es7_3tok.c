#include <stdio.h>
#include <string.h>

#define DIM 256

int main(){
    char parola[DIM];

    printf("Inserire la parola da cercare: ");
    scanf("%s", parola);

    FILE* fp = fopen("stringa.txt", "r");

    char s[DIM];
    fgets(s, 256, fp);

    char *token = strtok(s, " \n\0");

    int n=0;
    while(token != NULL){
        if(!strcmp(parola, token))
            n++;
        token =strtok(NULL, " \n\0");
    }
    fclose(fp);
    printf("Parola '%s' trovata %d volte\n", parola,n);
}