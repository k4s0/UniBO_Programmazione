#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define mlung 30
/*
Autore:Lorenzo Casini
Inizio:17/11/16
Modifica:17/11/16
Versione: 1.0.1
*/
int main(void)
{
    char ch=(char*)malloc((1) * sizeof(char));
    char *pch;//puntatore al carattere
    char *ppch;//punatore al puntatore
    pch=(char*)malloc((mlung+1) * sizeof(char));//creazione spazio per stringa
    ppch=pch;//inizializzo al primo posto il puntatore del puntatore

    printf("Inserisci Parola Da Modificare:");
    while(( ch = getchar()) != '\n'){//controllo i caratteri fino a quando non trovo un \n
        if (!isspace(ch) && !ispunct(ch))//controllo per spazi e segni di punteggiatura ecc
        {

            *pch=tolower(ch);//trasformo tutti i caratteri in minuscolo

            pch++;//scorro la posizone del puntatore
        }

    }
    *pch='\0';//inserisco carattere di terminazione

    system("cls");
    printf("Parola Modificata = %s\n",ppch);



    return 0;
}
