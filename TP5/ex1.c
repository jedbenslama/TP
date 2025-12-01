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

int humeurBonbons(int valeur){
    if(valeur<=3){
        return 0;
    }else if(valeur<=7){
        return 1;
    }else if(valeur<=12){
        return 2;
    }else{
        return 3;
    }
}

int humeurLegumes(int valeur){
    if(valeur<=3){
        return 0;
    }else if(valeur<=7){
        return 1;
    }else{
        return 2;
    }
}

int humeurFruits(int valeur){
    if(valeur<=3){
        return 0;
    }else if(valeur<=7){
        return 1;
    }else{
        return 2;
    }
}

void afficherResume(int conso[7]){
    char tableau_humeur_bonbons[5][5]={"😇","🙂","😕","😈"};
    char tableau_humeur_legumes[5][5]={"😭","🙂","😎"};
    char tableau_humeur_fruits[5][5]={"😥","🙂","😄"};
    printf("======== Resume du jour ========\nEau      :\t%d 💧\n", conso[0]);
    printf("Cafe     :\t%d 🍵\n", conso[1]);
    printf("Bonbons  :\t%d 🍬 %s\n", conso[2], tableau_humeur_bonbons[humeurBonbons(conso[2])]);
    printf("Gateau   :\t%d 🍰\n", conso[3]);
    printf("Legumes  :\t%d 🥦 %s\n", conso[4], tableau_humeur_legumes[humeurLegumes(conso[4])]);
    printf("Fruits   :\t%d 🍎 %s\n", conso[5], tableau_humeur_fruits[humeurFruits(conso[5])]);
    printf("Proteines:\t%d 🍗\n", conso[6]);
    printf("===============================\n");
}

int charger(int conso[7]){
    FILE * fichier = fopen("consommation.txt","r");
    if(fichier==NULL){
        return 0;
    }
    if(fscanf(fichier, "%d %d %d %d %d %d %d", &conso[0], &conso[1], &conso[2], &conso[3], &conso[4], &conso[5], &conso[6]) == EOF){
        fclose(fichier);
        return 0;
    }

    return 1;
}

int sauvegarder(int conso[7]){
    FILE * fichier = fopen("consommation.txt","w");
    if(fprintf(fichier, "%d %d %d %d %d %d %d", conso[0], conso[1], conso[2], conso[3], conso[4], conso[5], conso[6]) == EOF){
        return 0;
    }
    return 1;
}

void initialiser(int conso[7]){
    for (int i = 0; i < 7; i++){
        conso[i]=0;
    }
}

int main()
{
    int conso[7];
    if(charger(conso)==1){
        printf("Session chargée\n");
    }else{
        printf("Aucune sauvegarde trouvée\n");
        initialiser(conso);
    };
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
                if(sauvegarder(conso)==0){
                    printf("Erreur lors de la sauvegarde\n");
                }else{
                    printf("Sauvegarde réussie.\n");
                };
                break;
            default:
                printf("Choix incorrect\n");
                break;
            }
    }
    return 0;
}
