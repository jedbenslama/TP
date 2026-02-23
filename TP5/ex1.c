#include "gestionsauvegarde.h"
#include <time.h>
#include "humeurs.h"
#include "affichages.h"

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

int calculerScoreSante(int conso[7], int objectifs[7]){
    int score_de_base=50;
    if(conso[0]>=objectifs[0]){
        score_de_base+=10;
    }
    if(conso[4]>=objectifs[4]){
        score_de_base+=10;
    }
    if(conso[5]>=objectifs[5]){
        score_de_base+=10;
    }
    if(conso[6]>=objectifs[6]){
        score_de_base+=10;
    }
    if(conso[2]>5){
        for (int i = 0; i < conso[2]; i++){
            if(i <= 15){
                score_de_base++;
            }else{
                break;
            }
        }
    }
    if(conso[1]>3){
        for (int i = 0; i < conso[1]; i++){
            if(i <= 20){
                score_de_base++;
            }else{
                break;
            }
        }
    }
    return score_de_base;
}

int main()
{
    int conso[7];
    int objectifs[]={8,0,0,0,5,3,2};
    if(charger(conso)==1){
        printf("Session chargée\n");
    }else{
        printf("Aucune sauvegarde trouvée\n");
        initialiser(conso);
    };
    int choice = -1;
    while(1){
        printf("\n");
        afficherMenu();
        printf("\n");
        choice=getUserChoice();
        switch (choice){
            case 1:
                ajouterConsommation(conso);
                break;
            case 2:
                afficherResume(conso, objectifs);
                break;
            case 3:
                afficherObjectifsEtScore(conso, objectifs);
                break;
            case 5:
                if(sauvegarder(conso)==0){
                    printf("Erreur lors de la sauvegarde\n");
                }else{
                    printf("Sauvegarde réussie.\n");
                };
                return 0;
                break;
            default:
                printf("Choix incorrect\n");
                break;
            }
    }
    return 0;
}
