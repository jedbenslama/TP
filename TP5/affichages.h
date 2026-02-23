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

void afficherMenu(){
    printf("========================\nSuivi de consommation\n========================\n1. Ajouter une consommation\n2. Afficher le resume du jour\n3. Afficher les objectifs et le score\n4. Choisir le resume d une date\n5. Sauvegarder et quitter\nVotre choix : ");
}

void afficherBarre(int valeur, int max){
    if(max<=0){
        max=1;
    }
    // ░█
    int casesPleines = (valeur*10)/max;
    for (int i = 1; i <= 10; i++)
    {
        if(i<casesPleines){
            printf("█");
        }else{
            printf("░");
        }
    }
    
}

void afficherResume(int conso[7], int objectifs[7]){
    char tableau_humeur_bonbons[10][10]={"😇","🙂","😕","😈"};
    char tableau_humeur_legumes[10][10]={"😭","🙂","😎"};
    char tableau_humeur_fruits[10][10]={"😥","🙂","😄"};
    printf("======== Resume du jour ========\nEau      :\t%d 💧\t", conso[0]);
    afficherBarre(conso[0],objectifs[0]);
    
    printf("\nCafe     :\t%d 🍵 ", conso[1]);
    afficherBarre(conso[1], objectifs[1]);
    
    printf("\nBonbons  :\t%d 🍬 %s ", conso[2], tableau_humeur_bonbons[humeurBonbons(conso[2])]);
    afficherBarre(conso[2], objectifs[2]);
    
    printf("\nGateau   :\t%d 🍰 ", conso[3]);
    afficherBarre(conso[3], objectifs[3]);
    
    printf("\nLegumes  :\t%d 🥦 %s ", conso[4], tableau_humeur_legumes[humeurLegumes(conso[4])]);
    afficherBarre(conso[4], objectifs[4]);
    
    printf("\nFruits   :\t%d 🍎 %s ", conso[5], tableau_humeur_fruits[humeurFruits(conso[5])]);
    afficherBarre(conso[5], objectifs[5]);
    
    printf("\nProteines:\t%d 🍗 ", conso[6]);
    afficherBarre(conso[6], objectifs[6]);
    
    printf("\n===============================\n");
}

void afficherObjectifsEtScore(int conso[7], int objectifs[7]){
    printf("\n====== Objectifs du jour ======\n");
    printf("Categorie     Objectif Atteint ?\n");
    
    printf("Eau      :\t   ");
    if(conso[0]>=objectifs[0]){
        printf("✅");
    }else{
        printf("❌");
    }
    printf("\n");

    printf("Cafe     :\t   (pas d objectif)\n");
    printf("Bonbons  :\t   (pas d objectif)\n");
    printf("Gateau   :\t   (pas d objectif)\n");

    printf("Legumes  :\t   ");
    if(conso[4]>=objectifs[4]){
        printf("✅");
    }else{
        printf("❌");
    }
    printf("\n");

    printf("Fruits   :\t   ");
    if(conso[5]>=objectifs[5]){
        printf("✅");
    }else{
        printf("❌");
    }
    printf("\n");

    printf("Proteines:\t   ");
    if(conso[6]>=objectifs[6]){
        printf("✅");
    }else{
        printf("❌");
    }
    printf("\n");
    printf("Score sante du jour : %d/100\n", calculerScoreSante(conso, objectifs));
    printf("============================\n\n");
}