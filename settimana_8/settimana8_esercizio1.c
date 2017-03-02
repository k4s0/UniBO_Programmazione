/*
Autore:Casini Lorenzo
Inizio: 1/12/16
Modifica: 4/12/16
Versione: 2.0
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
/*
ATTENZIONE IL PROGRAMMA POTREBBE CRASHARE MA TERMINA PERFETTAMENTE L'ESECUZIONE
QUINDI CHIUDERE IL MESSAGGIO DI WINDOWS E VERIFICARE L'EFFETTIVO FUNZIONAMENTO
GUARDANDO L'OUTPUT DELLA SHELL ------------GRAZIE------------
*/


/*PROTOTIPI FUNZIONI*/
int funz_cerca_vett_ord (int *vettore, int cerca, int dim, int*);

void ordina_vettore(int*, int);
void stampa(int *, int);
int funz_cerca(int*, int, int, int*);

/*VARIABILI GLOBALI*/
int dim, cerca, start = 0, trovato = FALSE;
int *vett;

/*MAIN*/
int main () {

	int i;

	/*definizione grandezza vettore*/
    do {
		fflush(stdin);
        printf("Inserire il numero di elementi del vettore:"); //prendo in input il numero di elementi del vettore
    } while (scanf("%d", &dim) != 1 || dim < 1);

    vett = (int*)malloc(dim * sizeof(int)); //alloco spazio per il vettore

    srand((unsigned int)time(NULL));
	/*controllo malloc*/
	if (vett == NULL) {
		printf("MEMORIA INSUFFICIENTE!");
	}

    printf("\n\n      Stampo vettore non ordinato      \n\n");

    /*randomizzo il vettore*/
    for (i = 0; i < dim; i++) {
		*(vett + i) = rand()%10+1; //inizializzo casualmente il vettore
		printf("%d  ", *(vett + i));
	}
	printf("\n\n");

    /*ricerca numero*/
	do {
		fflush(stdin);
		printf("\n\nInserire il numero da cercare:");
	} while (scanf("%d", &cerca) != 1 || (cerca < 1 || cerca > 10));

    int *vettInd = (int*)malloc(sizeof(int)); //dichiaro e alloco vettore di indici
    if (vettInd == NULL) {
		printf("MEMORIA INSUFFICIENTE!");
	}

    int risultato = funz_cerca(vett, cerca, dim, vettInd); //restituirà -1 se non è stato trovato l'elemento, oppure la lunghezza del vettore (ovvero quanti elementi uguali sono stati trovati)

    /*stampa degli elementi ricercati*/
    stampa(vettInd, risultato);

	/*ordinamento vettore (bubblesort)*/
	printf("\n\n      Ordino il vettore      \n      Stampo vettore ordinato      \n\n");

    /*ordino vettore in ordine crescente*/
    ordina_vettore(vett, dim);

    /*stampo vettore ordinato*/
    for (i = 0; i < dim; i++) {
		printf("%d  ", *(vett + i));
	}

    int *vettIndOrd = (int*)malloc(sizeof(int)); //nuovo vettore di indici (per la ricerca binaria)
    if (vettIndOrd == NULL) {
		printf("MEMORIA INSUFFICIENTE!");
	}
	int risultatoOrd = funz_cerca_vett_ord(vett, cerca, dim, vettIndOrd); //-1 se l'elemento non viene trovato, oppure la lunghezza del vettore

    /*ordino il vettore di indici*/
    ordina_vettore(vettIndOrd, risultatoOrd);

    /*stampo gli elementi ricercati*/
    stampa(vettIndOrd, risultatoOrd);

    /*libero la memoria precedentemente allocata*/
    free(vett);
    free(vettInd);
    free(vettIndOrd);

    printf("\n\n");
    return 0;
}

/*FUNZIONE ORDINA VETTORE*/
void ordina_vettore(int *vettore, int dim){

	int a, b, c;

	/*ordinamento bubble sort*/
	for (a = 0 ; a < ( dim - 1 ); a++)
	{
		for (b = 0 ; b < dim - a - 1; b++)
		{
			if (*(vettore+ b) > *(vettore + b + 1))
			{
                /*switch degli elementi*/
				c = *(vettore + b);
				*(vettore + b) = *(vettore + b + 1);
				*(vettore + b + 1) = c;
			}
		}
	}
}

