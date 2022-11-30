#include"Traducteur.hpp"
#include<Arduino.h>

Traducteur::Traducteur(){}; //On introduit le constructeur

void Traducteur::tiret(){    //On définit le temps d'allumage de la led pour traduire un tiret 
    
    digitalWrite(LED_BUILTIN,HIGH);   //On allume la LED
    Temps = millis();   //On définit un temps (temps actuel)
    while((millis()-Temps)<2000){digitalWrite(LED_BUILTIN,HIGH);}  //Tant que 2 secondes ne se sont pas écoulées, on garde la lED allumée
    while((millis()-Temps)<3000){digitalWrite(LED_BUILTIN,LOW);}  // dès que les 2s se sont écoulées, on éteint la led et on la rallume au bout de 0,5 sec
    
}

void Traducteur::point(){   //On définit le temps d'allumage de la led pour traduire un point (même principe que le tiret mais ici on attend seulement 1 sec)
    
    digitalWrite(LED_BUILTIN,HIGH);
    Temps = millis();
    while((millis()-Temps)<1000){digitalWrite(LED_BUILTIN,HIGH);}
    while((millis()-Temps)<1500){digitalWrite(LED_BUILTIN,LOW);}

}

void Traducteur::traduction_carac_clignotements(char carac_mor){  
        if ( carac_mor == '-') { tiret();}     //appel de la fonctiion tiret
        else if ( carac_mor == '.') {point();}    //appel de la fonction point
}

void Traducteur::traduction_phrase_clignotements(String phrase_mor){
      for(int j=0; j < phrase_mor.length();j++){     //On parcourt toute la phrase
            traduction_carac_clignotements(phrase_mor[j]); //On traduit chaque carcatère morse de la phrase en clignotements
}

}



