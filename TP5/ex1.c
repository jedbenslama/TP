#include <stdio.h>
#include <stdlib.h>

void afficherMenu(){
    printf("========================\nSuivi de consommation\n========================\n1. Ajouter une consommation\n2. Afficher le resume du jour\n3. Sauvegarder et quitter\nVotre choix : ");
}

int getUserChoice(){
    int choice;
    scanf("%d", &choice);
    return choice;
}

void initialiser(int conso[7]){
    for (int i = 0; i < 7; i++){
        conso[i]=0;
    }
}

void ajouterConsommation(int conso[7]){
    printf("Quelle catégorie voulez vous modifier\n");
    printf("1. Eau 💧\n");
    printf("2. Cafe 🍵\n");
    printf("3. Bonbons 🍬\n");
    printf("4. Gateau 🍰\n");
    printf("5. Legumes 🥦\n");
    printf("6. Fruits 🍎\n");
    printf("7. Proteines 🍗\nVotre choix : ");
    int choice1 = getUserChoice()-1;
    printf("Combien d unites ajouter ? ");
    int choice2 = getUserChoice();
    conso[choice1]+=choice2;
    printf("Consommation mise a jour\n");
}

void afficherResume(int conso[7]){
    printf("======== Resume du jour ========\nEau      :\t%d\n", conso[0]);
    printf("Cafe     :\t%d\n", conso[1]);
    printf("Bonbons  :\t%d\n", conso[2]);
    printf("Gateau   :\t%d\n", conso[3]);
    printf("Legumes  :\t%d\n", conso[4]);
    printf("Fruits   :\t%d\n", conso[5]);
    printf("Proteines:\t%d\n", conso[6]);
    printf("===============================\n");
}

void charger(){
    FILE * fichier = fopen("consommation.txt","r");
    // j'ai oublié de commit je commit maintenant
}

int main()
{
    int conso[7];
    initialiser(conso);
    int choice = -1;
    while(choice!=3){
        printf("\n");
        afficherMenu();
        printf("\n");
        choice=getUserChoice();
        switch (choice){
            case 1:
                ajouterConsommation(conso);
                break;
            case 2:
                afficherResume(conso);
                break;
            case 3:
                break;
            default:
                printf("Choix incorrect\n");
                break;
            }
    }
    return 0;
}
