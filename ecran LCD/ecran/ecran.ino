#include <LiquidCrystal.h>

#define FIRST TRUE
int STATE=0;
int rank=0;
// LiquidCrystal(rs,enable,d4,d5,d6,d7)
LiquidCrystal lcd(11,10,5,4,3,2); //rw brancher sur gnd
void setup() {
  Serial.begin(9600);
  // Lancement de l'écran
  lcd.begin(40,4);
  lcd.setCursor(10,2);
  lcd.print("Demarrage du systeme");
  int i;
  for(i=0; i<3; i++){
    lcd.print(".");
    delay(2000);
  }
}

/**
 * Affiche le menu du logiciel
 */
void menu(){
  lcd.setCursor(10,0);
  lcd.print("Menu Principal");
}

void loop() {
  lcd.clear();
  if (STATE==0){
    menu();
    // Affecter les boutons poussoirs
    STATE=1;
  }
  else if (STATE==1){
    Serial.print(rank);
  }
  
}
