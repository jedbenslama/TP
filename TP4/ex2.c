#include <stdio.h>
#include <stdlib.h>

void afficher_menu(){
    printf("=== BANQUE - DISTRIBUTEUR ===\n");
    printf("1 - Faire un retrait\n");
    printf("2 - Quitter\n");
}

int saisir_montant(){
    int montant;
    printf("Montant a retirer : ");
    scanf("%i", &montant);
    while(1){
        if(montant_valide(montant)){
            break;
        }else{
            printf("Le montant doit etre entre 5 euros et 1000 euros, divisible par 5.\n");
        }
    }
    return montant;
}

int montant_valide(int montant){
    if(montant%5==0 && montant>=5 && montant <=1000){
        return 1;
    }else{
        printf("Erreur : montant invalide.");
        return 0;
    }
}

int calcul_distribution(int montant){

}

int main(){
    int choix;
    while(1){
        afficher_menu();
        printf("Votre choix : ");
        scanf("%i", &choix);
        while(choix!=1 && choix!=2){
            printf("Soit 1 soit 2\n> ");
            scanf("%i", &choix);
        }
        switch (choix)
        {
        case 1:
            int montant = saisir_montant();
            break;
        
        case 2:
            break;
        }
    }
    return 0;
}
