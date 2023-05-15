#include <stdio.h>
#define TRUE 1
#define FALSE 0


int cerca_carattere(char c, char str[]);

int main()
{
    char c, str[64];
    int n;

    printf("Inserire la stringa: ");
    gets(str);
    printf("Inserire il carattere da cercare: ");
    scanf("%c", &c);
    
    n = cerca_carattere(c, str);
    if (n)
        printf("Carattere trovato\n");
    else
        printf("Carattere non trovato\n");
}

int cerca_carattere(char c, char str[])
{
    if (*str == '\0')
        return FALSE;
    if (*str == c)
        return TRUE;

    return cerca_carattere(c, ++str);
}