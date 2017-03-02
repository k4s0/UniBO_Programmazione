/*
Nome: Casini lorenzo
Versione 1.0
Data Inizio: 26/12/2016
Es: 1
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
