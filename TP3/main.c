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
    }
    return 0;
}

int main(){
    int LONGUEUR = 15;
    int largeur = afficherPointeHaut(LONGUEUR);
    afficherPointesCotey(largeur);
}