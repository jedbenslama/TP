#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// medoc = nom, codemédicament, date de fabrication, date de péremption, prix unitaire en $, ventes, stock restant

// fonction pour tableau Tab de N=80 médicaments ; puis le trie suivant la date de péremption, en utilisant la méthode de tri à bulles

// date pour comparer deux dates plus tard, ca sera plus simple
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char nom[50];
    char code_medicament[20];
    Date date_fabrication;
    Date date_peremption;
    float prix_unitaire;
    int nb_ventes;
    int nb_stock_restant;
} Medicament;


int comparerDates(Date d1, Date d2) {
    if (d1.annee != d2.annee)
        return (d1.annee > d2.annee) ? 1 : -1;
    if (d1.mois != d2.mois)
        return (d1.mois > d2.mois) ? 1 : -1;
    if (d1.jour != d2.jour)
        return (d1.jour > d2.jour) ? 1 : -1;
    return 0;
}

void trierMedocs(Medicament** medicament, int nombre_medicaments){}; // implementer pseudo code

void afficherMedocs(Medicament** medicament, int nombre_medicaments){
    printf("Format de la date d'expiration: JJ/MM/AAAA\n");
    for (int i = 0; i < nombre_medicaments; i++){
        printf("%s - Expire le: %d/%d/%d\n", medicament[i]->nom, medicament[i]->date_peremption.jour, medicament[i]->date_peremption.mois, medicament[i]->date_peremption.annee);
    }
}

