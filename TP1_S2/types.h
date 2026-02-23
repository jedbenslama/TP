typedef struct Eleve{
    char prenom[15];
    char nom[15];
}Eleve;

typedef struct Place{
    int rangee;
    int table;
    int occupee;
    Eleve eleve;
}Place;