#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void afficherPointeHaut(LONGUEUR, SPACENUMBER){
    for(int i=0; i < LONGUEUR; i++){
        for(int j=0; j < SPACENUMBER-i; j++){
            printf(" ");
        }
        printf("A");
        for(int j=0; j < i*2; j++){
            printf("A");
        }
        printf("\n");
    }
}

int main(){
    int LONGUEUR = 5;
    int SPACENUMBER = 10;

        
    
}