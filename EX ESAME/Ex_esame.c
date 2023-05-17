/*Scrivere una funzione iterativa che data una lista in input e un intero k, calcoli la media dei primi k nodi nella
lista. Si analizzi e motivi la complessità in spazio e in tempo.
Es: 5->3->7->1->2->NULL   k = 3 Risultato 5*/

/*int media_it(Nodo* head, int k){
    int i=0, media=0;
    for(i=0; i<k; i++){
        media+=head->data;
        head=head->next;
    }
    media/=i;
    return media;
}*/

/*Scrivere una funzione ricorsiva che prenda in input una lista e un intero k positivo e che cancelli dalla lista tutti
i nodi a valore k, solo se sono in una posizione pari. Si analizzi e motivi la complessità in spazio e in tempo.
Es: 5->3->7->1->3->NULL k = 3 Risultato 5->7->1->3->NULL*/
                                      //p=0;  
/*void cancella_k_rc(Nodo* head, int k, int p){
    if(head!=NULL){
        if((p%2==0)&&(head->data==k)){
            Nodo* new_head=head;
            head=head->next;
            return new_head;
        }
        cancella_k_rc(head->next, k, p+1);
    }
}*/