/*
Autore:Casini Lorenzo
versione 2.1.3
*/
#define MAX 10
#define VUOTA -1
#define INDEF -2



struct Lista_malloc
{
    int* vettore;
    int size;
    int last;
};

struct Lista_colleg
{
    int num;
    struct Lista_colleg* next;
};


int Inizializza( struct Lista_malloc *ld, int dim);
void StampaDinamica(struct Lista_malloc ld);
int AggiungiDinamica(struct Lista_malloc *ld, int elem);
void MoreSize(struct Lista_malloc *ld);
int CodaDinamica(struct Lista_malloc *ld, int elem);
int AggiungiDopo(struct Lista_malloc *ld, int pos, int elem);
int CancPrimoDinamico(struct Lista_malloc *ld);
int CancUltimoDinamico(struct Lista_malloc *ld);
int CancellaElem(struct Lista_malloc *ld, int elem);

int Addhead_link(struct Lista_colleg **testa, int elem);
void Stampa_link(struct Lista_colleg *testa);
int Addafter_link(struct Lista_colleg **testa, int elem, int elem_dacercare);
int Addlast_link(struct Lista_colleg **testa, int elem);
int DeleteHead_link(struct Lista_colleg **testa);
int Delete_link(struct Lista_colleg **testa, int elem_dacercare);
int DeleteLast_link(struct Lista_colleg **testa);
