/*
Nome: Casini lorenzo
Versione 1.0
Data Inizio: 26/12/2016
Es: 1
*/
#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

//Vettore Statico
//Aggiungere in Testa
int inserisciInTestaVettS(int elem){
  if(vett[MAX-1]==NULL){
    int supp[MAX]={NULL};
    int i=0;
    supp[i]=elem;
    for(i=1;i<=MAX;i++){
      supp[i]=vett[i-1];
    }
    for(i=0;i<MAX;i++){
      vett[i]=supp[i];
    }
  }
  else{
    puts("Vettore Completo");
    return 1;
  }
  int i=0;
  for(i=0;i<MAX;i++){
    printf("\nElemento:%d",vett[i]);
  }
  return 0;
}
//Aggiungere in Coda
int inserisciInCodaVettS(int elem){
  if(vett[MAX-1]==NULL){
    int i=0;
    while(vett[i]!=NULL){
      i++;
    }
    vett[i]=elem;
  }
  else{
    puts("Vettore Completo");
    return 1;
  }
  int i=0;
  for(i=0;i<MAX;i++){
    printf("\nElemento:%d",vett[i]);
  }
  return 0;
}
//Aggiungere dopo elemento
int InserisciDopoEleVettS(int elem, int ricerca){
  if(vett[MAX-1]==NULL){
    int supp[MAX]={NULL};
    int i=0;
    int count=0;
    while(vett[i]!=ricerca&&i<MAX){
        supp[i]=vett[i];
        i++;
    }
    supp[i]=vett[i];
    count=i;
    i++;
    supp[i]=elem;
    i++;
    count++;
    while(i<MAX){
        supp[i]=vett[count];
        i++;
        count++;
    }
    i=0;
    while(i<MAX){
      vett[i]=supp[i];
      i++;
    }
  }
  else{
    puts("Vettore Completo");
    return 1;
  }
  int i=0;
  for(i=0;i<MAX;i++){
    printf("\nElemento:%d",vett[i]);
  }
  return 0;
}
//Cancellare testa
int cancellaTestaVettS(){
    int supp[MAX]={NULL};
    int i=1;
    while(i<MAX){
        supp[i-1]=vett[i];
        i++;
    }
    i=0;
    while(i<MAX){
        vett[i]=supp[i];
        i++;
    }
    i=0;
    for(i=0;i<MAX;i++){
        printf("\nElemento:%d",vett[i]);
    }
}
//Cancellare coda
int cancellaCodaVettS(){
    int i=0;
    while(i<MAX){
        if(i==MAX-1){
            vett[i]=0;
        }
        i++;
    }
    i=0;
    for(i=0;i<MAX;i++){
        printf("\nElemento:%d",vett[i]);
    }
}
//Cancellare elemento
int cancellaDopoElem(int elem){
    int supp[MAX]={NULL};
    int i=0;
    int cont=0;
    while(vett[i]!=elem){
        i++;
    }
    vett[i]=NULL;
    i=0;
    while(i<MAX){
        if(vett[i]!=NULL){
            supp[cont]=vett[i];
            cont++;
        }
        i++;
    }
    i=0;
    while(i<MAX){
        vett[i]=supp[i];
        i++;
    }
    i=0;
    for(i=0;i<MAX;i++){
        printf("\nElemento:%d",vett[i]);
    }
}


//Lista
//Pulisce la memoria
void resetLista(struct cella **t)
{
    struct cella *temp;

    while (*t != NULL)
    {
        temp = *t;
        *t = (*t)->next;
        free(temp);
    }
}


//Restituisce 1 se l'elemento e' stato eliminato, 0 altrimenti
int eliminaElemento(struct cella **t, int num)
{
    struct cella *prec, *temp;

    temp = *t;
    prec = NULL;

    while (temp != NULL)
    {
        if (temp->valore == num)
        {
            if (prec == NULL)
                *t = (*t)->next;
            else
                prec->next = temp->next;
            free(temp);
            return 1;
        }
        prec = temp;
        temp = temp->next;
    }

    return 0;
}
//Eliminazione elemento in testa
int eliminaElementoTesta(struct cella **t)
{
    struct cella *supp,*temp;

    if(*t!=NULL)
    {
        temp = *t;
        supp = *t;
        temp = temp->next;
        free(supp);
        *t=temp;
        return 1;
    }
    else
        return 0;
}
//Eliminazione elemento in coda
int eliminaElementoCoda(struct cella **t)
{
    struct cella *temp;

    if(*t==NULL) {
        printf("Tentativo di eliminazione da lista vuota\n");
        return 0;
    }

    if((*t)->next==NULL) {
        free(*t);
        *t=NULL;
        return 0;
    }

    temp=*t;

    while(temp->next->next!=NULL)
        temp=temp->next;

    free(temp->next);
    temp->next=NULL;
    return 1;
}


/*
La testa viene passata per valore quindi le modifiche non vengono viste all'esterno
La funzione restituisce la posizione della cella in cui � stato trovato il valore, 0 altrimenti
*/
int cercaInLista(struct cella *t, int numero)
{
    int count = 0;
    while (t != NULL)
    {
        count++;
        if (t->valore == numero)
            return count;
        t = t->next;
    }
    return 0;
}

void stampaLista(struct cella *t)//La testa viene passata per valore quindi le modifiche non vengono viste all'esterno
{
    int count = 0;

    printf("\n");
    if (t == NULL)
    {
        printf(" La lista e\' vuota!\n");
        return;
    }

    while (t != NULL)
    {
        count++;
        printf(" cella %d valore: %d\n",count,t->valore);
        t = t->next;
    }

    printf("\n\n Stampati %d valori\n ",count);
}


