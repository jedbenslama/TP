typedef struct Eleve{
    char prenom[30];
    char nom[30];
    char nomcomplet[60];
}Eleve;

typedef struct Place{
    int rangee;
    int table;
    int occupee;
    Eleve eleve;
}Place;