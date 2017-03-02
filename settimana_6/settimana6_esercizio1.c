#include <stdio.h>
/*
Autore:Lorenzo Casini
Inizio:17/11/16
Modifica:17/11/16
Versione: 1.0
*/

int main(){
    int intero=5;
    char carattere='c';
    float virgola1=17.25f;
    double virgola2=10055.58562;
    //dichiarazione puntatori
    int *pintero;
    char *pcarattere;
    float *pvirgola1;
    double *pvirgola2;
    //stampa puntatore a intero
    pintero=&intero;
    printf("Il puntatore a int vale==> %d\n",*pintero);
    //stampa puntatore a char
    pcarattere=&carattere;
    printf("Il puntatore a char vale==> %c\n",*pcarattere);
    //stampa puntatore a float
    pvirgola1=&virgola1;
    printf("Il puntatore a float vale==> %f\n",*pvirgola1);
    //stampa puntatore a double
    pvirgola2=&virgola2;
    printf("Il puntatore a double vale==> %f\n",*pvirgola2);
    return 0;
}


