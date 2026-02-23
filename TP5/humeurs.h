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
    if(valeur<=1){
        return 0;
    }else if(valeur<=2){
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