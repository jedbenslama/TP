#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){
    int LONGUEUR = 5;
    int espaces_initiaux = 10;

    for(int i=0; i < LONGUEUR; i++){
        for(int j=0; j < espaces_initiaux-i; j++){
            printf(" ");
        }
        printf("A");
        for(int j=0; j < i*2; j++){
            printf("A");
        }
        printf("\n");
    }
    
}