//Viene restituito 1 se l'elemento � stato inserito, 0 se l'elemento � gi� presente in lista
int creaElemento(struct cella **t, int num)
{
    struct cella *nuovoElemento;

    if (cercaInLista(*t,num) == 0)
    {
        nuovoElemento = (struct cella*)malloc(sizeof(struct cella));
        if (nuovoElemento == NULL)
        {
            printf("\n\n Errore nell\'allocazione della memoria.\n Il programma verra\' chiuso!\n ");
            system("pause");
            exit(1);
        }
        nuovoElemento->valore = num;
        nuovoElemento->next = *t;
        *t = nuovoElemento;
        return 1;
    }
    else
        return 0;
}
//Aggiungiamo elemento in coda
int creaElementoCoda(struct cella **t, int num)
{
    if (cercaInLista(*t,num) == 0)
    {
        struct cella *nuovoElemento;
        struct cella *temp;
        nuovoElemento = (struct cella*)malloc(sizeof(struct cella));
        nuovoElemento->next=NULL;
        nuovoElemento->valore=num;
        if (*t == NULL)
            *t = nuovoElemento;
        else
        {
            temp = *t;
            while (temp->next != NULL)
                temp = temp ->next;
            temp->next = nuovoElemento;
        }
        return 1;
    }
    else
        return 0;
}
//Aggiungiamo elemento dopo un'elemento
int creaElementoDopo(struct cella **t, int num, int ricerca)
{
    if (cercaInLista(*t,ricerca) != 0 && cercaInLista(*t,num) == 0)
    {
        struct cella *nuovoElemento;
        struct cella *temp;
        nuovoElemento = (struct cella*)malloc(sizeof(struct cella));
        nuovoElemento->next=NULL;
        nuovoElemento->valore=num;
        if (*t == NULL)
            *t = nuovoElemento;
        else
        {
            temp = *t;
            while (temp->valore != ricerca)
                temp = temp ->next;
            nuovoElemento->next=temp->next;
            temp->next = nuovoElemento;
        }
        return 1;
    }
    else
        return 0;
}

//Vettore Dinamico
int incremento(int *Dvett,int elem,int dimVetDinamico)
{
    int count=dimVetDinamico;
    Dvett = (int *)realloc(Dvett, elem * sizeof(int));
    dimVetDinamico=dimVetDinamico*elem;
    for(;count<dimVetDinamico;count++){
        Dvett[count]=NULL;
    }
    return dimVetDinamico;
}

int inserisciInTestaVettD(int elem,int dimensione){
  if(Dvett[dimensione-1]==NULL){
    int supp[dimensione];
    int i=0;
    supp[i]=elem;
    for(i=1;i<=dimensione;i++){
      supp[i]=Dvett[i-1];
    }
    for(i=0;i<dimensione;i++){
      Dvett[i]=supp[i];
    }
  }
  else{
    puts("Vettore Completo");
    return 1;
  }
  int i=0;
  for(i=0;i<dimensione;i++){
    printf("\nElemento:%d",Dvett[i]);
  }
  return 0;
}

int inserisciInCodaVettD(int elem,int dimensione){
  if(Dvett[dimensione-1]==NULL){
    int i=0;
    while(Dvett[i]!=NULL){
      i++;
    }
    Dvett[i]=elem;
  }
  else{
    puts("Vettore Completo");
    return 1;
  }
  int i=0;
  for(i=0;i<dimensione;i++){
    printf("\nElemento:%d",Dvett[i]);
  }
  return 0;
}

int InserisciDopoEleVettD(int elem, int ricerca,int dimensione){
  if(Dvett[dimensione-1]==NULL){
    int supp[dimensione];
    int i=0;
    int count=0;
    while(Dvett[i]!=ricerca&&i<dimensione){
        supp[i]=Dvett[i];
        i++;
    }
    supp[i]=Dvett[i];
    count=i;
    i++;
    supp[i]=elem;
    i++;
    count++;
    while(i<dimensione){
        supp[i]=Dvett[count];
        i++;
        count++;
    }
    i=0;
    while(i<dimensione){
      Dvett[i]=supp[i];
      i++;
    }
  }
  else{
    puts("Vettore Completo");
    return 1;
  }
  int i=0;
  for(i=0;i<dimensione;i++){
    printf("\nElemento:%d",Dvett[i]);
  }
  return 0;
}

int cancellaTestaVettD(int dimensione){
    int supp[dimensione];
    int i=1;
    while(i<dimensione){
        supp[i-1]=Dvett[i];
        i++;
    }
    i=0;
    while(i<dimensione){
        Dvett[i]=supp[i];
        i++;
    }
    i=0;
    for(i=0;i<dimensione;i++){
        printf("\nElemento:%d",Dvett[i]);
    }
}

int cancellaCodaVettD(int dimensione){
    int i=0;
    while(i<dimensione){
        if(i==dimensione-1){
            Dvett[i]=0;
        }
        i++;
    }
    i=0;
    for(i=0;i<dimensione;i++){
        printf("\nElemento:%d",Dvett[i]);
    }
}

int cancellaDopoElemD(int elem,int dimensione){
    int supp[dimensione];
    int i=0;
    int cont=0;
    while(Dvett[i]!=elem){
        i++;
    }
    Dvett[i]=NULL;
    i=0;
    while(i<dimensione){
        if(Dvett[i]!=NULL){
            supp[cont]=Dvett[i];
            cont++;
        }
        i++;
    }
    i=0;
    while(i<dimensione){
        Dvett[i]=supp[i];
        i++;
    }
    i=0;
    for(i=0;i<dimensione;i++){
        printf("\nElemento:%d",Dvett[i]);
    }
}
