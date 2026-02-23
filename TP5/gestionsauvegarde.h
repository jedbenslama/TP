#include <stdio.h>
#include <stdlib.h>

int charger(int conso[7]){
    FILE * fichier = fopen("consommation.txt","r");
    if(fichier==NULL){
        return 0;
    }
    if(fscanf(fichier, "%d %d %d %d %d %d %d", &conso[0], &conso[1], &conso[2], &conso[3], &conso[4], &conso[5], &conso[6]) == EOF){
        fclose(fichier);
        return 0;
    }

    return 1;
}

int sauvegarder(int conso[7]){
    FILE * fichier = fopen("consommation.txt","w");
    if(fprintf(fichier, "%d %d %d %d %d %d %d", conso[0], conso[1], conso[2], conso[3], conso[4], conso[5], conso[6]) == EOF){
        return 0;
    }
    return 1;
}

void initialiser(int conso[7]){
    for (int i = 0; i < 7; i++){
        conso[i]=0;
    }
}