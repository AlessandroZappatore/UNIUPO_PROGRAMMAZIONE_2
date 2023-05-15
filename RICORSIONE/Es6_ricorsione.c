#include <stdio.h>

int conta_carattere(char c, char str[], int n);

int main()
{
    char c, str[64];
    int n=0;

    printf("Inserire la stringa: ");
    gets(str);
    printf("Inserire il carattere da cercare: ");
    scanf("%c", &c);
    
    n = conta_carattere(c, str, n);
    
    printf("Carattere trovato %d volte\n", n);
}

int conta_carattere(char c, char str[], int n)
{
    if (*str == '\0')
        return n;
    if (*str == c)
        n++;

    return conta_carattere(c, ++str, n);
}