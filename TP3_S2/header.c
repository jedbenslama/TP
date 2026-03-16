typedef struct Chanson{
    char path[100];
    char nom[100];
    char artiste[100];
    struct Chanson *suivant;
}Chanson;