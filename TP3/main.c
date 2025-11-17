#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int afficherPointeHaut(int LONGUEUR){
    int last_line;
    int spacenumber = (LONGUEUR-1)*3;
    for(int i=0; i < LONGUEUR; i++){
        if(i==LONGUEUR-1){
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
        if(i==LONGUEUR-1){
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

int afficherBasEtoile(int largeur_actuelle, int largeur_totale, int LONGUEUR){
    int espaces = largeur_totale-largeur_actuelle;
    for(int i=0; i*2<espaces; i++){
        for(int j=0; j<espaces-i*2; j++){
            printf(" ");
        }

        for(int j=0; j<largeur_totale-2*(espaces-i*2); j++){
            if((j <= (2*(espaces-i*2))) || (j>=(largeur_totale-2*(espaces-i*2))-2*(espaces-i*2))){
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
    int LONGUEUR = 15;
    int largeur = afficherPointeHaut(LONGUEUR);
    int largeur_actuelle=afficherPointesCotey(largeur);
    int be=afficherBasEtoile(largeur_actuelle, largeur, LONGUEUR);
    printf("%d", largeur_actuelle);
}