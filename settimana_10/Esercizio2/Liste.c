/*
Autore:Casini Lorenzo
versione 2.1.3
*/
#include"Liste.h"
#include<stdio.h>
#include<stdlib.h>

//LE FUNZIONI RESTITUISCONO 1 SE LE OPERAZIONI ESEGUITI SONO ANDATE A BUON FINE, 0 DIVERSAMENTE
//LISTA DINAMICA

int Inizializza( struct Lista_malloc *ld, int dim)
{
    ld->vettore=(int*)malloc((sizeof(int))*dim);
    if(ld->vettore==NULL) exit(EXIT_FAILURE);

    ld->size=dim;
    ld->last=VUOTA;

    return 1;
}

void StampaDinamica(struct Lista_malloc ld)
{
    int i;
    for(i=0; i<=ld.last; i++)
    {
        printf("%d ",ld.vettore[i]);
    }
}

void MoreSize(struct Lista_malloc *ld)
{
    ld->vettore=realloc(ld->vettore, ((ld->size)+1)*sizeof(int));
    ld->size=ld->size+1;
}

int AggiungiDinamica(struct Lista_malloc *ld, int elem)
{
    if(ld->size==0) return 0;

    if(ld->size==ld->last+1) //SE E' PIENA
    {
        MoreSize(ld);
        int i;
        for(i=ld->last; i>=0; i--)
        {
            ld->vettore[i+1]=ld->vettore[i];
        }
        ld->vettore[0]=elem;

        ld->last=(ld->last)+1;
        return 1;
    }
    else
    {
        if(ld->last==VUOTA)//SE VUOTA
        {
            ld->vettore[0]=elem;
            ++(ld->last);
            return 1;
        }
        else
        {
            int i;
            for(i=ld->last; i>=0; i--)
            {
                ld->vettore[i+1]=ld->vettore[i];
            }
            ld->vettore[0]=elem;

            ld->last=(ld->last)+1;
            return 1;
        }


    }

}

int CodaDinamica(struct Lista_malloc *ld, int elem)
{
    if(ld->size==0) return 0;

    if(ld->size==ld->last+1) //SE E' PIENA
    {
        MoreSize(ld);
        ld->vettore[ld->last+1]=elem;
        ld->last++;

        return 1;
    }
    else
    {
        ld->vettore[ld->last+1]=elem;
        ld->last++;

        return 1;
    }

}

int AggiungiDopo(struct Lista_malloc *ld, int pos, int elem) // AGGIUNGE IN UNA POSIZIONE
{
    int i;
    if(ld->size==0) return 0;
    if(pos<0 || pos>(ld->last)) return 0;

    if(ld->last+1==ld->size)
    {
        MoreSize(ld);
        for (i=ld->last; i>=pos; i--)
        {
                ld->vettore[i+1]=ld->vettore[i];
                ld->last++;
        }
        //ld->last=(ld->last)-1;
        ld->vettore[pos]=elem;

        return 1;

    }
    else
    {
        if(ld->last==VUOTA)
        {
            return 0;
        }
        else
        {
            for (i=ld->last; i>=pos; i--)
            {
                ld->vettore[i+1]=ld->vettore[i];
                ld->last++;
            }
            //ld->last=(ld->last)-1;
            ld->vettore[pos]=elem;

            return 1;
        }
    }


}

int CancPrimoDinamico(struct Lista_malloc *ld)    //ELIMINA IL PRIMO
{
    if(ld->size==0) return 0;
    if(ld->last==VUOTA)
    {
        return 0; //Nulla da eliminare
    }
    else
    {
        if(ld->last==0)
        {
            ld->last=(ld->last-1);
        }
        else
        {
            int i;
            for(i=1; i<=ld->last; i++)
            {
                ld->vettore[i-1]=ld->vettore[i];
            }

            ld->last=(ld->last-1);
        }

        return 1;
    }
}

int CancUltimoDinamico(struct Lista_malloc *ld)  //ELIMINA L'ULTIMO
{
    if(ld->size==0) return 0;
    if(ld->last==VUOTA)
    {
        return 0;
    }
    else
    {
        ld->last=(ld->last-1);
        return 1;
    }

}

