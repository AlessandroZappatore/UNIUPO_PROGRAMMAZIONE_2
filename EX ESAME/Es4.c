#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct brano
{
    char *titolo;
    char *autore;
    int durata;
    struct brano *next;
};

struct brano* build_playlist(char **titolo, char **autore, int *durata, int n, int i);
void skip_to(char song[], struct brano** head);
int playlist_len(struct brano* head);
struct brano* delete_song(char song[], struct brano* head);
void print_list(struct brano* head);

int main()
{
    char *titolo[] = {"On Top Of The World", "Giorgio by Moroder", "Survival"};
    char *autore[] = {"Imagine Dragons", "Daft Punk", "Eminem"};
    int durata[] = {192, 544, 292};

    struct brano* playlist=build_playlist(titolo, autore, durata, 3, 0);
    print_list(playlist);
    int len=playlist_len(playlist);
    printf("La durata restante e': %d\n", len);

    printf("\n\n");
    skip_to("Giorgio by Moroder", &playlist);
    print_list(playlist);

    len=playlist_len(playlist);
    printf("La durata restante e': %d\n", len);

    printf("\n\n");
    delete_song("Survival", playlist);
    print_list(playlist);

    while(playlist==NULL){
        struct brano* temp=playlist->next;
        free(playlist);
        playlist=temp;
    }
    
    return 0;
}

struct brano* build_playlist(char **titolo, char **autore, int *durata, int n, int i){
    struct brano* head=(struct brano*)malloc(sizeof(struct brano));
    if(i==n)
        return NULL;

    if(head==NULL)
        exit(1);

    head->titolo=titolo[i];
    head->autore=autore[i];
    head->durata=durata[i];
    head->next=build_playlist(titolo, autore, durata, n, i+1);
    return head;
}

void print_list(struct brano* head){
    if(head==NULL)
        return;
    printf("Brano: %s\tAutore: %s\tDurata: %d\n", head->titolo, head->autore, head->durata);
    print_list(head->next);
}

void skip_to(char song[], struct brano** head){
    if(*head==NULL){
        printf("Brano non trovato\n");
        return;
    }
    
    if(!strcmp((*head)->titolo, song))
        return;

    struct brano* temp=(*head)->next;
    free(*head);
    (*head)=temp;
    skip_to(song, head);
}

int playlist_len(struct brano* head){
    if(head!=NULL){
        return head->durata+playlist_len(head->next);
    }

}

struct brano* delete_song(char song[], struct brano* head){
    if(head==NULL){
        printf("Brano non trovato\n");
        return NULL;
    }

    if(!strcmp(head->titolo, song)){
        struct brano* temp=head->next;
        free(head);
        return temp;
    }

    head->next=delete_song(song, head->next);
    return head;
}
