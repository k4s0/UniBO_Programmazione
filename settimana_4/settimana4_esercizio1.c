/*
Autore: Lorenzo Casini
Versione:1.0
Data Inizio:27/10/2016
Modifica:27/10/2016
*/
/*
ESERCIZIO 1

Scrivere un programma C che, preso in ingresso un valore intero n,
ne effettui la conversione nel corrispondente numero binario e lo memorizzi in un vettore.
Se si decide di effettuare limitazioni al valore di ingresso n, assicurarsi che le stesse siano
gestite a livello di programma. Corredare il programma degli opportuni commenti.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define vvet 32

int main()
{
    int binario [vvet]={0};//dichiaro il vettore per contenere il mio numero convertito
    int valore,condizione,i,conta,risultato;
    char ripeti;
    valore=condizione=i=conta=risultato=0;
    do
    {
             do{

            printf("Inserisci Il Numero Da Convertire In Binario==>");
            fflush(stdin);
            scanf("%d",&valore);
            if(valore<UINT_MAX&&valore>0){//controllo che il numero immesso non sia più grande della variabile unsigned int
                    condizione=0;//condizone falsa allora il numero è buono
            }else if(valore<0||valore > UINT_MAX){
                system("cls");
                printf("Errore Valore Non Gestito!\n");
                condizione=1;//condizione vera all'ora il numero non è valido

            }

        }while(condizione==1);//rieseguo fino a quando l'utente non immette un numero valido

        for(i=0;valore!=0;i++){

                conta++;//variabile per contare i campi usati nell'array

                risultato=valore/2;//divido per 2 il numero

                if(valore%2==0){//controllo il resto della divisione e scrivo 0 se senza resto 1 se c'e' il resto
                    binario[i]=0;
                }else if(valore%2==1){
                    binario[i]=1;
                }

                valore=risultato;


        }

        system("cls");

        printf("Il Valore Convertito In Binario Vale==>");
        for(i=conta-1;i>=0;i--){//stampo il vettore al contrario

                printf("%d",binario[i]);//stampo il vettore con il mio numero

        }
        printf("\n");


        printf("Vuoi rieseguire il programma?(Y|N): \n");//chiedo all'utente se vuole rieseguire il programma
        fflush(stdin);
        scanf("%c",&ripeti);
        system("cls");

    }while(ripeti=='y'|| ripeti=='Y');//controllo la scelta dell'utente di rieseguire il programma





    return 0;
}
