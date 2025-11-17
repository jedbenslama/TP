#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int afficherPointeHaut(int longueur){
    int last_line;
    int spacenumber = (longueur-1)*3;
    for(int i=0; i < longueur; i++){
        if(i==longueur-1){
            for(int j=0; j < spacenumber-i; j++){
                printf("_");
            }
        }else{
            for(int j=0; j < spacenumber-i; j++){
                printf(" ");
            }
        }
        printf("A");
        for(int j=0; j < i*2; j++){
            printf("A");
        }
        if(i==longueur-1){
            for(int j=0; j < spacenumber-i; j++){
                printf("_");
            }
            last_line = spacenumber*2+1;
        }
        printf("\n");
    }
    return last_line;
}

int afficherPointesCotey(int largeur){
    int largeur_finale;
    for(int i=0; i<(int)((float)largeur/(float)2); i+=6){
        if(i>0){
            for(int j=0; j<i/2; j++){
                printf(" ");
            }
        }
        for(int j=0; j<largeur-i; j++){
            printf("A");
        }
        printf("\n");
        largeur_finale= largeur-i/2;
    }
    return largeur_finale;
}

int afficherBasEtoile(int largeur_actuelle, int largeur_totale, int longueur){
    int espaces = largeur_totale-largeur_actuelle;
    for(int i=0; i*2<espaces; i++){
        for(int j=0; j<espaces-i*2; j++){
            printf(" ");
        }

        for(int j=0; j<largeur_totale-2*(espaces-i*2); j++){
            if((j < (2*(espaces-i*2))) || (j>=(largeur_totale-2*(espaces-i*2))-2*(espaces-i*2))){
                printf("A");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

int main(){
    int longueur=0;
    while (longueur<5)
    {
        printf("Veuillez saisir un nombre supérieur à 5\n> ");
        scanf("%i",&longueur);
    }
    
    int largeur = afficherPointeHaut(longueur);
    int be=afficherBasEtoile(afficherPointesCotey(largeur), largeur, longueur);
}