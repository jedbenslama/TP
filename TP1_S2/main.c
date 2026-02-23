#include <stdio.h>
#include "types.h"
#include <stdlib.h>
#include "functions.c"
#include <strings.h>

int main(){
    int rangees;
    int tables;
    printf("Combien de rangees ?\n> ");
    scanf("%d",&rangees);
    printf("Combien de tables ?\n> ");
    scanf("%d",&tables);

    Place *classe[rangees-1][tables-1];
    
    char file_content[5000];
    strcpy(file_content, readfile("liste.txt"));

    int nombre_eleves;
    char **listedechar = splitlines(file_content, &nombre_eleves);
    
    return 1;
}