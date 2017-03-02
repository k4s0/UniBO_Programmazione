/*
Nome: Casini lorenzo
Versione 1.0
Data Inizio: 26/12/2016
Es: 1
*/
/*
Predisporre una libreria di gestione del tipo di dato astratto LISTA, implementato sia tramite allocazione indicizzata
(vettore statico e vettore dinamico) che tramite strutture collegate. Le funzioni che, come minimo,
dovranno essere implementate sono: inserisci in testa, inserisci in coda, inserisci dopo un certo elemento,
cancella dalla testa, cancella dalla coda, cancella la prima occorrenza dell’elemento.
Il programma deve visualizzare lo stato della lista ad inizio esecuzione (vuota) e dopo ogni operazione scelta dall'utente. Ad esempio:

lista: vuota

inserisci in testa elemento 5

lista: 5

inserisci in testa elemento 12

lista: 12 5

inserisci in coda elemento 21

lista: 12 5 21

inserisci in testa elemento 9

lista: 9 12 5 21

togli dalla testa

lista: 12 5 21

togli dalla coda

lista: 12 5

inserisci dopo elemento 12 l'elemento 8

lista: 12 8 5

inserisci dopo elemento 8 l'elemento 4

lista: 12 8 4 5

cancella prima occorrenza dell'elemento 8

lista: 12 4 5
*/

#ifndef Gestione_Liste_Varie
#define Gestione_Liste_Varie

//Vettore Statico
#define MAX 3
	int vett[MAX]={NULL};

	int inserisciInTestaVettS(int);
	int inserisciInCodaVettS(int);
	int InserisciDopoEleVettS(int,int);
	int cancellaTestaVettS();
	int cancellaCodaVettS();
	int cancellaDopoElem(int);

//Liste
	struct cella
    {
        int valore;
        struct cella *next;
    };

    int creaElemento(struct cella **t, int num);
    int creaElementoCoda(struct cella **t, int num);
    int creaElementoDopo(struct cella **t, int num, int ricerca);
    void stampaLista(struct cella *t);
    int cercaInLista(struct cella *t, int numero);
    int eliminaElemento(struct cella **t, int num);
    int eliminaElementoTesta(struct cella **t);
    int eliminaElementoCoda(struct cella **t);
    void resetLista(struct cella **t);

//Vettore Dinamico
    int *Dvett;

	int inserisciInTestaVettD(int,int);
	int inserisciInCodaVettD(int,int);
	int InserisciDopoEleVettD(int,int,int);
	int cancellaTestaVettD(int);
	int cancellaCodaVettD(int);
	int cancellaDopoElemD(int,int);
	int incremento(int *,int,int);
#endif
