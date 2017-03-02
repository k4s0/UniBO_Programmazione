/*
Nome: Casini lorenzo
Versione 1.0
Data Inizio: 26/12/2016
Es: 1
*/
/*
Predisporre una libreria di gestione del tipo di dato astratto LISTA, implementato sia tramite allocazione indicizzata
(vettore statico e vettore dinamico) che tramite strutture collegate. Le funzioni che, come minimo,
dovranno essere implementate sono: inserisci in testa, inserisci in coda, inserisci dopo un certo elemento,
cancella dalla testa, cancella dalla coda, cancella la prima occorrenza dell’elemento.
Il programma deve visualizzare lo stato della lista ad inizio esecuzione (vuota) e dopo ogni operazione scelta dall'utente. Ad esempio:

lista: vuota

inserisci in testa elemento 5

lista: 5

inserisci in testa elemento 12

lista: 12 5

inserisci in coda elemento 21

lista: 12 5 21

inserisci in testa elemento 9

lista: 9 12 5 21

togli dalla testa

lista: 12 5 21

togli dalla coda

lista: 12 5

inserisci dopo elemento 12 l'elemento 8

lista: 12 8 5

inserisci dopo elemento 8 l'elemento 4

lista: 12 8 4 5

cancella prima occorrenza dell'elemento 8

lista: 12 4 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//Includo mie librerie
#include "libreria.h"
#include "libreria.c"

int main(){
  //Dichiaro tutte le variabili che mi servono
  int dimVetDinamico=MAX;
  int scelta,check,elem,ricerca,numero,count;
  struct cella *testa;
  //Inizializzo le variabili
  testa = NULL;
  check=0;
  Dvett=(int *)malloc(MAX*sizeof(int));
  for(count=0;count<MAX;count++){
    Dvett[count]=NULL;
  }
  //Inizio menu
  puts("Decidi con cosa vuoi lavorare\n Vettore statico(1)\n Vettore Dinamico(2)\n Lista(3)");
  printf(">");
  scanf("%d",&scelta);
  fflush(stdin);
  switch(scelta){
    case 1://Vettore statico
        while(1){
            system("cls");
            printf("Seleziona l\'operazione:\n");
            printf("\n 1 - Inserisci nuovo elemento");
            printf("\n 2 - Inserisci in coda");
            printf("\n 3 - Inserisci dopo un certo elemento");
            printf("\n 4 - Cancella Testa");
            printf("\n 5 - Cancella Coda");
            printf("\n 6 - Cancella elemento");
            printf("\n Qualsiasi altro numero - Esci");
            printf("\n\n > ");
            scanf("%d",&scelta);
            fflush(stdin);
            switch(scelta){
                case 1://Aggiunta elemento in Testa
                    system("cls");
                    puts("Elemento da aggiungere:");
                    scanf("%d",&elem);
                    fflush(stdin);
                    inserisciInTestaVettS(elem);
                    system("pause");
                    break;
                case 2://Aggiunta elemento in Coda
                    system("cls");
                    puts("Elemento da aggiungere:");
                    scanf("%d",&elem);
                    fflush(stdin);
                    inserisciInCodaVettS(elem);
                    system("pause");
                    break;
                case 3://Aggiunta elemento dopo ricerca
                    system("cls");
                    puts("Elemento da aggiungere:");
                    scanf("%d",&elem);
                    fflush(stdin);
                    puts("Elemento da ricercare:");
                    scanf("%d",&ricerca);
                    fflush(stdin);
                    InserisciDopoEleVettS(elem,ricerca);
                    system("pause");
                    break;
                case 4://Cancellazione Testa
                    system("cls");
                    cancellaTestaVettS();
                    system("pause");
                    break;
                case 5://Cancellazione Coda
                    system("cls");
                    cancellaCodaVettS();
                    system("pause");
                    break;
                case 6://Cancellazione Elemento
                    system("cls");
                    puts("Elemento da ricercare:");
                    scanf("%d",&ricerca);
                    fflush(stdin);
                    cancellaDopoElem(ricerca);
                    system("pause");
                    break;
                default://Chiusura
                    system("cls");
                    puts("Bye Bye");
                    return 0;
            }
        }
        break;

    case 2://Vettore Dinamico
        while(1){
            system("cls");
            printf("Seleziona l\'operazione:\n");
            printf("\n 1 - Inserisci nuovo elemento");
            printf("\n 2 - Inserisci in coda");
            printf("\n 3 - Inserisci dopo un certo elemento");
            printf("\n 4 - Cancella Testa");
            printf("\n 5 - Cancella Coda");
            printf("\n 6 - Cancella elemento");
            printf("\n 7 - Incrementa Vettore");
            printf("\n Qualsiasi altro numero - Esci");
            printf("\n\n > ");
            scanf("%d",&scelta);
            fflush(stdin);
            switch(scelta){
                case 1:
                    system("cls");
                    puts("Elemento da aggiungere:");
                    scanf("%d",&elem);
                    fflush(stdin);
                    inserisciInTestaVettD(elem,dimVetDinamico);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    puts("Elemento da aggiungere:");
                    scanf("%d",&elem);
                    fflush(stdin);
                    inserisciInCodaVettD(elem,dimVetDinamico);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    puts("Elemento da aggiungere:");
                    scanf("%d",&elem);
                    fflush(stdin);
                    puts("Elemento da ricercare:");
                    scanf("%d",&ricerca);
                    fflush(stdin);
                    InserisciDopoEleVettD(elem,ricerca,dimVetDinamico);
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    cancellaTestaVettD(dimVetDinamico);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    cancellaCodaVettD(dimVetDinamico);
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    puts("Elemento da ricercare:");
                    scanf("%d",&ricerca);
                    fflush(stdin);
                    cancellaDopoElemD(ricerca,dimVetDinamico);
                    system("pause");
                    break;
                case 7:
                    check++;
                    if(check==1){
                        system("cls");
                        puts("Raddopiate le posizioni");
                        dimVetDinamico=incremento(Dvett,2,dimVetDinamico);
                        system("pause");
                    }
                    else{
                        puts("Azione non piu' possibile");
                        system("pause");
                    }

                    break;
                default:
                    system("cls");
                    puts("Bye Bye");
                    return 0;
            }
        }
        break;

    case 3:
            while (1){
            system("cls");
            printf("Seleziona l\'operazione:\n");
            printf("\n 1 - Inserisci nuovo elemento");
            printf("\n 2 - Inserisci in coda");
            printf("\n 3 - Inserisci dopo un certo elemento");
            printf("\n 4 - Elimina Testa");
            printf("\n 5 - Elimina Coda");
            printf("\n 6 - Elimina Elemento");
            printf("\n Qualsiasi altro numero - Esci");
            printf("\n\n > ");
            scanf("%d",&scelta);
            switch(scelta){
                case 1: //Inserisci in testa
                    system("cls");
                    printf("\n\n Inserisci il valore intero da inserire nella lista: ");
                    fflush(stdin);
                    scanf("%d",&numero);
                    if(creaElemento(&testa,numero))
                        printf("\n\n Nuovo elemento creato correttamente!\n ");
                    else
                        printf("\n\n Elemento presente, impossibile inserire!\n ");
                    system("pause");
                    stampaLista(testa);
                    system("pause");
                    break;
                case 2: //Inserisci in coda
                    system("cls");
                    printf("\n\n Inserisci il valore intero da inserire nella lista: ");
                    fflush(stdin);
                    scanf("%d",&numero);
                    if(creaElementoCoda(&testa,numero))
                        printf("\n\n Nuovo elemento creato correttamente!\n ");
                    else
                        printf("\n\n Elemento presente, impossibile inserire!\n ");
                    system("pause");
                    stampaLista(testa);
                    system("pause");
                    break;
                case 3: //Inserisci dopo elemento
                    system("cls");
                    printf("\n\n Inserisci il valore intero da inserire nella lista: ");
                    fflush(stdin);
                    scanf("%d",&numero);
                    printf("\n\n Inserisci il valore da ricercare: ");
                    fflush(stdin);
                    scanf("%d",&ricerca);
                    if(creaElementoDopo(&testa,numero,ricerca))
                        printf("\n\n Nuovo elemento creato correttamente!\n ");
                    else
                        printf("\n\n Elemento da ricercare non presente oppure numero inserito gi� presente, impossibile inserire!\n ");
                    system("pause");
                    stampaLista(testa);
                    system("pause");

                    break;
                case 4: //Cancella Testa
                    system("cls");
                    printf("\n Verra\' eliminata la prima occorenza della lista");
                    if (eliminaElementoTesta(&testa))
                        printf("\n\n Il valore e\' stato eliminato dalla lista\n ");
                    system("pause");
                    stampaLista(testa);
                    system("pause");
                    break;
                case 5: //Cancella Coda
                    system("cls");
                    printf("\n Verra\' eliminata la coda della lista");
                    if (eliminaElementoCoda(&testa))
                        printf("\n\n Il valore e\' stato eliminato dalla lista\n ");
                    system("pause");
                    stampaLista(testa);
                    system("pause");
                    break;
                case 6: //Cancella Elemento
                    system("cls");
                    printf("\n Verra\' eliminata la prima occorrenza trovata a partire dalla testa");
                    printf("\n\n Inserisci il valore da eliminare nella lista: ");
                    fflush(stdin);
                    scanf("%d",&numero);
                    if (eliminaElemento(&testa,numero))
                        printf("\n\n Il valore %d e\' stato eliminato dalla lista\n ",numero);
                    else
                        printf("\n\n Il valore selezionato NON e\' presente in lista\n ");
                    system("pause");
                    stampaLista(testa);
                    system("pause");
                    break;
                default: //Esci dal programma
                    resetLista(&testa);
                    puts("Bye Bye");
                    return 0;
                    break;
            }
        }
        break;

    default:
        puts("Inserimento Sbagliato");
        return 0;
  }


  return 0;
}
