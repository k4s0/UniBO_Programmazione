/*
Autore:Casini Lorenzo
Inizio: 4/12/16
Modifica: 7/12/16
versione: 2.1
*/
/*
Realizzare un programma per il calcolo del fattoriale in modo da visualizzare le sue variabili locali e i parametri delle chiamate ricorsive.
Per ogni chiamata ricorsiva, visualizzare l’output su una riga separata e aggiungere un livello di rientro.
Fate del vostro meglio per rendere l’output chiaro, interessante e significativo.
L’obiettivo è quello di disegnare e implementare un formato dell’output che aiuti una persona a capire meglio la ricorsione.
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_NUM 12
/*
sel il programma da problemi eliminare la struct e la funzione qui sotto indicate da <--
*/
struct SMALL_RECT {//<---
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
};
void adjustWindowSize()//<---
{
    struct SMALL_RECT test;

    HANDLE hStdout;
    COORD coord;
    BOOL ok;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = 150;
    coord.Y = 30;
    ok = SetConsoleScreenBufferSize(hStdout, coord);

    test.Left = 0;
    test.Top = 0;
    test.Right = coord.X-1;
    test.Bottom = coord.Y-1;

    SetConsoleWindowInfo(hStdout, ok, &test);

}

int fattoriale(int num );//prototipo della mia funzione fattoriale

int main(void)
{

  adjustWindowSize();//<---richiamo alla funzione per il resize della console
  int val,fatt;
  printf("Inserisci un numero positivo per il quale calcolare il fattoriale(Valori da 1 a %d)==>",MAX_NUM);
  scanf("%d",&val);
  if(val>MAX_NUM){
        system("cls");
    puts("Inserire Un Numero Compreso Tra 1 e 12");
    return 0;
  }
  if(val<=0){
      system("cls");
    puts("Inserire Un Numero Positivo > 0");
    return 0;
  }
  fatt=fattoriale(val);//richiamo della mia funzione
  printf("Il Fattoriale del Numero %d e': %d",val,fatt);
}

int fattoriale(int num)//gli passo il valore che l'utente ha immesso
{
  int ris,j=0;
  int static i=0;
  if(num==0)//controllo che non sia uno 0 in tal caso rtituisco 1
    return 1;

  ris = num * fattoriale(num - 1);//faccio la ricorsione per il calcolo del fattoriale

  for(j=0;j<i;j++)//for per stampare gli spazi
  {
    printf("\t");
  }

  printf("%d Ricorsione fattoriale %d = %d\n",num,num,ris);//stampo il risultato del fattoriale per ogni richiamo della funzione

  i++;

  return ris;
}
