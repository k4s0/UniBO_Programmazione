/*
Autore: Casini Lorenzo
Inizio 30/11/16
Modifica : 30/11/16
Versione: 1.0
*/
/*
ESERCIZIO 2

Modificare il programma dell'esercizio 1 in modo che il vettore di studenti venga allocato dinamicamente e
successivamente riallocato al suo riempimento. Inizialmente usare la funzione malloc() per allocare lo spazio sufficiente per un
vettore di 10 strutture studente, Quando il vettore non ha più spazio per contenere nuovi studenti, utilizzare la funzione realloc()
per raddoppiare la sua dimensione. Ripetere il raddoppio delle dimensioni ogni volta che il vettore si riempe.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//creo il protoitpo per le mie funzioni
int Inserimento();
int Mostrami();
int Modifica();

typedef struct //creo la struttura per gli esami
{
  int analisi;
  int programmazione;
}NUM_ESAMI;

typedef struct //creo la struttura per gli studenti
{
  int num_matr;
  char nome[26];
  char cognome[26];
  int giorno;
  int mese;
  int anno;
  NUM_ESAMI pianods;
} studente;

//qualche variabile fa sempre comodo
studente* insieme;
int tokenp=0;
int cont;
int gestionematricole;
int mol=1;

int Inserimento() //Funzione per l'inserimento di studenti
{
  system("cls");//Per windows: "cls", per mac: avete i soldi per prendere il libro che lo spiega
  printf("Inserire Il Numero Di Matricola[Max 10 Caratteri]:");
  cont=scanf("%d", &insieme[tokenp].num_matr);
  while ( getchar() != '\n' );
  if(insieme[tokenp].num_matr<0||insieme[tokenp].num_matr>9999999999||cont==0)//controllo che l'input della matricola si giusto
    return 0;

  printf("\nInserire nome matricola(Max25Caratteri):");
  scanf("%25s", insieme[tokenp].nome);
  while ( getchar() != '\n' ); //Inserimento nome studente

  printf("\nInserire cognome matricola(Max25Caratteri):");
  scanf("%25s", insieme[tokenp].cognome);
  while ( getchar() != '\n' ); //Inserimento cognome studente

  printf("\nInserire giorno data di nascita(Max2Caratteri)(Formato 0-30):");
  cont=scanf("%2d",&insieme[tokenp].giorno);
  while ( getchar() != '\n' );
  if(cont<=0 || insieme[tokenp].giorno>30)
    return 0; //Inserimento data di nascita

  printf("\nInserire mese data di nascita(Max2Caratteri)(Formato 0-11):");
  cont=scanf("%2d",&insieme[tokenp].mese);
  while ( getchar() != '\n' );
  if(cont<=0 || insieme[tokenp].mese>11)
    return 0; //Inserimento mese di nascita

  printf("\nInserire anno data di nascita(Max4Caratteri):");
  cont=scanf("%4d",&insieme[tokenp].anno);
  while ( getchar() != '\n' );
  if(cont<=0)
    return 0; //Inserimento anno di nascita

  printf("\nInserire Voto Esame Analisi:");
  cont=scanf("%2d",&insieme[tokenp].pianods.analisi);
  while ( getchar() != '\n' );
  if(cont<=0 || insieme[tokenp].pianods.analisi>30)
    return 0; //Inseirmento piano di studi

  printf("\nInserire Voto Programmazione:");
  cont=scanf("%2d",&insieme[tokenp].pianods.programmazione);
  while ( getchar() != '\n' );
  if(cont<=0 || insieme[tokenp].pianods.programmazione>30)
    return 0;

  for(cont=0; cont<(10*mol); cont++)
  {
    if(cont!=tokenp)
    {
      if(insieme[tokenp].num_matr==insieme[cont].num_matr)
      return 2;
    }
  } //Controllo presenza o meno della matricola
  return 1;
}

int Mostrami() //Funzione per vedere lo studente
{
  system("cls");
  printf("Inserire Matricola Studente:");
  scanf("%10d",&gestionematricole);
  while ( getchar() != '\n' );
  for(cont=0; cont<(10*mol); cont++)
  {
    if(gestionematricole==insieme[cont].num_matr)
    {
      printf("Matricola:%d\nNome:%s\nCognome:%s\nData di nascita:%d/%d/%d\nPiano di Studi\n\tAnalisi:%d\n\tProgrammazione:%d",insieme[cont].num_matr,insieme[cont].nome,insieme[cont].cognome,insieme[cont].giorno,insieme[cont].mese,insieme[cont].anno,insieme[cont].pianods.analisi,insieme[cont].pianods.programmazione);
      return 1;
    }
  }
  return 0;
}

int Modifica() //modificare il piano di Studi
{
  system("cls");
  printf("Inserire Matricola Studente:");
  scanf("%10d",&gestionematricole);
  while ( getchar() != '\n' );
  for(cont=0; cont<(10*mol); cont++)
  {
    if(gestionematricole==insieme[cont].num_matr)
    {
      printf("\nInserire Nuovo Voto Analisi:");
      cont=scanf("%2d",&insieme[cont].pianods.analisi);
      while ( getchar() != '\n' );
      if(cont<=0 || insieme[cont].pianods.analisi>30)
        return 1;

      printf("\nInserire Nuovo Voto Programmazione:");
      cont=scanf("%2d",&insieme[cont].pianods.programmazione);
      while ( getchar() != '\n' );
      if(cont<=0 || insieme[cont].pianods.programmazione>30)
        return 1;
    }
  }
  return 0;
}

int main()
{
  insieme=(studente*)malloc(sizeof(studente)*10);
  if(insieme==NULL){
    puts("Memoria Insufficente!");
    return 0;

  }
  int dowhile=1;
  do//Per riniziare dal menu
  {
    system("cls");
    puts("\n\n");
    int check;
     puts("\t\t--------------------------------------------- \n");
    puts("\t\t| BENVENUTO NEL GESTIONALE UNIVERSITARIO     | \n");
     puts("\t\t--------------------------------------------- \n");
    puts("Prego Selezionare Una Voce Del Menu:");
    puts("1)Aggiungi Un Nuovo Studente");
    puts("2)Visualizza Studente");
    puts("3)Modifica Dati Studente\n");
    printf("Scelta==>");
    char menu='0';
    do //Controllo selezione del menu
    {
      scanf("%c",&menu);
      while ( getchar() != '\n' );
      if(menu!='0'&&menu!='1'&&menu!='2')
        puts("Sbagliato opzione, ripetere la scelta");
    }while(menu!='0'&& menu!='2' && menu!='1');

    switch(menu) //Eventi del menù
    {
        case '1': //Aggiungere Matricola
          if(tokenp<10)
          {
            check=Inserimento();
            if(check==0)
            {
              puts("Errore di Inserimento");
              return 0;
            }
            if(check==2)
            {
              puts("Matricola già presente");
              return 0;
            }
          }
          else
          {
              insieme=(studente*)realloc(insieme,sizeof(studente)*2);//Riallocazione
              if(insieme==NULL){
                puts("Memoria Insufficente!");
                return 0;
              }
              if(mol==1)
                mol=2;
              if(mol==2)
                mol = mol+2;
              return 0;
          }
          tokenp++;
          dowhile=0;
          break;

        case '2':
          check=Mostrami();
          if(check==0)
          {
            puts("Matricola non presente");
          }
          dowhile=0;
          break;

        case '3':
          check=Modifica();
          if(check==1)
          {
            puts("Errore Inserimento");
          }
          dowhile=0;
          break;
    }
  }while(dowhile==0);

  free(insieme);
  return 0;
}
