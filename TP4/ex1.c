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

int saisirNombreEleves(){
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

void saisirNotes(int data[30][3], int nombre_eleves){
    for(int i=0; i<nombre_eleves; i++){
        printf("Eleve %i :\n",i+1);
        for(int j=0; j<3; j++){
            int note;
            printf("  Note du controle %i (0 a 20) : ", j+1);
            scanf("%d", &note);
            while(note < 0 || note > 20){
                printf("Veuillez saisir une note entre %d et %d : ", 0, 20);
                scanf("%d", &note);
            }
            data[i][j]=note;
        }
    }
}

void afficherNotes(int data[30][3], int nombre_eleves){
    printf("Tableau des notes\n");
    printf("Eleve\t C1\tC2\tC3\n");
    for(int i=0; i<nombre_eleves; i++){
        printf("\n    %d\t", i);
        for(int j=0; j<3; j++){
            printf("%d\t", data[i][j]);
        }
    }
}

float calculerMoyenneEleve(int data[30][3], int nombre_eleves){
    int indiceEleve;
    printf("Entrez l'indice de l'eleve (%d a %d): ", 1, nombre_eleves+1);
    scanf("%i", &indiceEleve);
    while(indiceEleve <= 0 || indiceEleve>nombre_eleves){
        printf("Entrez l'indice de l'eleve (%d a %d): ", 1, nombre_eleves+1);
        scanf("%i", &indiceEleve);
    }
    indiceEleve--;
    float moyenne_eleve = ((float)data[indiceEleve][0] + (float)data[indiceEleve][1] + (float)data[indiceEleve][2])/3.0f;
    printf("Moyenne de l'eleve%i: %f\n", indiceEleve, moyenne_eleve);
    return moyenne_eleve;
}

float calculerMoyenneGenerale(int data[30][3], int nombre_eleves){
    float diviseur=0;
    float dividende=0;
    for(int i=0; i<nombre_eleves; i++){
        for(int j=0; j<3; j++){
            dividende+=data[i][j];
            diviseur++;
        }
    }
    return dividende/diviseur;
}

int main(){
    
}