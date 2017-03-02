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
#include"Liste.h"
#include<stdio.h>
#include<stdlib.h>
//PILA DINAMICA
int Push_malloc(struct Lista_malloc *ld, int elem);
int Pop_malloc(struct Lista_malloc *ld);
void InitLista_malloc(struct Lista_malloc *ld, int dim);
int PilaPiena_malloc (struct Lista_malloc *ld);

//PILA COLLEGATA
int PilaVuota_colleg(struct Lista_colleg *testa);
int Push_colleg(struct Lista_colleg **testa, int elem);
int Pop_colleg(struct Lista_colleg **testa);

//CODA DINAMICA
void InitCoda_malloc(struct Lista_malloc *ld, int dimensione);
int CodaVuota_malloc(struct Lista_malloc *ld);
int AggiungiCoda_malloc(struct Lista_malloc *ld, int elem);
int DatoCoda_malloc(struct Lista_malloc *ld);

//CODA COLLEGATA
int AggiungiCoda_colleg(struct Lista_colleg **testa, int elem);
int DatoCoda_colleg(struct Lista_colleg **testa);
int CodaVuota_colleg(struct Lista_colleg **testa);