int CancellaElem(struct Lista_malloc *ld, int elem) //ELimina
{
    if(ld->size==0) return 0;
    int i;
    int j;
    if(ld->last==VUOTA)
    {
        return 0;
    }
    else
    {
        if(ld->last==0)
        {
            ld->last=(ld->last)-1;
            return 1;
        }
        else
        {
            for(i=0; i<=(ld->last); i++)//Trovo l'elemento
            {
                if(ld->vettore[i]==elem)
                {
                    for(j=i; j+1<=ld->last; j++)
                    {
                    ld->vettore[j]=ld->vettore[j+1];
                    }
                }
            }
            ld->last=ld->last-1;
            return 1;
        }

    }

}

//Lista Collegata Semplice

void Stampa_link(struct Lista_colleg *testa)
{
    while(testa!=NULL)
    {
        printf("%d ", testa->num);
        testa=testa->next;
    }
}

int Addhead_link(struct Lista_colleg **testa, int elem)
{
    struct Lista_colleg *nuovo;
    nuovo=(struct Lista_colleg*)malloc(sizeof(struct Lista_colleg));
    if(nuovo==NULL)
    {
        printf("Errore di alloccazione\n");
        exit(EXIT_FAILURE);
        return 0;
    }

    nuovo->next=NULL;
    nuovo->num=elem;

    if(*testa==NULL)
    {
        *testa=nuovo;
        return 1;
    }
    else
    {
        nuovo->next=*testa;
        *testa=nuovo;
        return 1;
    }
}

int Addlast_link(struct Lista_colleg **testa, int elem)
{
    struct Lista_colleg *tmp;
    struct Lista_colleg *nuovo;
    nuovo=(struct Lista_colleg*)malloc(sizeof(struct Lista_colleg));
    if(nuovo==NULL)
    {
        printf("Errore di alloccazione\n");
        exit(EXIT_FAILURE);
        return 0;
    }

    nuovo->next=NULL;
    nuovo->num=elem;

    if(*testa==NULL)
    {
        *testa=nuovo;
        return 1;
    }
    else
    {
        tmp=*testa;
        while(tmp->next!=NULL) //SCORRE FINO ALL'ULTIMO
        {
            tmp=tmp->next;
        }
        tmp->next=nuovo;
        return 1;

    }
}

int Addafter_link(struct Lista_colleg **testa, int elem, int elem_dacercare)
{
    if(*testa==NULL)
    {
        return 0;
    }

    struct Lista_colleg *nuovo;
    nuovo=(struct Lista_colleg*)malloc(sizeof(struct Lista_colleg));
    if(nuovo==NULL)
    {
        exit(EXIT_FAILURE);
        return 0;
    }
    nuovo->num=elem;
    nuovo->next=NULL;

    struct Lista_colleg *tmp;
    tmp=*testa;

    while(tmp!=NULL)
    {
        if(tmp->num==elem_dacercare)
        {
            nuovo->next=tmp->next;
            tmp->next=nuovo;
            return 1;
        }

        tmp=tmp->next;
    }

    return 0;
}

int DeleteHead_link(struct Lista_colleg **testa)
{
    if(*testa==NULL) return 0;
    struct Lista_colleg *tmp;
    tmp=*testa;
    *testa=(*testa)->next;
    free(tmp);
    return 1;
}

int DeleteLast_link(struct Lista_colleg **testa)
{
    if(*testa==NULL) return 0;

    struct Lista_colleg *tmp;
    struct Lista_colleg *prec;
    prec=NULL;
    tmp=*testa;
    while(tmp->next!=NULL)
    {
        prec=tmp;
        tmp=tmp->next;
    }
    if(prec==NULL)
    {
        *testa=NULL;
        free(tmp);
    }
    else
    {
        prec->next=NULL;
        free(tmp);
    }
    return 1;

}

int Delete_link(struct Lista_colleg **testa, int elem_dacercare)
{
    if(*testa==NULL)
    {
        return 0;
    }

    struct Lista_colleg *tmp;
    struct Lista_colleg *prec=NULL;
    tmp=*testa;
    while(tmp!=NULL)
    {
        if(tmp->num==elem_dacercare)
        {
            if(prec==NULL)
            {
                *testa=(*testa)->next;
                free(tmp);
                return 1;
            }
            else
            {
                prec->next=tmp->next;
                free(tmp);
                return 1;

            }
        }
        prec=tmp;
        tmp=tmp->next;
    }
    return 1;
}
