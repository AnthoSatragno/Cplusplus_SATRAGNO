#include<Arduino.h>


class Traducteur{

    public:
    
    Traducteur();  //Constructeur
   
    void tiret();     //Méthode tiret
    void point();     //Méthode point
    int Temps;
    void traduction_carac_clignotements(char carac_mor);  //Méthode pour traduire un caractère morse en clignotements
    void traduction_phrase_clignotements(String phrase_mor);  //Méthode pour traduire une phrase en morse en clignotements

    private :

};