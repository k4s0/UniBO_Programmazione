/*
Autore:Casini Lorenzo
versione 2.1.3
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
