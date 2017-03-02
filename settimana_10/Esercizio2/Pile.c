/*
Autore:Casini Lorenzo
versione 2.1.3
*/
/*
ESERCIZIO 2

Predisporre una libreria di gestione del tipo di dato astratto PILA e del tipo di dato astratto CODA implementati tramite allocazione indicizzata,
tramite strutture collegate e sfruttando la libreria scritta sulle liste. Le funzioni che, come minimo, dovranno essere implementate sono: push, pop,
ed empty per la pila e inserisci in coda, estrai dalla coda, coda vuota per la coda. Il programma deve visualizzare lo stato della coda o della
pila ad inizio esecuzione (vuota) e dopo ogni operazione scelta dall'utente, come nell'esercizio precedente.
*/
#include "Pile.h"
#include<stdio.h>
#include<stdlib.h>

//PILA DINAMICA

int Push_malloc(struct Lista_malloc *ld, int elem)
{
    int result;
    result=AggiungiDinamica(ld, elem);
    return result;
}

int Pop_malloc(struct Lista_malloc *ld)
{
    if(ld->last==VUOTA) exit(EXIT_FAILURE);
    int dato;
    dato=ld->vettore[0];
    CancPrimoDinamico(ld);
    return dato;
}

void InitLista_malloc(struct Lista_malloc *ld, int dim)
{
    Inizializza(ld, dim);
}

int PilaPiena_malloc (struct Lista_malloc *ld)
{
    return (ld->last=ld->size-1);
}

//PILA COLLEGATA

int Push_colleg(struct Lista_colleg **testa, int elem)
{
    int result;
    result=Addhead_link(&*testa, elem);
    return result;
}

int Pop_colleg(struct Lista_colleg **testa)
{
    if(*testa==NULL) exit(EXIT_FAILURE);
    int dato;
    dato=(*testa)->num;
    DeleteHead_link(&*testa);
    return dato;
}

int PilaVuota_colleg(struct Lista_colleg *testa)
{
    int a;
    if(testa==NULL) a=1;
    return a;
}

//CODA DINAMICA

void InitCoda_malloc(struct Lista_malloc *ld, int dimensione)
{
    Inizializza(ld, dimensione);
}

int CodaVuota_malloc(struct Lista_malloc *ld)
{
    int a;
    if(ld->last==VUOTA) a=1;
    return a;
}

int AggiungiCoda_malloc(struct Lista_malloc *ld, int elem)
{
    int a; //RISULTATO DELLA OPERAZIONE
    a=CodaDinamica(ld, elem);
    return a;
}

int DatoCoda_malloc(struct Lista_malloc *ld)
{
    int dato=ld->vettore[0];
    CancPrimoDinamico(ld);
    return dato;
}

//CODA COLLEGATA

int AggiungiCoda_colleg(struct Lista_colleg **testa, int elem)
{
    int risultato;
    risultato=Addlast_link(&*testa, elem);
    return risultato;
}

int DatoCoda_colleg(struct Lista_colleg **testa)
{
    if(*testa==NULL) exit(EXIT_FAILURE);
    int dato;
    dato=(*testa)->num;
    DeleteHead_link(&*testa);
    return dato;
}

int CodaVuota_colleg(struct Lista_colleg **testa)
{
    int a;
    if(*testa==NULL) a=1;
    return a;
}
