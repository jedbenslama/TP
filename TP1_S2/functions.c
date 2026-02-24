#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "types.h"

char *readFile(char filename[50]){
    FILE *fichier = fopen(filename,"r");
    if(fichier==NULL){
        printf("erreur lors de la lecture du fichier");
        exit(67);
    }
    
    
    
    static char file_content[3000]; // static car la memoire serait libérée apres l utilisation de la fonction
    size_t bytesRead;
    while ((bytesRead = fread(file_content, 1, sizeof(file_content) - 1, fichier)) > 0){
        file_content[bytesRead]='\0';
    }
    return file_content;
}

char **splitLines(const char text[], int *nombre_eleves) {
    size_t tailletext = strlen(text);
    int max_lines = 50;
    char **listedechar = malloc(max_lines * sizeof(char *));
    if (!listedechar) {
        return NULL;
    }

    char currline[50];
    int j = 0;
    int k = 0;
    for (int i = 0; i < tailletext; i++) {
      if (text[i] != '\n' && text[i] != '\0' && text[i] != '\r') {
        currline[j] = text[i];
        j++;
      } else {
        currline[j]='\0'; // \0 à la fin, c'est plus efficace que reinitialiser la variable
        listedechar[k] = malloc(strlen(currline) + 1);
        if (!listedechar[k]) {
          exit(67);
        }
        if(j>0){ // pour skip et ne pas ajouter de strings avec juste \n dedans etc
          strcpy(listedechar[k], currline); 
          k++;
        }
        j = 0;
        if (k >= max_lines){
          break;
        }
      }
    }
    
    *nombre_eleves = k;
    listedechar[k] = NULL; 
    return listedechar;
}

void initTables(int rangees, int tables, Place classe[rangees][tables]){
  for (int i = 0; i < rangees; i++){
    for (int j = 0; j < tables; j++){
      classe[i][j].rangee=i;
      classe[i][j].table=j;
      classe[i][j].occupee=0;
    }
  }
}

void definirPrenomNomEleve(char prenom[15], char nom[15], char fullname[30]){
  sscanf(fullname, "%s %s", prenom, nom);
}

void randomElevePasChoisi(int rangees, int tables, Place classe[rangees][tables], int nombre_eleves, char **eleves, char result[]){
  int searching = 1;
  while(searching){
    strcpy(result, eleves[rand() % nombre_eleves]);
    searching = 0;
    for (int i = 0; i < rangees; i++){
      for (int j = 0; j < tables; j++){
        if(classe[i][j].eleve.nomcomplet == result){
          searching = 1;
        }
      }
    }
  }
}

void placesRandom(int rangees, int tables, Place classe[rangees][tables], int nombre_eleves, char **eleves){
  int places_choisies=0;
  while(places_choisies<nombre_eleves){
    int x = rand() % rangees;
    int y = (rand() % rangees/2)*2;
    if(!classe[x][y].occupee){
      char eleve_random[50];
      randomElevePasChoisi(rangees, tables, classe, nombre_eleves, eleves, eleve_random);
      strcpy(classe[x][y].eleve.nomcomplet, eleve_random);
      definirPrenomNomEleve(classe[x][y].eleve.prenom, classe[x][y].eleve.nom, classe[x][y].eleve.nomcomplet);
      classe[x][y].occupee=1;
      places_choisies++;
    }
  }
  
}

int randomDispositionUnSurDeux(int rangees, int tables, char **eleves, int nombre_eleves, Place classe[rangees][tables], int *eleves_places) { // on return un int pour savoir il reste combien d'eleves
  int restant;
  for (int i = 0; i < rangees; i++){
    for (int j = 0; j < tables; j+=2){
      if(*eleves_places < nombre_eleves){
        char eleve_random[50];
        randomElevePasChoisi(rangees, tables, classe, nombre_eleves, eleves, eleve_random);
        strcpy(classe[i][j].eleve.nomcomplet, eleve_random);
        definirPrenomNomEleve(classe[i][j].eleve.prenom, classe[i][j].eleve.nom, classe[i][j].eleve.nomcomplet);
        classe[i][j].occupee=1;
        *eleves_places+=1;
        restant++;
      }
    }
  }
  return restant;
}

void afficherClasse(int rangees, int tables, Place classe[rangees][tables]){ // y a encore une erreur de formatage dans la fonction qui lit liste.txt je pense donc je peux pas encore afficher les noms de familles
  for (int i = 0; i < rangees; i++){
    for (int j = 0; j < tables; j++){
      if(classe[i][j].occupee){
        if(strlen(classe[i][j].eleve.prenom)>=4){
          printf("|   %s\t", classe[i][j].eleve.prenom);
        }else{
          printf("|   %s\t\t", classe[i][j].eleve.prenom);
        }
      }else{
        printf("|\tX\t");
      }
    }
    printf("\n");
  }
}