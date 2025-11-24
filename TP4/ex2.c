#include <stdio.h>
#include <stdlib.h>

void afficher_menu(){
    printf("\n=== BANQUE - DISTRIBUTEUR ===\n");
    printf("1 - Faire un retrait\n");
    printf("2 - Quitter\n");
}

int montant_valide(int montant){
    if(montant%5==0 && montant>=5 && montant <=1000){
        return 1;
    }else{
        printf("Erreur : montant invalide.\n");
        return 0;
    }
}

int saisir_montant(){
    int montant;
    printf("Montant a retirer : ");
    scanf("%i", &montant);
    while(1){
        if(montant_valide(montant)){
            break;
        }else{
            printf("Le montant doit etre entre 5 euros et 1000 euros, divisible par 5 : ");
            scanf("%i", &montant);
        }
    }
    return montant;
}

void calcul_distribution(int montant){
    int billets50 = 0, billets20 = 0, billets10 = 0, billets5 = 0;
    billets50 = (int)((float)montant / 50.0f);
    montant = montant % 50;

    billets20 = (int)((float)montant / 20.0f);
    montant = montant % 20;

    billets10 = (int)((float)montant / 10.0f);
    montant = montant % 10;

    billets5 = (int)((float)montant / 5.0f);
    montant = montant % 5;

    printf("\nBillets distribues :\n");
    if(billets50>0){
        printf("%d billets de 50\n", billets50);
    }
    if(billets20>0){
        printf("%d billets de 20\n", billets20);
    }
    if(billets10>0){
        printf("%d billets de 10\n", billets10);
    }
    if(billets5>0){
        printf("%d billets de 5\n", billets5);
    }
}

int main(){
    int choix;
    int montant;
    while(1){
        afficher_menu();
        printf("Votre choix : ");
        scanf("%i", &choix);
        while(choix!=1 && choix!=2){
            printf("Soit 1 soit 2 : ");
            scanf("%i", &choix);
        }
        switch (choix)
        {
        case 1:
            montant = saisir_montant();
            calcul_distribution(montant);
            break;
        
        case 2:
            return 0;
            break;
        }
    }
}
