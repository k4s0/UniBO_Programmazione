/*
Autore : Casini Lorenzo
Inizio: 24/11/16
Modifica: 27/11/16
Versione: 1.3
*/
/*
Si scriva un programma C, adeguatamente commentato, che gestisca un certo numero di studenti iscritti ad un corso di laurea. Il programma utilizza un vettore di strutture, ognuna delle quali memorizza le informazioni di uno studente (numero matricola, nome e cognome, anno di immatricolazione, piano di studi). Il programma deve fornire la possibilit� di:

aggiungere un nuovo studente, stampando un messaggio di errore se lo studente � gi� presente (individuato dalla matricola) o se il vettore � pieno.
dato il numero di matricola, stampare le informazioni dello studente oppure un messaggio di errore se la matricola non � presente nel vettore
dato un numero di matricola, modificare le informazioni del piano di studi aggiungendo un voto oppure stampando un messaggio di errore se la matricola non � presente nel vettore.
Il piano di studi � un vettore di NUM_ESAMI elementi ognuno di tipo struttura contenete il nome dell'insegnamento e il voto corrispondente (0 se non sostenuto).
*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_ESAMI 2
#define MAX_STUDENTI 2
#define MAX_MATRICOLA 8

typedef struct {//struttura per i voti
    char nome_esame[30];
    int voto_esame;
}PIANODISTUDI;

typedef struct{//struttura per i dati degli studenti
    int matricola;
    char nome[30];
    char cognome[30];
    int anno_im;
    int indice_esami;
    PIANODISTUDI piano[NUM_ESAMI];
}UTENTE;

UTENTE stud[MAX_STUDENTI];//ecco il mio array di strutture


int main(){
    int i,j,y;
//qualche variabile fa sempre comodo

    char ripeti,scelta,str[100];
    int pos_studente=0;
    int controllo_matricola=0;
    int indice_esami=0;


    do{
            //stampo il menu del programma

        puts("\t\tBenvenuto Nel Gestionale Universitario, Cosa Vuoi Fare?\n");
        puts("\t1)Ricerca Tramite Matricola");
        printf("\t2)Inserire Nuovo Studente[Studenti Presenti %d su %d]\n",pos_studente,MAX_STUDENTI);
        puts("\t3)Inserisci Voto");
        puts("\t4)Esci Dal Programma\n");
        printf("Scelta==>");
        fflush(stdin);
        scanf("%d",&scelta);
        system("cls");
        switch(scelta){
        case 1:
            if(stud[0].matricola==0){//controllo che esistano degli studenti
                    if(pos_studente>=1){//controllo che nessuno abbia inserito matricole fasulle , non numerali
                            puts("Volevi Fare Il Furbo Inserendo Un Matricola Con Delle Lettere, Ora Io Mi Arresto!");
                            exit(0);

                    }else{
                        puts("Non Ci Sono Studneti All'Interno Del Gestionale, Inseriscili!");
                    }


            }else{
                printf("Inserisci Matricola Per Ricercare Studente:");
                fflush(stdin);
                scanf("%d",&controllo_matricola);
                //fgets(controllo_matricola,int,MAX_MATRICOLA);
                if(controllo_matricola>0&&controllo_matricola<=99999999){//controllo che la matricola sia numerica e di 8 cifre e positiva
                        int i;
                        for(i=0;i<=pos_studente;i++){

                            if(controllo_matricola==stud[i].matricola){//cerco nelle struct lo studente richiesto
                                //stampo i dati relativi alla matricola richiesta
                                    puts("\t\tDATI STUDENTE\n");
                                    printf("Matricola: %d\n",stud[i].matricola);
                                    printf("Nome: %s\n",stud[i].nome);
                                    printf("Cognome: %s\n",stud[i].cognome);
                                    printf("Anno Immatricolazione: %d\n",stud[i].anno_im);
                                    puts("\t\tPIANO DI STUDI STUDENTE\n");
                                    //stampo i dati richiesti dei vari esami della matricola richiesta
                                    for(j=0;j<stud[i].indice_esami;j++){
                                        printf("Esame: %s\n",stud[i].piano[j].nome_esame);
                                        printf("Voto: %d\n",stud[i].piano[j].voto_esame);

                                    }

                            }


                        }

                }else{
                    puts("Errore Input Errato!");
                }

            }
            break;
        case 2:
            if((pos_studente)==MAX_STUDENTI){//controllo sul numero massimo di studenti
                    puts("Numero Massimo Di Studenti Raggiunto.");

            }else{
                //memorizzo le info sugli studenti nelle struct
                puts("\t\tINFORMAZIONI STUDENTE\n");
                printf("Inserici Matricola Studente[MAX %d NUMERI]:",MAX_MATRICOLA);
                fflush(stdin);
                scanf("%d",&stud[pos_studente].matricola);
               // scanf("%[^0-9]%d",str,&stud[pos_studente].matricola);
                system("cls");
                puts("\t\tINFORMAZIONI STUDENTE\n");
                printf("Inserici Nome Studente:");
                fflush(stdin);
                scanf("%s",&stud[pos_studente].nome);
                system("cls");
                puts("\t\tINFORMAZIONI STUDENTE\n");
                printf("Inserici Cognome Studente:");
                fflush(stdin);
                scanf("%s",&stud[pos_studente].cognome);
                system("cls");
                puts("\t\tINFORMAZIONI STUDENTE\n");
                printf("Inserici Anno Immatricolazione Studente:");
                fflush(stdin);
                scanf("%d",&stud[pos_studente].anno_im);
                system("cls");
                puts("I DATI SONO STATI INSERITI CORRETTAMENTE");
                pos_studente++;
            }

            break;
        case 3:
                printf("Inserisci Matricola Alla Quale Assegnare Esame e Voto:");
                fflush(stdin);
                scanf("%d",&controllo_matricola);
                if(controllo_matricola>0&&controllo_matricola<=99999999){//contorllo che la matricola sia un numero di  8 cifre e positiva


                        for(y=0;y<=pos_studente;y++){
                                if(controllo_matricola==stud[y].matricola){//cerco lo studente nelle struct

                                        if(stud[y].indice_esami==NUM_ESAMI){//vedo se lo studente puo inserire ancora degli esami
                                            puts("Numero Massimo Di Esami Raggiunto!");
                                        }else{
                                            //memorizzo le informazioni sugli esami
                                            puts("\t\tPIANO DI STUDI\n");
                                            printf("Inserisci Nome Dell'Esame:");
                                            fflush(stdin);
                                            scanf("%s",&stud[y].piano[stud[y].indice_esami].nome_esame);

                                            printf("%s",stud[y].piano[stud[y].indice_esami].nome_esame);


                                            system("cls");


                                            puts("\t\tPIANO DI STUDI\n");
                                            printf("Inserisci Voto Dell'Esame:");
                                            fflush(stdin);
                                            scanf("%d",&stud[y].piano[stud[y].indice_esami].voto_esame);

                                            printf("%d",stud[y].piano[stud[y].indice_esami].voto_esame);


                                            system("cls");
                                            puts("I DATI SONO STATI INSERITI CORRETTAMENTE");

                                            stud[y].indice_esami++;
                                            controllo_matricola=0;
                                            break;

                                        }

                                }else{
                                    system("cls");
                                    puts("Matricola Non Esistente!");
                                }

                        }

                }else{
                    puts("Errore Input Errato!");
                }

            break;
        case 4:
            exit(0);
            break;
        default:
            puts("Inserisci Un Opzione Corretta!");
            break;
        }
        printf("Vuoi Tornare Al Menu'?(Y|N): \n");//chiedo all'utente se vuole rieseguire il programma
        fflush(stdin);
        scanf("%c",&ripeti);
        system("cls");


    }while(ripeti=='y'|| ripeti=='Y');


    return 0;
}
