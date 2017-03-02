#include <stdio.h>
#include <stdlib.h>
/*
Autore:Lorenzo Casini
Versione:1.1
Data Inizio:19/10/2016
Ultimo Aggiornamento:19/10/2016
*/
/*
ESERCIZIO 1

Scrivere un programma C che, preso in input un valore riga e un valore colonna, stampi a video la tavola pitagorica della moltiplicazione e quella dell’addizione,
utilizzando una volta il costrutto for e una volta il costrutto while (quindi sia for che while per la somma, sia for che while per la moltiplicazione).
Inserire nel codice il controllo sull’input dell’utente.
*/

int main()
{
    int righe,colonne,i,j,scelta,conta;//variabili per utilizzo di cicli e vari contatori
    char ripeti;
    righe=colonne=scelta=0;



    do{//ciclo do-while per la riesecuzione del programma se la condizione == true

        printf("Scegli il tipo di ciclo:\n");
        printf("1)Ciclo FOR\n");
        printf("2)Ciclo WHILE\n");
        printf("Scelta:");
        fflush(stdin);
        scanf("%d",&scelta);

        switch(scelta){//switch per la creazione di un men� di selezione delle tabelle generate con ciclo FOR o WHILE
        case 1:
           do {//ciclo per il controllo dell'immissione di numeri soltanto positivi
                printf("Inserire un numero maggiore o uguale a 1\n");
                printf("Inserire numero di colonne: ");
                scanf("%d", &colonne);
                printf("Inserire numero di righe: ");
                scanf("%d", &righe);
                printf("\n\n");
            } while (righe<1 || colonne<1);//controllo che l'utente inserisca un range di valori interi giusto
            system("cls");//pulisco lo schermo
            printf("\t\tTavolo Pitagorica Della Moltiplicazione\n");

            for(i=1;i<=colonne;i++){//cicli annidati per la creazione della tavola pitagorica
                for(j=1;j<=righe;j++){
                        printf("%d\t",i*j);//tavola moltiplicazione

                }
                printf("\n");//stampo separatore di righe
            }
            printf("\t\tTavolo Pitagorica Dell'Addizione\n");

            for(i=0;i<=colonne;i++){//cicli annidati per la creazione della tavola pitagorica
                for(j=0;j<=righe;j++){
                        printf("%d\t",i+j);//tavola addizione

                }
                printf("\n");//stampo separatore di righe
            }

            break;
        case 2:
            do {//ciclo per il controllo dell'immissione di numeri soltanto positivi
                printf("Inserire un numero maggiore o uguale a 1\n");
                printf("Inserire numero di colonne: ");
                scanf("%d", &colonne);
                printf("Inserire numero di righe: ");
                scanf("%d", &righe);
                printf("\n\n");
            } while (righe<1 || colonne<1);
            system("cls");
            printf("\t\tTavolo Pitagorica Della Moltiplicazione\n");


            i=0;

            while(i<=colonne){//cicli annidati per la creazione della tavola pitagorica
                    j=0;
                    while(j<=righe){
                        printf("%d\t",i*j);//tavola moltiplicazione
                        j++;
                    }
                i++;
                printf("\n");//stampo separatore di righe

            }
            printf("\t\tTavolo Pitagorica Dell'Addizione\n");


            i=0;

            while(i<=colonne){//cicli annidati per la creazione della tavola pitagorica
                    j=0;
                    while(j<=righe){
                        printf("%d\t",i+j);//tavola addizione
                        j++;
                    }
                i++;
                printf("\n");//stampo separatore di righe

            }


            break;
        default:
            printf("ERRORE! Inserisci un valore compreso tra [1,2]\n");
            break;
        }





            printf("Vuoi cambiare tipo di ciclo?(Y|N): \n");//chiedo all'utente se vuole rieseguire il programma
            fflush(stdin);//Libero sempre il buffer per evitare problemi di letture false
            scanf("%c",&ripeti);
            system("cls");

    }while(ripeti=='y'|| ripeti=='Y');//controllo la scelta dell'utente se vuole rieseguire il programma


    return 0;
}
