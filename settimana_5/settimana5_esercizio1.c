#include <stdio.h>
#include<stdlib.h>
#include<time.h>
/*
Autore: Casini Lorenzo
Inizio: 10/11/16
Modifica: 13/11/16
Versione 2.1
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
