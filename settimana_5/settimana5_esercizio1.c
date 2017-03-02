#include <stdio.h>
#include<stdlib.h>
#include<time.h>
/*
Autore: Casini Lorenzo
Inizio: 10/11/16
Modifica: 13/11/16
Versione 2.1
*/
/*
ESERCIZIO 1

Scrivere un programma C che generi un “cammino casuale” all’interno di una matrice 10x10.
La matrice conterrà dei caratteri (inizialmente saranno tutti ‘.’). Il programma deve passare casualmente da un elemento all'altro,
muovendosi in alto, in basso, a sinistra o a destra di una posizione soltanto. Gli elementi visitati dal programma dovranno essere etichettati
con lettere che vanno dalla A alla Z nell'ordine con cui vengono visitati. Ecco un esempio dell’output desiderato:

A . . . . . . . . . .

B C D . . . . . . .

. F E . . . . . . .

H G . . . . . . . .

I . . . . . . . . .

J . . . . . . . Z .

K . . R S T U V Y .

L M P Q . . . W X .

. N O . . . . . . .

. . . . . . . . . .

Suggerimento: generare un numero casual fra 0 e 3 indicante la direzione della prossima mossa. Prima di effettuare la mossa controllare che:

    Non vada fuori dalla matrice
    Non porti ad un elemento al quale è già stata assegnata una lettera.

Se una delle due condizioni viene violata, provate a muovervi in un’altra direzione. Se tutte le direzioni sono bloccate, il programma deve terminare. Ecco un esempio di fine prematura:

A B G H I . . . . .
. C F . J K . . . .
. D E . M L . . . .
. . . . N O . . . .
. . W X Y P Q . . .
. . V U T S R . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .

Y è bloccata in tutte le direzioni quindi non c’è modo di inserire Z.
*/
void main()
{
	//dichiarazione della matrice ed assegnamento
    char lung=65, mtr1[10][10]={{'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'}};
     int i, j, c, r, s=0, mossa=0, ct=0;

    srand(time(NULL));
    r=rand()%10;
    c=rand()%10;
    mtr1[r][c]=lung;
    lung++;
    ct++;
    do//ciclo per eseguire il controllo delle dmensione della mtr1 che non esca dai valori e
		//controllo della casella se vuota o no
    {
        if(ct==26)
        {
            break;
        }
        mossa=rand()%4;
        s=0;
        switch(mossa)//direzione della mossa presa dal random
        {
            case 0: if(c!=0)
                    {
                        if(mtr1[r][c-1]=='.')//controllo che il valore sia un .
                        {
                            c--;
                            mtr1[r][c]=lung;
                            lung++;
                            ct++;
                            break;
                        }
                        else
                            s++;

                    }
                    else
                        s++;
            case 1: if(r!=9)
                    {
                        if(mtr1[r+1][c]=='.')//controllo che il valore sia un .
                        {
                            r++;
                            mtr1[r][c]=lung;
                            lung++;
                            ct++;
                            break;
                        }
                        else
                            s++;
                    }
                    else
                        s++;
            case 2: if(c!=9)
                    {
                        if(mtr1[r][c+1]=='.')//controllo che il valore sia un .
                        {
                            c++;
                            mtr1[r][c]=lung;
                            lung++;
                            ct++;
                            break;
                        }
                        else
                            s++;
                    }
                    else
                        s++;
            case 3: if(r!=0)
                    {
                        if(mtr1[r-1][c]=='.')//controllo che il valore sia un .
                        {
                            r--;
                            mtr1[r][c]=lung;
                            lung++;
                            ct++;
                            break;
                        }
                        else
                            s++;

                    }
                    else
                        s++;
        }
    }while(s<4);
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)//vado a stampare la matrice
        {
            printf(" %5c", mtr1[i][j]);

        }
        printf("\n\n");
    }
}
