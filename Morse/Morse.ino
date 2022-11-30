#include"Lettre_Morse.hpp"
#include"Traducteur.hpp"
#include<Arduino.h>

Lettre_Morse Lm;
Traducteur Tr;

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600);
delay(500);
Tr.traduction_phrase_clignotements(Lm.traduction_phrase(Lm.texte));

}

void loop() {
  // put your main code here, to run repeatedly:
}
