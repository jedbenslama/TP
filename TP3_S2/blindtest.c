#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "header.c"

/* -------------------------------------------------- */
/* OUTILS SUR LES CHAINES                             */
/* -------------------------------------------------- */

/* Supprime les caractères de fin de ligne (\n ou \r) d'une chaîne */
void trim_newline(char *s) {
    size_t len = strlen(s);

    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[len - 1] = '\0';
        len--;
    }
}

/* 
Normalise une chaîne :
- supprime les espaces inutiles
- convertit en minuscules
Permet de comparer deux réponses sans tenir compte
des majuscules et des espaces.
*/
void normalize_string(char *dest, const char *src) {
    int i = 0;
    int j = 0;
    int prev_space = 0;

    while (src[i] != '\0' && isspace((unsigned char)src[i])) {
        i++;
    }

    while (src[i] != '\0') {
        unsigned char c = (unsigned char)src[i];

        if (isspace(c)) {
            prev_space = 1;
        } else {
            if (prev_space && j > 0) {
                dest[j++] = ' ';
            }
            dest[j++] = (char)tolower(c);
            prev_space = 0;
        }

        i++;
    }

    dest[j] = '\0';
}

/* 
Compare deux chaînes après normalisation.
Retourne 1 si elles sont équivalentes, sinon 0.
*/
int string_equals_normalized(const char *a, const char *b) {
    char na[256];
    char nb[256];

    normalize_string(na, a);
    normalize_string(nb, b);

    return strcmp(na, nb) == 0;
}

/* -------------------------------------------------- */
/* GESTION AUDIO                                      */
/* -------------------------------------------------- */

/*
Lance la lecture d'un extrait audio avec ffplay.
start = instant de départ
seconds = durée de l'extrait
*/
void play_song_excerpt_at(const char *filename, int start, int seconds) {
    char command[1024];

    snprintf(command, sizeof(command),
             "ffplay -nodisp -autoexit -loglevel quiet -ss %d -t %d \"%s\"",
             start, seconds, filename);

    system(command);
}

/*
Charge les morceaux depuis songs.txt dans un tableau.
Retourne le nombre de morceaux chargés.
*/
int charger_chansons(char filename[], Chanson *premierechanson) { // renommée pour mieux correspondre aux instructions de l'exo
    FILE *f;
    char line[3 * 256];
    int count = 0;

    f = fopen(filename, "r");
    if (f == NULL) {
        perror("Erreur ouverture songs.txt");
        return -1;
    }

    while (fgets(line, sizeof(line), f) != NULL && count < 100) {
        char *file;
        char *title;
        char *artist;

        trim_newline(line);

        if (strlen(line) == 0) {
            continue;
        }

        file = strtok(line, ";");
        title = strtok(NULL, ";");
        artist = strtok(NULL, ";");

        if (file == NULL || title == NULL || artist == NULL) {
            printf("Ligne ignoree dans songs.txt.\n");
            continue;
        }

        strcpy(premierechanson->path, file);
        strcpy(premierechanson->nom, title);
        strcpy(premierechanson->artiste, artist);
        premierechanson->suivant = malloc(sizeof(Chanson));
        premierechanson = premierechanson->suivant;

        count++;
    }

    fclose(f);
    return count;
}

void swap_chansons(int nombre_chansons, Chanson *premierechanson, int pos1, int pos2) {
    if (pos1 == pos2){
        return;
    }
    Chanson *chanson1;
    Chanson *chanson2;
    Chanson *current = premierechanson;

    for (int i = 0; i < nombre_chansons; i++) {
        if (i == pos1)
            chanson1 = current;
        if (i == pos2)
            chanson2 = current;
        current = current->suivant;
    }
    char tmp_path[100];
    char tmp_nom[100];
    char tmp_artiste[100];

    strcpy(tmp_path, chanson1->path);
    strcpy(tmp_nom, chanson1->nom);
    strcpy(tmp_artiste, chanson1->artiste);

    strcpy(chanson1->path, chanson2->path);
    strcpy(chanson1->nom, chanson2->nom);
    strcpy(chanson1->artiste, chanson2->artiste);

    strcpy(chanson2->path, tmp_path);
    strcpy(chanson2->nom, tmp_nom);
    strcpy(chanson2->artiste, tmp_artiste);
}

void melanger_chansons(int nombre_chansons, Chanson *premierechanson){
    for (int i = 0; i < nombre_chansons*5; i++){ // *5 pour bien mélanger après ça va pas changer grand chose
        int pos1 = rand() % (nombre_chansons-1);
        int pos2 = rand() % (nombre_chansons-1);
        if (pos1 == pos2){
            return;
        }
        Chanson *chanson1;
        Chanson *chanson2;
        Chanson *current = premierechanson;
    
        for (int i = 0; i < nombre_chansons; i++) {
            if (i == pos1)
                chanson1 = current;
            if (i == pos2)
                chanson2 = current;
            current = current->suivant;
        }
        char tmp_path[100];
        char tmp_nom[100];
        char tmp_artiste[100];
    
        strcpy(tmp_path, chanson1->path);
        strcpy(tmp_nom, chanson1->nom);
        strcpy(tmp_artiste, chanson1->artiste);
    
        strcpy(chanson1->path, chanson2->path);
        strcpy(chanson1->nom, chanson2->nom);
        strcpy(chanson1->artiste, chanson2->artiste);
    
        strcpy(chanson2->path, tmp_path);
        strcpy(chanson2->nom, tmp_nom);
        strcpy(chanson2->artiste, tmp_artiste);
    }
}

