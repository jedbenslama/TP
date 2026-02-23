#include <stdio.h>
#include "types.h"
#include <stdlib.h>
#include "functions.c"

int main(){
    int rangees;
    int tables;
    printf("Combien de rangees ?\n> ");
    scanf("%d",&rangees);
    printf("Combien de tables ?\n> ");
    scanf("%d",&tables);

    Place *classe[rangees-1][tables-1];
    
    printf("%s", readfile("liste.txt"));
    
    return 1;
}