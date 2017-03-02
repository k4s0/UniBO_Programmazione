/*
Autore: Casini Lorenzo
Inizio: 9-12-16
Modifica: 11-12-16
Versione 1.4
*/
/*Un’azienda deve gestire un certo numero di venditori che vendono un certo numero di prodotti.
Una volta al giorno ognuno dei venditori fornisce al programma il proprio codice, il codice del prodotto venduto e la quantità
del venduto giornaliero per ogni prodotto. Scrivere un programma C che immagazzini i dati in una struttura dinamica e visualizzi le
vendite totali per ognuno dei prodotti e per ognuno dei venditori. Il programma deve inoltre stilare una classifica sia dei
prodotti che dei venditori. Organizzare l’intero programma in funzioni.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
/*struttura per inserimento di vendite giornaliere*/
typedef struct {
     int id;
	int idVend; // ID VENDITORE
	int idProd;  //ID PRODOTTO (relativo alla struttura PRDOTTO)
	int qtaVendGiorn; // QUANTITÀ VENDUTA GIORNALMENTE DAL VENDITORE

} Venditore;
/*prototipi funzioni*/
char menu();
char input(Venditore **vend, int giorno, int numVend);
void stampaVenditeTot(Venditore **vend, int totVend, int vettContaVendite[]);
void stampaVendGiorn (Venditore **vend, int ggTot, int vettContaVend[]);
void cercaProdGiorn (Venditore **vend, int ggTot, int vettContaVend[], int i);
void stampaProdGiorn (Venditore **vend, int ggTot, int vettContaVend[], int idProd, int somma, int j, int i, int k, int vettId[]);
/*variabili globali*/
int scelta;

/*main*/
int main () {
    /*variabili*/
    int termina = FALSE;
    int esci = FALSE;
	int contagg = 0;
	int contaVend = 0;


	/*ALLOCO MATRICE E VETTORE CONTAVENDITE*/
    Venditore **strVend;
    strVend = (Venditore**)malloc(sizeof(Venditore*));
	if (strVend == NULL) {
		printf("Memoria insufficiente!");
	}

	strVend[0] = (Venditore*)malloc(sizeof(Venditore) * (contaVend + 2));
	if (*strVend == NULL) {
		printf("Memoria insufficiente!");
	}

	int *vettContaVend = (int*)malloc(sizeof(int));
	if (vettContaVend == NULL) {
		printf("Memoria insufficiente!");
	}

	/*menu con scelta*/
	do {
		fflush(stdin);
		scelta = menu();
		switch (scelta) {
			case '1':
				//inserisci vendite giornaliere
                contaVend = 0;
                printf("Giorno %d\n", contagg + 1);
				//alloca nuova vendita
				do {
                  strVend[contagg] = (strVend[contagg]);malloc(sizeof(Venditore) * (contaVend + 1));
					if (strVend == NULL) {
						printf("Memoria insufficiente!");
					}
                    termina = input(strVend, contagg, contaVend);
                    contaVend++;
                }while (termina == FALSE);

                vettContaVend = realloc(vettContaVend, sizeof(int) * (contagg + 1));
				if (vettContaVend == NULL) {
					printf("Memoria insufficiente!");
				}
                vettContaVend[contagg] = contaVend;
                contagg++;
				break;

            case '2':
                stampaVenditeTot(strVend, contagg, vettContaVend);
				break;
            case '3':
				stampaVendGiorn(strVend, contagg - 1, vettContaVend);
				break;
			case '4':
				cercaProdGiorn(strVend, contagg - 1 , vettContaVend, 0);
				break;
			case '5':
				esci = TRUE;
				break;
			default:
				puts("Inserisci un numero corretto");
				break;
		}
	} while (esci == FALSE);

	printf("\n\n");

	free(*strVend);
	free(strVend);
	free(vettContaVend);
	return 0;
}

char menu() {
	/*MENU*/
	puts("\n - - - - - - - -M E N U- - - - - - - - - ");
	puts("1 > Inserisci vendite giornaliere");
	puts("2 > Visualizza report giornaliero"); //report dei valori inseriti da quando è stato aperto il programma
	puts("3 > Vendite giornaliere per venditore");
	puts("4 > Vendite giornaliere per prodotto");
	puts("5 > Esci");
	printf("Scelta==>");

	scelta = getchar();
	return scelta;
} //menu OK

