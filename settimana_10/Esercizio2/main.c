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
#include"Pile.h"
#include<stdio.h>
#include<stdlib.h>

struct Lista_malloc ld;
int main()
{
    //PILA
    int scelta;
    int memoria;
    int elem;
    printf("Pila\n");
    printf("Pila indicizzata statica\n\n");
    printf("Digitare la dimensione della pila:\n");
    scanf("%d", &memoria);
    InitLista_malloc(&ld, memoria);
    do
    {
        printf("\nScelte possibili:\n");
        printf("1: Aggiungi in Pila\n");
        printf("2: Visualizza dato\n");
        printf("0: Prosegui\n");
        scanf("%d", &scelta);

        switch(scelta)
        {
            case 0: scelta=0;
                    break;
            case 1: printf("Digitare l'elemento da inserire in pila\n");
                    scanf("%d", &elem);
                    Push_malloc(&ld, elem);
                    break;
            case 2: printf("%2d", Pop_malloc(&ld));
                    break;
        }
        if(PilaPiena_malloc(&ld)==1)
        {
            printf("Pila Piena\n");
        }
        else
        {
            printf("Pila Vuota\n");
        }
        }while(scelta!=0);

    free(ld.vettore);
    system("PAUSE");
    system("CLS");
    printf("\nPILA COLLEGATA\n");
    struct Lista_colleg *testa=NULL;

    do
    {
        printf("\nScelte possibili:\n");
        printf("1: Aggiungi in Pila\n");
        printf("2: Visualizza dato\n");
        printf("0: Prosegui\n");
        scanf("%d", &scelta);

        switch(scelta)
        {
            case 0: scelta=0;
                    break;
            case 1: printf("Digitare l'elemento da inserire in pila\n");
                    scanf("%d", &elem);
                    Push_colleg(&testa, elem);
                    break;
            case 2: printf("%2d", Pop_colleg(&testa));
                    break;
        }
        if(PilaVuota_colleg(testa)==1)
        {
            printf("\nPila Vuota\n");
        }
        }while(scelta!=0);

        //LIBERO AREA DI MEMORIA
        struct Lista_colleg *tmp;
        while(testa!=NULL)
        {
            tmp=testa;
            free(tmp);
            testa=testa->next;
        }
        free(testa);

    //CODA

    system("PAUSE");
    system("CLS");
    printf("Coda Dinamica\n");
    printf("Digitare la dimensione della coda:\n");
    scanf("%d", &memoria);
    InitCoda_malloc(&ld, memoria);
    do
    {
        printf("\nScelte possibili:\n");
        printf("1: Aggiungi in coda\n");
        printf("2: Visualizza dato\n");
        printf("0: Prosegui\n");
        scanf("%d", &scelta);

        switch(scelta)
        {
            case 0: scelta=0;
                    break;
            case 1: printf("Digitare l'elemento da inserire in coda\n");
                    scanf("%d", &elem);
                    AggiungiCoda_malloc(&ld, elem);
                    break;
            case 2: printf("%2d\n", DatoCoda_malloc(&ld));
                    system("PAUSE");
                    break;
        }
        if(CodaVuota_malloc(&ld)==1)
        {
            printf("Coda Vuota\n");
        }

        }while(scelta!=0);

    free(ld.vettore);
    system("PAUSE");
    system("CLS");

    printf("Coda Collegata\n");
    do
    {
        printf("\nScelte possibili:\n");
        printf("1: Aggiungi in coda\n");
        printf("2: Visualizza dato\n");
        printf("0: Prosegui\n");
        scanf("%d", &scelta);

        switch(scelta)
        {
            case 0: scelta=0;
                    break;
            case 1: printf("Digitare l'elemento da inserire in coda\n");
                    scanf("%d", &elem);
                    AggiungiCoda_colleg(&testa, elem);
                    break;
            case 2: printf("%2d\n", DatoCoda_colleg(&testa));
                    system("PAUSE");
                    break;
        }
        if(CodaVuota_colleg(&testa)==1)
        {
            printf("Coda Vuota\n");
        }

        }while(scelta!=0);

        //LIBERO AREA DI MEMORIA
        while(testa!=NULL)
        {
            tmp=testa;
            free(tmp);
            testa=testa->next;
        }
        free(testa);




    return 0;
}
