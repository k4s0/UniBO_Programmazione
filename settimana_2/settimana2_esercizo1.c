/*
    Nome: lorenzo casini
    Creato: 12/10/2016
    Ultima modifica: 16/10/2016
	Versione: 2.0
 */
#include <stdio.h>
#include <stdlib.h>

/*
Scopo:scrivere un programma che chieda all'utente di immettere l'orario di arrivo all'aeroporto (espresso in ore e minuti utilizzando il formato a 24 ore).
Il programma deve visualizzare gli orari di partenza e di arrivo del primo volo che sar� possibile prendere (quello il cui orario di partenza � immediatamente successivo rispetto a quello immesso dall'utente).
*/
int main()
{
    float partenzeAM[4]={8.00,9.43,11.19,12.47}; //Dichiaro e inizializzo 4 vettori per le partenze e gli ariivi, divisi in modo che la posizione della partenza sia uguale alla posizione dell'arrivo nell'altro vettore
    float partenzePM[4]={2.00,3.45,7.00,9.45};
    float arriviAM[4]={10.16,11.52,1.31,3.00};
    float arriviPM[4]={4.08,5.55,9.20,11.58};

    float orario; //variabile per il controllo dell'ora
    int i=0;
    char ripeti;

    do  //Do-while �ciclo post-condizionato che ci permette di eseguire il programma rispettando una condizione se falsa esci dal ciclo e di conseguenza dal programma
    {
        printf("Inserisci l'orario di partenza del volo in formato 24h,\ndividendo le ore dai minuti Es.(15.30)\n");
        fflush(stdin);//libero il buffer prima di leggere dati di input da tastiera
        scanf("%f",&orario);//Faccio inserire i dati

        if(orario>12)//Con questo if controllo se sono nella zona pm o am
        {
            orario-=12;//serve per il cambio dal formato 24h a quello 12h
			
            while(i<4)
            {
                if(orario<partenzePM[i]) //Controllo per capire quale volo e' il successivo
                {
                    printf("Il prossimo volo e' in partenza alle ore: %.2fPM l'arrivo previsto e' per le ore: %.2fPM\n",partenzePM[i],arriviPM[i]);
                    i=4;
                }
                else //Nel caso il controllo non vada a buon fine, passo all'elemento successivo del vettore per fare di nuovo il controllo ed incremento la mia variabile contatore
                {
                    i++;
                }
            }
            i=0;
        }
        else
        {
            while(i<4)
            {
                if(orario<partenzeAM[i])//Controllo per verificare la posizione nel vettore
                {
                    if(orario>partenzeAM[2])//Controllo per gestire le partenze del mattino che arrivano nel pomeriggio
                        printf("Il prossimo volo e' in partenza alle ore: %.2fAM l'arrivo previsto e' per le ore: %.2fPM\n",partenzeAM[i],arriviAM[i]);//stampo l'orario giusto presente nei vettori
                    else
                        printf("Il prossimo volo e' in partenza alle ore: %.2fAM l'arrivo previsto e' per le ore: %.2fAM\n",partenzeAM[i],arriviAM[i]);////stampo l'orario giusto presente nei vettori
                    i=4;
                }
                else
                {
                    i++;
                }
            }
            i=0;
        }
        printf("Vuoi immettere nuovi orari?(Y|N): \n");//chiedo all'utente se vuole rieseguire l'immissione degli orari
        fflush(stdin);//Libero sempre il buffer per evitare problemi di letture false
        scanf("%c",&ripeti);
        system("cls");

    }while(ripeti=='y'|| ripeti=='Y'); //Condizione dell'while se falsa esce dal ciclo e termina il programma

return 0;
}
