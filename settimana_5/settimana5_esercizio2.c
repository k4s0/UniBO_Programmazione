/*
Autore:Casini Lorenzo
Inizio:13/11/16
Modifica: 13/11/16
Versione: 1.1
*/
/*
ESERCIZIO 2

Scrivere un programma C che riceva in ingresso due parole inserite da tastiera.
Si consideri che ciascuna parola può contenere al massimo 30 caratteri.
Il programma deve sostituire ogni occorrenza della seconda parola nella prima parola con il carattere ’*’.
Ad esempio, inserite le parole

abchdfffchdchdtlchd

e

chd

il programma deve visualizzare la parola

ab*fff**tl*

Scrivere due versioni: la prima deve ignorare la presenza della libreria <string.h> e quindi dovete
lavorare esplicitamente su ogni singolo carattere delle stringhe. La seconda deve usare le funzioni
della libreria <string.h> per determinare la lunghezza e per ricercare sotto-stringhe all'interno di una stringa
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 30

void main()
{
    //dichiarazioni vettori
    char str1[DIM+1];
    char str2[DIM+1];
    char sc[DIM+1];
    //dichiarazione variabili
    int i,j,z,o, l1,l2;
    int cont=0;
    char c;
    printf("Inserisci la frase principale! Massimo 30 caratteri\n==>");
    i=0;//prendo in input carattere per carattere e lo assegno a str1
    while((c=getchar()) != '\n' && i <=DIM)
    {
            str1[i] = c;
            i++;
    }
    str1[i] = '\0';//l'ultimo elemento del vettore dev essere \0
    l1 = i;//assegno al1 la lunghezza della prima stringa
    printf("Inserisci la frase da ricercare! massimo 30 caratteri\n==>");
    i=0;
    while((c=getchar()) != '\n' && i <=DIM)
    {
            str2[i] = c;
            i++;
    }
    str2[i] = '\0';
    l2= i;
    if(l1<l2)//controllo che la prima stringa sia maggiore della seconda
    {
        printf("%s\n", str1);// se e' piu grande stampo la prima stringa
    }else
    {
        z=0;
        for(i=0; i < l1 ; i++)//analizzo ogni carattere della prima stringa
            {

              cont = 0;
              if(str1[i] == str2[0])//cerco se esiste un carattere della prima stringa sia uguale al primo della seconda stringa
                {
                    for(j=0; j<l2; j++)
                    {
                        o = j+i;
                        if(str1[o]==str2[j])//controllo che i restanti elementi della stringa2 siano uguali ai restanti elementi della stringa 1
                        {
                            cont++;//aumento il contatore ogni colta che trovo una coerenza
                        }
                    }
                    if(cont == l2)//se il contatore e' uguale alla lunghezza di stringa inserisco il valore nella stringa di supporto e la incremento
                    {

                        sc[z]='*';
                        z++;
                        i+=cont-1;
                    }
                    else//se non e' uguale assegno alla stringa di supporto il valore della prima stringa
                    {
                        sc[z]=str1[i];
                        z++;
                    }
                }
                else
                {

                    sc[z]=str1[i];
                    z++;
                }
            }
    }
    sc[z]='\0';
    printf("%s\n",sc);//stampo a video la stringa di supporto
    system("pause");
    system("cls");

    printf("Inserisci la stringa principale! Massimo 30 caratteri\n");
    i=0;
    fflush(stdin);
    //prendo in input carattere per carattere e lo assegno a str1
    while((c=getchar()) != '\n' && i <=DIM)
    {
            str1[i] = c;
            i++;
    }
    str1[i] = '\0';//l'ultimo elemento del vettore dev essere \0
    l1 = i;//assegno
    printf("Inserisci l'occorrenza da ricercare! Massimo 30 caratteri\n");
    i=0;
    fflush(stdin);
    while((c=getchar()) != '\n' && i <=DIM)
    {
            str2[i] = c;
            i++;
    }
    str2[i] = '\0';
    l2= i;
    int sw;
    char *p;
    l1=strlen(str1);//trovo la lunghezza della stringa utilizzando la funzione strlen
    l2=strlen(str2);
    do
    {
        sw=(int)strstr(str1,str2);//assegno il valore della funzione strstr a sw
        if(sw==(int)NULL)//se il valore e' NULL esco dal ciclo
        {
            break;
        }
        else
        {
            p=(int)sw;//dico al puntatore p di puntare all'indirizzo di sw
            *p='*';//sostituisco il valore della prima coerenza con *
            p++;//incremento il puntatore
            for(;*p!='\0';p++)//shifto a sinistra tutti i caratteri dopo p fino a \0
            {
                *p=*(p+l2-1);
            }

        }
    }while(sw!=(int)NULL);
    printf("%s", str1);//stampo a video la stringa

}
