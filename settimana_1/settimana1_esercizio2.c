#include <stdio.h>
#include <stdlib.h>
/*
ESERCIZIO 2

Scrivere un programma C che usi TUTTI gli operatori studiati; stampare i valori delle variabili usate prima e dopo l’applicazione degli stessi.
*/
/*
Autore = Casini Lorenzo
Pregetto = Esercizio2
Versione = 1.2.1
Data Inizio = 06/10/2016
Data Aggiornamneto = 09/10/2016
*/
int main()
{
    //dichiarazione delle variabile da utilizzare
    int a, b,risultato;
    a = 20;
	b = 5;
	printf("Operatori Aritmetici\n");
	//stampo il valore delle variabili prima di utilizzarle
    printf("Le variabili valgono: a= %d e b= %d\n",a,b);
    //faccio la differenza con l'operatore -
	risultato = a - b;
	//stampo il risultato ottenuto
	printf("risultato di %d - %d = %d\n",a,b,risultato);

    //assegno nuovi valori alle variabili
    a = 21;
	b = 3;
	//stampo il valore delle variabili
	printf("Le variabili valgono: a= %d e b= %d\n",a,b);
	//faccio il prodotto
	risultato = a * b;
	//stampo il risultato
	printf("risultato di %d * %d = %d\n",a,b,risultato);

	//assegno nuovi valori alle variabili
    a = 49;
	b = 7;
	//stampo il loro valore
	printf("Le variabili valgono: a= %d e b= %d\n",a,b);
	//effettuo la differenza
	risultato = a / b;
	//stampo il risultato
	printf("risultato di %d / %d = %d\n",a,b,risultato);

	//assegno nuovi valori
    a = 31;
	b = 45;
	//stampo il loro contenuto
	printf("Le variabili valgono: a= %d e b= %d\n",a,b);
	//effettuo la somma
	risultato = a + b;
	//stampo il risultato finale
	printf("risultato di %d + %d = %d\n",a,b,risultato);

    //assegno nuovi valori
	a = 17;
	b = 5;
	//stampo i valori
	printf("Le variabili valgono: a= %d e b= %d\n",a,b);
	//effettuo l'operazione di somma
	risultato = a % b;
	//stampo il risultato finale,con %% viene stampato il simbolo %
	printf("risultato di %d %% %d = %d\n",a,b,risultato);

	//stampo un separatore

	printf("----------------------------------------------------------------------------\n");
	printf("Operatore ++\n");
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////esistono operatori prefissi o postfissi////////////////////////////////////////////////////////
    /////////////nell'esempio di codice sotto ho riportato dei postfissi////////////////////////////////////////
    /////////////la differenza sta nel momento in cui viene effettuata l'operazione/////////////////////////////
    /////////////Gli operatori prefissi modificano il proprio operando prima che ne venga utilizzato il valore//
    /////////////Gli operatori postfissi modificano il proprio operando dopo avere utilizzato il valore/////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//assegno nuovi valori alle variabili
	a=5;
	b=10;
	//stampo il loro valore
    printf("Le variabili valgono: a= %d e b= %d\n",a,b);

    printf("con l'operatore ++[variabile] incrementiamo di 1 la variabile stessa\n");
    //eseguo gli operatori ++
    //operandi postfissi
    a++;
    b++;
    //stampo il valore finale
    printf("Le variabili valgono: a= %d e b= %d\n",a,b);

    printf("----------------------------------------------------------------------------\n");
    printf("Operatore --\n");

    //assegno nuovi valori
	a=5;
	b=10;
	//stampo il loro valore
    printf("Le variabili valgono: a= %d e b= %d\n",a,b);
    printf("con l'operatore --[variabile] diminuiamo di 1 la variabile stessa\n");
    //effettuo l'operazione --
    a--;
    b--;
    //stampo il loro valore finale
    printf("Le variabili valgono: a= %d e b= %d\n",a,b);

    printf("----------------------------------------------------------------------------\n");

    printf("Utilizzo degli operatori prefissi e postfissi\n");

    //assegnazione di nuovi valori alle variabili
    a = 10;
    b = 10;
    //utilizzo di operatori sia prefissi che postfissi
    printf("%d %d\n",a--,--b);
    printf("%d %d\n",a--,--b);
    printf("%d %d\n",a--,--b);
    printf("%d %d\n",a--,--b);
    printf("%d %d\n",a--,--b);
    printf("%d %d\n",a--,--b);
    printf("%d %d\n",a--,--b);
    printf("%d %d\n",a--,--b);
    printf("%d %d\n",a--,--b);
    printf("%d %d\n",a--,--b);


    printf("----------------------------------------------------------------------------\n");
    printf("Operatore compatto +=\n");

    //assegno nuovi valori
	a=7;
	//stampo il loro valore
    printf("La variabile vale: a = %d \n",a);
    //eseguo la somma compatta,equivale a=a+a;
    a+=a;
    //stampo il loro valore finale
    printf("La variaile vale: a = %d \n",a);

    printf("----------------------------------------------------------------------------\n");
    printf("Operatore compatto -=\n");

    //assegno nuovi valori
	a=12;
	//stampo il loro valore
    printf("La variabile vale: a = %d \n",a);
    //eseguo la differenza compatta equivale a= a-2;
    a-=2;
    //stampo il loro valore finale
    printf("La variaile vale: a = %d \n",a);

    printf("----------------------------------------------------------------------------\n");
    printf("Operatore compatto /=\n");

    //assegno nuovi valori
	a=144;
	//stampo il loro valore
    printf("La variabile vale: a = %d \n",a);
    //la differenza compatta equivale a= a/2;
    a/=2;
    //stampo il loro valore finale
    printf("La variaile vale: a = %d \n",a);

    printf("----------------------------------------------------------------------------\n");
    printf("Operatore compatto *=\n");

    //assegno nuovi valori
	a=5;
	//stampo il loro valore
    printf("La variabile vale: a = %d \n",a);
    //eseguo il prodotto compatto equivale a= a*3;
    a*=3;
    //stampo il loro valore finale
    printf("La variaile vale: a = %d \n",a);

    printf("----------------------------------------------------------------------------\n");
    printf("Operatore compatto %=\n");

    //assegno nuovi valori
	a=254;
	//stampo il loro valore
    printf("La variabile vale: a = %d \n",a);
    //equivale a = a%125;
    a%=125;
    //stampo il loro valore finale
    printf("La variaile vale: a = %d \n",a);

    return 0;
}