char input (Venditore **vend, int giorno, int contaVend){

    printf("\nVendita numero %d - ID %d\n", contaVend + 1, contaVend);
    //id vendita
    vend[giorno][contaVend].id = contaVend;


	//id venditore
	fflush(stdin);
	printf("ID venditore");
	do {
		fflush(stdin);
		printf("==>");
	} while (scanf("%d", &vend[giorno][contaVend].idVend) != 1);

	//id prodotto
	fflush(stdin);
	printf("ID prdotto");
	do {
		fflush(stdin);
		printf("==>");
	} while (scanf("%d", &vend[giorno][contaVend].idProd) != 1);

	//quantità
	do {
		fflush(stdin);
		printf("Quantita' venduta==>");
	}while (scanf("%d", &vend[giorno][contaVend].qtaVendGiorn) != 1);

    char yn;
    int riprova = FALSE;
    do {
        fflush(stdin);
        printf("Terminare? (Y/N)==>");
        yn = getchar();
        switch (yn) {
            case 'y':
            case 'Y':
                yn = TRUE;
                riprova = FALSE;
                break;
            case 'n':
            case 'N':
                yn = FALSE;
                riprova = FALSE;
                break;
            default:
                riprova = TRUE;
                break;
        }
        system("cls");
    }while (riprova == TRUE);
    return yn;
} //input OK

void stampaVenditeTot (Venditore **vend, int ggTot, int vettContaVend[]) {
    int i, j;
    for (i = 0; i < ggTot; i++) {
        printf("      Giorno %d      \n", i + 1);
        for (j = 0; j < vettContaVend[i]; j++) {
            printf("ID vendita >       %d\n", vend[i][j].id);
            printf("ID venditore >     %d\n", vend[i][j].idVend);
            printf("ID prdotto >       %d\n", vend[i][j].idProd);
            printf("Quantita' venduta > %d\n\n", vend[i][j].qtaVendGiorn);
        }
        printf("\n\n");
    }
} //venditeTotali OK

void stampaVendGiorn (Venditore **vend, int ggTot, int vettContaVend[]) {
    int j;
    printf("      Giorno %d      \n", ggTot + 1);
    for (j = 0; j < vettContaVend[ggTot]; j++) {
        printf("ID vendita >       %d\n", vend[ggTot][j].id);
        printf("ID venditore >    %d\n", vend[ggTot][j].idVend);
        printf("ID prdotto >       %d\n", vend[ggTot][j].idProd);
        printf("Quantita' venduta > %d\n\n", vend[ggTot][j].qtaVendGiorn);
    }
} //vendite Ultimo periodo x Venditore OK

void cercaProdGiorn (Venditore **vend, int ggTot, int vettContaVend[], int i) {

	int j = 0, trovato = FALSE, numProdotti = 0;

	int **matrProd = (int**)malloc(sizeof(int*));
	if (*matrProd == NULL) {
		printf("Memoria insufficiente!");
	}

	*matrProd = (int*)malloc(sizeof(int));
	if (matrProd == NULL) {
		printf("Memoria insufficiente!");
	}

	for (i = 0; i < vettContaVend[ggTot]; i++) {
		trovato = FALSE;
		for (j = 0; j < numProdotti; j++) {
			if (*(*(matrProd + j)+ 0) ==  vend[ggTot][i].idProd) {
				*(*(matrProd + j)+ 1) += vend[ggTot][i].qtaVendGiorn;
				trovato = TRUE;
			}
		}

		if(trovato == FALSE) {
			if(numProdotti == 0) {
				*(*(matrProd + numProdotti) + 0) = vend[ggTot][i].idProd;
				*(*(matrProd + numProdotti) + 1) = vend[ggTot][i].qtaVendGiorn;
			} else {
				matrProd = (int**)realloc(matrProd, sizeof(int*) * (numProdotti));
				if (matrProd == NULL) {
					printf("Memoria insufficiente!");
				}
				*(matrProd + numProdotti) = malloc(sizeof(int) * 2);
				if (matrProd == NULL) {
					printf("Memoria insufficiente!");
				}
				*(*(matrProd + numProdotti) + 0) = vend[ggTot][i].idProd;
				*(*(matrProd + numProdotti) + 1) = vend[ggTot][i].qtaVendGiorn;
			}
			numProdotti++;
		}
	}

	printf("Vendite del %d giorno \n", ggTot+1);
	for(i = 0; i < numProdotti; i++)
	{
		printf("Prodotto: %d\n", *(*(matrProd + i) + 0));
		printf("Quantita' venduta : %d\n\n", *(*(matrProd + i) + 1));
	}
} //vendite Ultimo periodo x Prodotto OK
