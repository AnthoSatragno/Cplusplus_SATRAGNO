#include"Lettre_Morse.hpp"
#include<Arduino.h>

Lettre_Morse::Lettre_Morse(){};         //On introduit le constructeur

String Lettre_Morse::texte = "Ceci 3st un te5t M0rse";
String Lettre_Morse::traduction_morse ="";       //On crée un string vide dans lequel on va stocker la traductiion de chaque caractères

char Lettre_Morse::latin[63] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0',' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
String Lettre_Morse::morse[63] = { ".-", "-...", "-.-." , "-..",".","..-.","--.","....","..",".---","-.-",".-..", "--", "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--",
"-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----",".",".-", "-...", "-.-." , "-..",".","..-.","--.",".","..",".---","-.-",".-..", "--", "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--",
"-..-","-.--","--.."};           //On crée un tableau regroupant la traduction de chaque caractère latin selon leur indice dans ce tableau

String Lettre_Morse::traduction_carac (char carac){
     int k =0;
     while (k < sizeof(latin) && carac!=latin[k]){k++;}          //On parcourt le tableau pour trouver le caractère à traduire
        if( k < sizeof(latin) ){return(morse[k]);}          //On selectionne la traduction morse du caractère correspondant d'indice k
        else {return("");}            //Si on ne trouve pas le caractère on ne renvoie rien
}

String Lettre_Morse::traduction_phrase(String phrase){ 
    Serial.println("Le texte à traduire est:\n");
    Serial.println(phrase);
    for(int i=0; i < phrase.length();i++){         //On parcourt toute la phrase à traduire
          if (traduction_carac(phrase[i])==""){traduction_morse = traduction_morse;}     //Si il n'existe pas de traduction, celle-ci reste inchangée
          else{traduction_morse += traduction_carac(phrase[i])+"...";}     /*On ajoute dans la chaine de caractère initialisée chaque caractère traduit un à un, avec un espacement
          ... entre chaque carcatère et ....... entre chaque mot*/
          
      }
    Serial.println("Le texte traduit en morse donne:\n");
    Serial.println(traduction_morse);     //On renvoie la traduction morse du texte dans le moniteur série
    
    return (traduction_morse);
    
        
}