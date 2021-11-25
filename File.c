#include<stdio.h>
#include <stdlib.h>
#include"File.h"

File F;

//Fonction tailleF() qui retourne le nombre d'élément dans la file
int tailleF(){
    int s = 0; //Compteur
    File L=F;
    while (L!=NULL){
        //Tantque la pile pointe vers un élément on incrémente le compteur
        s++;
        L=L->next;
    }
    return s;
}

//Fonction pleine()
int filevide(){
    int i = 0; //n'est pas vide
    if (F==NULL)
        i = 1; //est vide
    return i;
}

//Fonction pleine()
int filepleine(){
    int i = 0;    //N'est pas pleine
    if(T==tailleF())
        i = 1;  //est pleine
    return i;
}

//Fonction inserer()
void inserer(int y){
    
    if(filepleine()==0){
        //Créaction de l'élément à inserer
        File L = malloc(sizeof(File));
        L->elt = y;
        L->next = NULL;
        if(filevide()==1)
            F = L;
        else{    
        //Sauvegade de la tête de file
            File Fo = F;
            while(Fo->next!=NULL)
                Fo = Fo->next;
            Fo->next = L;
        }
    }
}

//Fonction retirer()
int retirer(){
    int result;
    if(filevide(F)==0){
        result = F->elt;
        //Sauvegade de la tête de file
        File L = F;
        F = F->next;
        L->next = NULL;
        free(L);
    }
    return result;
}


//Fonction d'affichage()
void afficher(){
    if(!filevide()){
        File L = F; //Sauvegade de la tête de file
        while(L->next!=NULL){
            printf("[%d] <-  ", L->elt);
            L=L->next;
        }
        printf("[%d] \n", L->elt);
    }
    else{
        printf("Erreur : la file est vide!!!\n");
    }
}

//Menu à 5 option 
void menu(){
   int choix, elt, choix2;

   /*Le menu doit être afficher au moins une fois et 
    se repéte tant que l'utilisateur ne décide pas de sortir de la boucle*/
  do{
        //Liste des options
        printf("\n\nMENU\n");
        printf("1.Inserer\n");
        printf("2.Retirer\n");
        printf("3.Est Pleine\n");
        printf("4.Est Vide\n");
        printf("5.Afficher\n");
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
                elt=retirer(F);
                printf("l element retire est [%d]\n", elt);
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







