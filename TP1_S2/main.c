#include <stdio.h>
#include "types.h"
#include <stdlib.h>
#include "functions.c"
#include <strings.h>

int main(){
    int rangees, tables;
    printf("Combien de rangees ?\n> ");
    scanf("%d",&rangees);
    printf("Combien de tables ?\n> ");
    scanf("%d",&tables);

    Place classe[rangees][tables];
    initTables(rangees, tables, classe);
    
    char file_content[5000];
    strcpy(file_content, readFile("liste.txt"));

    int nombre_eleves;
    char **eleves = splitLines(file_content, &nombre_eleves);

    float max = ((tables+1)/2)*rangees; // le nombre max d'élèves par rangée vaut tables+1/2, on le multiplie par rangees pour savoir le max par classe
    printf("%f", max);

    if(nombre_eleves<=max){
        //
    }
    
    return 1;
}