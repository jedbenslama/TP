#include <stdio.h>
#include <stdlib.h>

void afficherMenu(){
    printf("===== GESTION DE VOTES =====\n");
    printf("1. Saisir le nombre d'eleves\n");
    printf("2. Saisir les notes des eleves\n");
    printf("3. Afficher toutes les notes\n");
    printf("4. Afficher la moyenne d'un eleve\n");
    printf("5. Afficher la moyenne generale\n");
    printf("6. Afficher la meilleure note de chaque controle\n");
    printf("0. Quitter\n");
}

int lireChoix(){
    printf("Votre choix : ");
    int choix;
    scanf("%d", &choix);
    return choix;
}

int saisirNombreEleves(){ // les commits de l'étape 1,2 et 3 sont presque tous faits au meme temps parce que j'ai oublié de commit et je viens de faire beaucoup de ctrl-z et ctrl-y pour pouvoir commit les etapes dans l'ordre
    int nombre_saisi = 0;
    while(nombre_saisi > 30 || nombre_saisi < 1){
        printf("Entrez le nombre d'élèves (1 a 30) : ");
        scanf("%d", &nombre_saisi);
        if(nombre_saisi <= 30 || nombre_saisi >= 1){
            return nombre_saisi;
        }
        printf("Valeur invalide\n");
    }
}

int main(){
    
}