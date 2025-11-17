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

int main(){
    int LONGUEUR = 10;
    printf("%d\n",afficherPointeHaut(LONGUEUR));
    
}