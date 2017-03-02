#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
/*
Autore = Casini Lorenzo
Pregetto = Esercizio1
Versione = 1.1
Data Inizio = 06/10/2016
Data Aggiornamneto = 09/10/2016
*/
int main()
{
    //dichiarazione delle variabili necessarie , utilizzo tutti i tipi conosciuti
    int numero_caratteri;
    int intero=12;
    unsigned int numero_intero_no_segno=11;
    short int numero_corto_intero=5;
    unsigned short int numero_intero_no_segno_corto=4;
    long int numero_intero_lungo=1234;
    unsigned long int numero_intero_lungo_no_segno=15328;
    char carattere='a';
    unsigned char carattere_no_segno='b';
    float numero_float=4.2;
    double numero_double=4.254;
    long double numero_long_double=44.5;


    //stampo il valore della variabile intera, utilizzo i %d per stamapre il valore della variabile e i dati del min e del max
    numero_caratteri=printf (" Tipo : %-9s Min : %-20d Max : %-20d Bytes : %d\n "," int ",INT_MIN , INT_MAX,sizeof (int ) );
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %d\n",numero_caratteri,intero);

    // creazione di un separatore
    printf("--------------------------------------------------------------------------------------------------------------\n");

    //stampo il valore unsigned int , nel valore max utilizzo il %u per specificare che si tratta di un tipo unsigned
    numero_caratteri= printf (" Type : %-9s Min : %-20d Max : %-20u Bytes : %d\n "," unsigned_int ",0, UINT_MAX,sizeof (unsigned int ) );
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %d\n",numero_caratteri,numero_intero_no_segno);

    // creazione di un separatore
    printf("--------------------------------------------------------------------------------------------------------------\n");

    //stampo il valore short int, utilizzo il semplice %d
    numero_caratteri= printf (" Type : %-9s Min : %-20d Max : %-20d Bytes : %d\n "," short_int ",SHRT_MIN , SHRT_MAX,sizeof (short int ));
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %d\n",numero_caratteri,numero_intero_no_segno);

    // creazione di un separatore
    printf("--------------------------------------------------------------------------------------------------------------\n");

    //stampo il valore unsigned short int,utilizzo il %u per specificare che si tratta di un unsigned short
    numero_caratteri= printf (" Type : %-9s Min : %-20d Max : %-20u Bytes : %d\n "," unsigned short int ",0, USHRT_MAX ,sizeof (unsigned short int ));
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %d\n",numero_caratteri,numero_intero_no_segno_corto);

    // creazione di un separatore
    printf("--------------------------------------------------------------------------------------------------------------\n");

    //stampo il valore long int, utilizzo il %ld per specificare che tratto un dato di tipo long
    numero_caratteri= printf (" Type : %-9s Min : %-20ld Max : %-20ld Bytes : %d\n "," long int ",LONG_MIN,LONG_MAX ,sizeof (long int ));
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %d\n",numero_caratteri,numero_intero_lungo);

    // creazione di un separatore
    printf("--------------------------------------------------------------------------------------------------------------\n");

    //stampo il valore unsigned long int, il %lu specifica l'utilizzo di una variabile unsigned long
    numero_caratteri= printf (" Type : %-9s Min : %-20lu Max : %-20lu Bytes : %d\n "," unsigned long int ",0,ULONG_MAX ,sizeof (unsigned long int ));
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %d\n",numero_caratteri,numero_intero_lungo_no_segno);

    // creazione di un separatore
    printf("--------------------------------------------------------------------------------------------------------------\n");

    //stampo il valore char, char stampo i valori min e max con %d e il valore della variabile stessa con %c
    numero_caratteri=printf (" Type : %-9s Min : %-20d Max : %-20d Bytes : %d\n "," char ",CHAR_MIN , CHAR_MAX ,sizeof ( char ));
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %c\n",numero_caratteri,carattere);

     // creazione di un separatore
    printf("--------------------------------------------------------------------------------------------------------------\n");

     //stampo il valore unsigned char,stesso cosa del char sopra ma essendo unsigned il valore minimo è 0
    numero_caratteri=printf (" Type : %-9s Min : %-20d Max : %-20d Bytes : %d\n "," unsigned char ",0, UCHAR_MAX ,sizeof ( unsigned char ));
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %c\n",numero_caratteri,carattere_no_segno);

     // creazione di un separatore
    printf("--------------------------------------------------------------------------------------------------------------\n");

     //stampo il valore float,per il valore della variabile da visualizzare utilizzo il %f
    numero_caratteri=  printf (" Type : %-9s Min : %-20e Max : %-20e Bytes : %d\n "," float ",FLT_MIN , FLT_MAX ,sizeof ( float ));
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %.2f\n",numero_caratteri,numero_float);


    // creazione di un separatore
    printf("--------------------------------------------------------------------------------------------------------------\n");

     //stampo il valore double
    numero_caratteri =  printf (" Type : %-9s Min : %-20g Max : %-20g Bytes : %d\n "," double ",DBL_MIN , DBL_MAX ,sizeof ( double ));
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %.3lf\n",numero_caratteri,numero_double);

    // creazione di un separatore
    printf("--------------------------------------------------------------------------------------------------------------\n");

    //stampo il valore long double
    ///////////////////
    ////IMPORTANTE/////
    //ho notato che il compilatore non gestisce adeguatamente i valori del long double , restituisce infatti valori strani
    numero_caratteri =  printf (" Type : %-9s Min : %-20g Max : %-20g Bytes : %d\n "," long double ",LDBL_MIN , LDBL_MAX ,sizeof ( long double ));
    printf("Numero Caratteri Stampati :%d \n Valore Variabile: %Lf\n",numero_caratteri,numero_long_double);

return 0;

}
