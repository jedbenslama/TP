#include <stdio.h>

char *readfile(char filename[50]){
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