/*FUNZIONE CERCA*/
int funz_cerca (int *vettore, int cerca, int dim, int *vettInd) {
    int i, j = 1, c = 0;
    int *temp; //puntatore di appoggio

    for (i = 0; i < dim; i++) {
		if (*(vettore + i) == cerca){ //se trovo un elemento

            temp = vettInd;
            vettInd = malloc(sizeof(int)*(j++)); //aumento la dimensione del blocco di memoria per il vettore di indici
            if (vettInd == NULL) {
                printf("MEMORIA INSUFFICIENTE!");
            }
            vettInd = temp;

            c++; //incremento il conteggio per la dimensione

            *(vettInd + j - 2) = i; //inizializzo la nuova cella con il valore dell'indice
        }
	}

    if (c == 0) {
        return -1; //non è stato trovato l'elemento
    } else {
        return c; //restituisce la quantità di elementi immagazzinati
    }
}

/*FUNZIONE CERCA VETTORE ORDINATO*/
int funz_cerca_vett_ord (int *vettore, int cerca, int dim, int *vettIndOrd) {

    int j = 1, c = 0, inf = 0, sup = dim, valMedio, trovato = FALSE, *temp;

    /*ricerca binaria*/
    while(inf <= sup && trovato == FALSE) {

        valMedio = (inf+sup)/2; //trovo il valor medio

        if(cerca == *(vettore + valMedio)) { //se corrisponde all'elemento ricercato
            temp = vettIndOrd;
            vettIndOrd = malloc(sizeof(int)*(j++)); //lo immagazzino e alloco nuova memoria
            if (vettIndOrd == NULL) {
                printf("MEMORIA INSUFFICIENTE!");
            }
            vettIndOrd = temp;
            *vettIndOrd = valMedio;
            c++; //incremento il contatore per la dimensione

            int valMedioInf = valMedio; //variabili di appoggio per la ricerca di simili prima e dopo l'elemento trovato
            int valMedioSup = valMedio;

            /*ricerca di simili nella parte inferiore dell'array rispetto alla media*/
            while (valMedioInf >= 0 && *(vettore + --valMedioInf) == cerca) {

                temp = vettIndOrd;
                vettIndOrd = malloc(sizeof(int)*(j++));
                if (vettIndOrd == NULL) {
                    printf("MEMORIA INSUFFICIENTE!");
                }
                vettIndOrd = temp;

                c++;

                *(vettIndOrd + j - 2) = valMedioInf;
            }

            /*ricerca di simili nella parte superiore dell'array rispetto alla media*/
            while (valMedioSup < dim && *(vettore + ++valMedioSup) == cerca) {

                temp = vettIndOrd;
                vettIndOrd = malloc(sizeof(int)*(j++));
                if (vettIndOrd == NULL) {
                    printf("MEMORIA INSUFFICIENTE!");
                }
                vettIndOrd = temp;

                c++;

                *(vettIndOrd + j - 2) = valMedioSup;
            }
            trovato = TRUE;

        } else if(cerca > *(vettore + valMedio)) {
            inf = valMedio + 1;

        } else {
            sup = valMedio - 1;
        }
    }

    if (c == 0) {
        return -1;
    } else {
        return c;
    }
}

/*FUNZIONE STAMPA*/
void stampa(int *indice, int ris){

	/*stampa vettore*/
    if (ris == -1) {
        printf("\nIl valore cercato non e' stato trovato all'interno del vettore.");
    } else {
        int length = ris;
        char singPlur;
        if (length == 1) {
            singPlur = 'a';
        } else {
            singPlur = 'e';
        }
        printf("\n\nIl numero %d e' stato trovato (%d volt%c) in posizione: ", cerca, length, singPlur);
        int i;
        for (i = 0; i < ris; i++) {
            printf("%3d ", *(indice + i));
        }
    }
}
