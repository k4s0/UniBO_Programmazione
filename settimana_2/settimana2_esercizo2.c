#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
Autore = Casini Lorenzo
Pregetto = Esercizio2
Versione = 2.1
Data Inizio = 06/10/2016
Data Aggiornamneto = 16/10/2016
*/


/*
Integrare l'esercizio sugli operatori della prima settimana aggiungendo tutti quelli visti a lezione. 
Il programma complessivo dovrà quindi contenere: sizeof, cast, <, <=, >, >=, ==, !=, !, &&, ||, &, |, ^, ~, <<, >>, ?:, =, +=, -=, *=, /=
*/
/*


                HO SCRITTO E COMPILATO SU LINUX ATTENZIONE A CHI CORREGGE LO SLEEP IN LINUX SI INDICA IN SECONDI MENTRE SU WINZOZ SI INDICA IN MILLISECONDI 
                PER UNA CORRETTA VISUALIZZAZIONE SU WINZOZ SETTARE GLI SLEEP A 3000 ANZICHE' 3 .   GRAZIE


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
	sleep(3);
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
	sleep(3);

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
	sleep(3);

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
	sleep(3);


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
	sleep(3);

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
	sleep(3);

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
	sleep(3);

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
	sleep(3);

    printf("----------------------------------------------------------------------------\n");
    printf("Operatore compatto %%=\n");

    //assegno nuovi valori
	a=254;
	//stampo il loro valore
    printf("La variabile vale: a = %d \n",a);
    //equivale a = a%125;
    a%=125;
    //stampo il loro valore finale
    printf("La variaile vale: a = %d \n",a);
	sleep(3);
	printf("----------------------------------------------------------------------------\n");
    printf("Operatore <\n");

    //assegno nuovi valori
	a=25;
	b=10;
	//stampo il loro valore
    printf("La variabile  a = %d mentre la variabile b = %d, a<b?\n",a,b);
    
    if(a<b){
		printf("questa istruzione non verrà eseguita\n");
	}else{
		printf("errore! la variabile a e' piu' grande\n");
	}
	sleep(3);
	printf("----------------------------------------------------------------------------\n");
	
    printf("Operatore >\n");

    //assegno nuovi valori
	a=25;
	b=10;
	//stampo il loro valore
    printf("La variabile  a = %d mentre la variabile b = %d, a>b?\n",a,b);
    
    if(a>b){
		printf("la variabile a e' piu' grande della variabile b\n");
	}else{
		printf("errore!\n");
	}
	sleep(3);
	printf("----------------------------------------------------------------------------\n");
	
    printf("Operatore <=\n");

    //assegno nuovi valori
	a=10;
	b=10;
	//stampo il loro valore
    printf("La variabile  a = %d mentre la variabile b = %d, a<=b?\n",a,b);
    
    if(a<=b){
		printf("questa istruzione e' eseguita grazie al <=\n");
	}else{
		printf("errore! la variabile a e' piu' grande\n");
	}
	sleep(3);
	printf("----------------------------------------------------------------------------\n");
	
    printf("Operatore >=\n");

    //assegno nuovi valori
	a=10;
	b=10;
	//stampo il loro valore
    printf("La variabile  a = %d mentre la variabile b = %d, a>=b?\n",a,b);
    
    if(a>=b){
		printf("la variabile a ha un valore maggiore o \n uguale a b quindi vedi questo messaggio\n");
	}else{
		printf("errore!\n");
	}
	sleep(3);
	printf("----------------------------------------------------------------------------\n");
	
    printf("Operatore ==\n");

    //assegno nuovi valori
	a=100;
	b=90;
	//stampo il loro valore
    printf("La variabile  a = %d mentre la variabile b = %d, a==b?\n",a,b);
    
    if(a==b){
		printf("si le variabili sono uguali\n");
	}else{
		printf("no le variabili non sono uguali\n");
	}
	sleep(3);
	printf("----------------------------------------------------------------------------\n");
	
    printf("Operatore !=\n");

    //assegno nuovi valori
	a=100;
	b=90;
	//stampo il loro valore
    printf("La variabile  a = %d mentre la variabile b = %d, a!=b?\n",a,b);
    
    if(a!=b){
		printf("si le variabili sono diverse\n");
	}else{
		printf("no le variabili sono uguali\n");
	}
	sleep(3);
	printf("----------------------------------------------------------------------------\n");
	
    printf("Operatore logici\n");

    int m=40,n=20;
    int o=20,p=30;
    if (m>n && m !=0){
			printf("&& Devono verificarsi entrambe le condizioni per scrivere il messaggio\n");
	}
    if (o>p || p!=20){
			printf("|| solo una ondizione deve essere vera per vedere questo messaggio\n");
	}
   if (!(m>n && m !=0)){
			printf("! la condizione  vera,pero' io non sono visualizzato :(\n");
   }
   else{
			printf("! la condizione e' vera , ma essendo negata visualizzi questo messaggio :)\n");
   }
   sleep(3);
   	printf("----------------------------------------------------------------------------\n");
	
    printf("Operatore bit-wise\n");

	m = 40,n = 80;
	///////ATTENZIONE!!!!!!!!!
	//m=00101000
	//n=01010000
	//bisogna convertire in binario per capire i risultati ottenuti
	
	
	int AND_operatore=0,OR_operatore=0,XOR_operatore=0,NOT_operatore=0;//dischiaro le variabile per utilizzare gli operatori bit-wise
	AND_operatore = (m&n);//m&n = 00000000 (binario) = 0 (decimale)
	OR_operatore = (m|n);//m|n = 01111000 (binario) = 120 (decimale)
	NOT_operatore = (~m);//~m = 11111111111111111111111111 11111111111111111111111111111111010111 = -41 (decimale)
	XOR_operatore = (m^n);//m^n = 01111000 (binario) = 120 (decimale)
	printf("l'operatore AND vale: %d\n",AND_operatore );
	printf("l'operatore OR vale = %d\n",OR_operatore );
	printf("l'operatore NOT vale = %d\n",NOT_operatore );
	printf("l'operatore XOR vale = %d\n",XOR_operatore );
	printf("con lo spostamento a sinistra m vale = %d\n", m << 1);//spostamento a sinistra di una posizione m << 1 = 01010000 (binaio) = 80 (decimale)
	printf("con lo spostamento a destra m vale  = %d\n", m >> 1);//spostamento a destra di una posizione x >> 1 = 00010100 (binario) = 20 (decimale)
	sleep(3);
    printf("----------------------------------------------------------------------------\n");
	
    printf("Utilizzo di sizeof() e cast\n");

	float c;//dichiaro la varibile per il sizeof()
	int alfa=65;//dischiaro la variabile per il cast
	
	
	printf("Spazio utilizzato dal tipo float: %d \n",sizeof(c));//eseguo il sizeof del loat per vedere la memoria che occupa
	
	printf("La variabile alfa vale: %d mentre se utilizziamo il cast vale: %c",alfa,(char)alfa);//visualizzo prima il valore int della variabile che è 65 
																								// poi ne faccio il cast in char e visualizzo la lettera A
	


    return 0;
}
