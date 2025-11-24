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
    afficherMenu();
    printf("Votre choix : ");
    int choix;
    scanf("%d", &choix);
    while(choix < 0 || choix > 6){
        printf("Veuillez saisir un choix correct\n> ");
        scanf("%d", &choix);
    }
    return choix;
}

int saisirNombreEleves(){
    int nombre_saisi = 0;
    while(nombre_saisi > 30 || nombre_saisi < 1){
        printf("Entrez le nombre d'élèves (1 a 30) : ");
        scanf("%d", &nombre_saisi);
        if(!(nombre_saisi <= 30 || nombre_saisi >= 1)){
            printf("Valeur invalide\n");
        }
    }
    return nombre_saisi;
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
    printf("Eleve\tC1\tC2\tC3");
    for(int i=0; i<nombre_eleves; i++){
        printf("\n   %d\t", i);
        for(int j=0; j<3; j++){
            printf("%d\t", data[i][j]);
        }
    }
    printf("\n");
}

float calculerMoyenneEleve(int data[30][3], int indiceEleve){
    float moyenne_eleve = ((float)data[indiceEleve][0] + (float)data[indiceEleve][1] + (float)data[indiceEleve][2])/3.0f;
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

float trouverMeilleureNoteControle(int data[30][3], int nombre_eleves, int controle_index){
    float meilleure_note = 0.0f;
    for(int i=0; i<nombre_eleves; i++){
        if(data[i][controle_index] > meilleure_note){
            meilleure_note = data[i][controle_index];
        }
    }
    return meilleure_note;
}

void afficherMeilleuresNotes(int data[30][3], int nombre_eleves){
    for(int i=0; i<3; i++){
        printf("Meilleure note au controle %d : %f\n", i+1, trouverMeilleureNoteControle(data, nombre_eleves, i));
    }
}

int main(){
    int data[30][3];
    int nombre_eleves;
    while(1){
        int choix = lireChoix();
        switch (choix)
        {
        case 0:
            return 0;
            break;
        case 1:
            nombre_eleves = saisirNombreEleves();
            break;
        case 2:
            saisirNotes(data, nombre_eleves);
            break;
        case 3:
            afficherNotes(data, nombre_eleves);
            break;
        case 4:
            int indiceEleve;
            printf("Entrez l'indice de l'eleve (%d a %d): ", 1, nombre_eleves+1);
            scanf("%i", &indiceEleve);
            while(indiceEleve <= 0 || indiceEleve>nombre_eleves){
                printf("Entrez l'indice de l'eleve (%d a %d): ", 1, nombre_eleves+1);
                scanf("%i", &indiceEleve);
            }
            indiceEleve--;
            printf("Moyenne de l'eleve %i: %f\n", indiceEleve+1, calculerMoyenneEleve(data, nombre_eleves));
            break;
        case 5:
            printf("Moyenne generale de la classe: %f\n", calculerMoyenneGenerale(data, nombre_eleves));
            break;
        case 6:
            afficherMeilleuresNotes(data, nombre_eleves);
        default:
            break;
        }
    }
}