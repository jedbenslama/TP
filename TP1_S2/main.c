#include "functions.c"

int main(){
    int nb_rangees, nb_tables_par_rangee;
    printf("Combien de rangees ?\n> ");
    scanf("%d",&nb_rangees);
    printf("Combien de tables ?\n> ");
    scanf("%d",&nb_tables_par_rangee);

    Place classe[nb_rangees][nb_tables_par_rangee];
    initTables(nb_rangees, nb_tables_par_rangee, classe);
    
    char file_content[5000];
    strcpy(file_content, readFile("liste.txt"));

    int nombre_eleves;
    char **eleves = splitLines(file_content, &nombre_eleves);

    float max = ((nb_tables_par_rangee+1)/2)*nb_rangees; // le nombre max d'élèves par rangée vaut tables+1/2, on le multiplie par rangees pour savoir le max par classe
    
    int eleves_places=0;

    if(nombre_eleves>=max){
        randomDispositionUnSurDeux(nb_rangees, nb_tables_par_rangee, eleves, nombre_eleves, classe, &eleves_places);
        // placer le reste de maniere random
        afficherClasse(nb_rangees, nb_tables_par_rangee, classe);
    }else{
        // on les place de maniere random
        placesRandom(nb_rangees, nb_tables_par_rangee, classe, nombre_eleves, eleves);
        afficherClasse(nb_rangees, nb_tables_par_rangee, classe);
    }
    
    
    return 1;
}