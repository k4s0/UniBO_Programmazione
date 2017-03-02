/*
Autore: Casini Lorenzo
Inzio:19/10/2016
Aggiornamento:23/10/2016
Versione: 2.1
*/

#include <stdio.h>

int main ()
{
    int numero_studenti,scelta,i;//
    float media_classe,conta_media,media_prov;
    char ripeti;
    do
    {
        numero_studenti=scelta=i=media_classe=conta_media=media_prov=0;//azzero le variabili
        printf("Che Tipo Di Ciclo Vuoi Usare?\n");//faccio scegliere all'utente dal menu che tipo di ciclo usare'
        printf("1)FOR\n");
        printf("2)WHILE\n");
        printf("Scelta = ");
        fflush(stdin);
        scanf("%d",&scelta);
        system("cls");
        switch(scelta){
        case 1:
            do {//ciclo per il controllo dell'immissione di numeri soltanto positivi
                printf("Inserisci il numero degli studenti: ");
                scanf("%d",&numero_studenti);
            } while (numero_studenti<1);//controllo che il numero degli studenti non sia negativo
            for(i=1;i<=numero_studenti;i++){
                do {

                printf("Inserisci Voto Studente numero%d\n",i);
                scanf("%f",&conta_media);

            } while (conta_media<1||conta_media>10);//controllo che il voto sia compreso tra 1 e 10

            media_prov+=conta_media;//faccio la somma dei voti validi per la media finale

            }
            media_classe = media_prov/numero_studenti;//effettuo la media dei voti degli studenti
            system("cls");
            printf("\n");
            printf("\n");
            printf("Media Della Classe = %.2f\n",media_classe);//stampo la media della classe con un massimo di 2 decimali
            //blocco di istruzioni per restituire dei commneti in base alla media
            if(media_classe<6)
                printf("Media Classe Insufficente!\n");
            if(media_classe>=6&&media_classe<7)
                printf("Media Classe Sufficente!\n");
            if(media_classe>=7&&media_classe<8)
                printf("Media Classe Discreta!\n");
            if(media_classe>=8&&media_classe<9)
                printf("Media Classe Buona!\n");
            if(media_classe>=9&&media_classe<=10)
                printf("Media Classe Ottima!\n");
            break;

        case 2:
            //stesso programma funzionante allo stesso modo solo che al posto del for() c'e' un while()

            do {//ciclo per il controllo dell'immissione di numeri soltanto positivi
                printf("Inserisci il numero degli studenti: ");
                scanf("%d",&numero_studenti);
            } while (numero_studenti<1);//controllo il numero degli studenti
            i=1;
            while(i<=numero_studenti){
                do {

                printf("Inserisci Voto Studente numero%d\n",i);
                scanf("%f",&conta_media);

            } while (conta_media<1||conta_media>10);//controllo i voti che siano tra 1 e 10

            media_prov+=conta_media;//inzio a sommare i voti nella media provvisoria(solo quelli accettabili)
            i++;

            }
            media_classe = media_prov/numero_studenti;//media vera e propria dei voti
            system("cls");
            printf("\n");
            printf("\n");
            printf("Media Della Classe = %.2f\n",media_classe);//stampo la media con precisione di 2 decimali

            //esprimo un giudizio in base alla media della classe

            if(media_classe<6)
                printf("Media Classe Insufficente!\n");
            if(media_classe>=6&&media_classe<7)
                printf("Media Classe Sufficente!\n");
            if(media_classe>=7&&media_classe<8)
                printf("Media Classe Discreta!\n");
            if(media_classe>=8&&media_classe<9)
                printf("Media Classe Buona!\n");
            if(media_classe>=9&&media_classe<=10)
                printf("Media Classe Ottima!\n");
            break;
        default:
            break;
        }
        printf("Vuoi rieseguire il programma?(Y|N): \n");//chiedo all'utente se vuole rieseguire il programma
        fflush(stdin);
        scanf("%c",&ripeti);
        system("cls");

    }while(ripeti=='y'|| ripeti=='Y');//controllo la scelta dell'utente di rieseguire il programma


    return 0;

}
