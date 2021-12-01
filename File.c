#include<stdio.h>
#include <stdlib.h>
#include"File.h"

File F;
int nbrElement = 0; //nombre d'élément dans la file

//Fonction pleine()
int filevide(){
    int i = 0; //n'est pas vide
    if (nbrElement==0)
        i = 1; //est vide
    return i;
}

//Fonction pleine()
int filepleine(){
    int i = 0;    //N'est pas pleine
    if(nbrElement==T)
        i = 1;  //est pleine
    return i;
}

//Fonction inserer() : ici il s'agit d'une insertion en queue
void inserer(int y){
    if(filepleine()==0){
        //Si la file n'est pas pleine on insere un élément
        //Créaction de l'élément à inserer
        File L = malloc(sizeof(File));
        L->elt = y;
        L->next = NULL;
        if(filevide()==1)//Si la file est vide alors :

            F = L;
        else{    
            File Fo = F; //Sauvegade de la tête de file
            while(Fo->next!=NULL)
                Fo = Fo->next;
            Fo->next = L;
        }
        nbrElement++;
    }
    else//Dans le cas contraire on affiche un message d'erreur
        printf("Erreur : la file est deja pleine\n");
}

//Fonction retirer() : on retire l'élément quiest en tête de pile.
int retirer(){
    int result;
    if(filevide(F)==0){
        //si la file n'est pas vide on retire un élément 
        result = F->elt;
        File L = F; //Sauvegade de la tête de file
        F = F->next;
        L->next = NULL;
        free(L); //Libére la mémoire
        nbrElement--; //on effectue la décrémentation nombre d'élément dans la file
    }
   else //Dans le cas contraire on affiche un message d'erreur à l'utilisateur.
        printf("Erreur : la file est vide\n");
    return result;
}


//Fonction d'affichage()
void afficher(){
    if(!filevide()){ //si la file n'est pas vide on affiche les éléments qu'elle contient 
        File L = F; //Sauvegade de la tête de file
        while(L->next!=NULL){
            printf("[%d] <-  ", L->elt);
            L=L->next;
        }
        printf("[%d] \n", L->elt);
    }
    else //Dans le cas contraire on affiche un message à l'utilisateur.
        printf("La file ne contient aucun element!!!\n");
    
}

//Menu à 5 option 
void menu(){
   int choix, elt, choix2;

   /*Le menu doit être afficher au moins une fois et 
    se repéte tant que l'utilisateur ne décide pas de sortir de la boucle*/
  do{
        //Liste des options
        printf("\n-------------------MENU-------------------\n");
        printf("1.\tInserer\n");
        printf("2.\tRetirer\n");
        printf("3.\tEst Pleine\n");
        printf("4.\tEst Vide\n");
        printf("5.\tAfficher\n\n");
        printf("entrer votre choix : ");
        //Récupération du choix de l'utilisateur
        scanf("%d",&choix);
        //Exécution d'un bout de code en fonction du choix
        switch(choix){
            case 1:
                printf("quel element voulez vous inserer : ");
                scanf("%d",&elt);
                inserer(elt);
                break;
            case 2:
                
                if(!filevide()){
                    elt=retirer(F);
                    printf("l element retire est [%d]\n", elt);
                }    
                else
                    printf("Erreur : la file est vide\n");
                break;
            case 3:
                if(filepleine(F))
                    printf("la file est pleine\n");
                else
                    printf("le file n'est pas pleine\n");
                break;
            case 4:
                if(filevide(F))
                    printf("la file est vide\n");
                else
                    printf("la file n'est pas vide\n");
                break;
            case 5:
                afficher(F);
                break;
            default:
                printf("le choix est incorrect\n");
        }
        //On démande à l'utisateur s'il veut sortir du menu
        printf("voulez vous continuer (1-oui,0-non) : ");
        scanf("%d",&choix2);

    } while(choix2==1);//L'utilisateur doit saisir un nombre != 1pour quitter
}