int charger_scores(char filename[], Joueur *premierjoueur) { // renommée pour mieux correspondre aux instructions de l'exo
    FILE *f;
    char line[3 * 256];
    int count = 0;

    f = fopen(filename, "r");
    if (f == NULL) {
        perror("Erreur ouverture scores.txt");
        return 0;
    }

    while (fgets(line, sizeof(line), f) != NULL && count < 100) {
        char *nom;
        int score;

        trim_newline(line);

        if (strlen(line) == 0) {
            continue;
        }

        nom = strtok(line, ";");
        score = atoi(strtok(NULL, ";"));

        if (nom == NULL || score == 0) {
            printf("Ligne ignoree dans scores.txt.\n");
            continue;
        }

        strcpy(premierjoueur->nom, nom);
        premierjoueur->score = score;
        premierjoueur->suivant = malloc(sizeof(Joueur));
        premierjoueur = premierjoueur->suivant;

        count++;
    }

    fclose(f);
    return count;
}

void update_score(int nombre_joueurs, Joueur *premierjoueur, char nomjoueur[], int newscore){
    Joueur *current = premierjoueur;
    for (int i = 0; i < nombre_joueurs; i++) {
        if(strcmp(nomjoueur, current->nom)==0){
            current->score = newscore;
        }
        current = current->suivant;
    }
}
void sauver_scores(char nomfichier[], int nombre_joueurs, Joueur *premierjoueur){
    FILE *f;
    f = fopen(nomfichier, "w");
    Joueur *current = premierjoueur;
    for (int i = 0; i < nombre_joueurs; i++) {
        fprintf(f, "%s;%d", current->nom, current->score);
        current = current->suivant;
    }
}
/* -------------------------------------------------- */
/* PROGRAMME PRINCIPAL                                */
/* -------------------------------------------------- */

int main() {
    srand(time(NULL));
    Chanson *premierechanson = malloc(sizeof(Chanson));
    int nombre_chansons = charger_chansons("songs.txt", premierechanson);
    Chanson *current = premierechanson;
    for (int i = 0; i < nombre_chansons; i++){
        printf("%s %s  \t%s\n", current->path, current->nom, current->artiste);
        current = current->suivant;
    }

    melanger_chansons(nombre_chansons, premierechanson);
    
    printf("\n");
    current = premierechanson;
    for (int i = 0; i < nombre_chansons; i++){
        printf("%s %s  \t%s\n", current->path, current->nom, current->artiste);
        current = current->suivant;
    }

    Joueur *premierjoueur = malloc(sizeof(Joueur));
    int initial_nombre_joueurs = charger_scores("scores.txt", premierjoueur);

    printf("\n");
    printf("Joueurs chargés: %d\n", initial_nombre_joueurs);
    Joueur *current_joueur = premierjoueur;
    for (int i = 0; i < initial_nombre_joueurs; i++){
        printf("Nom du joueur %d: %s\n", i+1, current_joueur->nom);
        current_joueur = current_joueur->suivant;
    }

    printf("\n");
    printf("Combien de NOUVEAUX joueurs voulez vous ?\n> ");

    int nombre_joueurs;
    scanf("%d", &nombre_joueurs);
    nombre_joueurs += initial_nombre_joueurs;
    getchar();

    current_joueur = premierjoueur;
    
    for (int i = 0; i < nombre_joueurs; i++){
        printf("Nom du joueur %d: > ", i+1);
        fgets(current_joueur->nom, 100, stdin);
        current_joueur->nom[strcspn(current_joueur->nom, "\n")] = '\0';
        current_joueur->suivant = malloc(sizeof(Joueur));
        current_joueur = current_joueur->suivant;
    }
    current_joueur = premierjoueur;
    printf("\n");
    for (int i = 0; i < nombre_joueurs; i++){
        printf("Nom du joueur %d: %s\n", i+1, current_joueur->nom);
        current_joueur = current_joueur->suivant;
    }

    current_joueur = premierjoueur;
    for (int i = 0; i < nombre_joueurs; i++){
        current = premierechanson;
        int current_score = 0;
        for (int j = 0; j < nombre_chansons; j++){
            int result = 0;
            play_song_excerpt_at(current->nom, rand() % 60,10);
            char current_essai[100];
            printf("Quel est le titre de la chanson ?\n> ");
            fgets(current_essai, 100, stdin);
            if (string_equals_normalized(current_essai, current->nom)){
                result = 1;
            }
            current_score += result;
            current = current->suivant;
        }
        if(current_joueur->score < current_score){
            current_joueur->score = current_score;
        }
        
        current_joueur = current_joueur->suivant;
    }
    

    return 0;
}