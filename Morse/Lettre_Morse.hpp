#include<Arduino.h>




class Lettre_Morse {
    
  public:
    
      Lettre_Morse();   //Constructeur

      static String texte;       //Texte en latin
      static String traduction_morse;    //Traduction de ce texte en morse
      String traduction_carac (char carac);             //On définit les deux méthodes qui vont traduire chaque carcactère puis la phrase entière en morse
      String  traduction_phrase( String phrase);
      
  private:

      static char latin[63];     //Tableau de scarcatèrees latin
      static String morse[63];     //Tableau des caractères morse
};