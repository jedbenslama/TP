typedef struct Chanson{
    char path[100];
    char nom[100];
    char artiste[100];
    struct Chanson *suivant;
}Chanson;

typedef struct Joueur{
    char nom[100];
    int score;
    struct Joueur *suivant;
}Joueur;