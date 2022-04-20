#include "pitches.h"
#include "melody.h"
#include "Tone32.h"
#include <LiquidCrystal.h>

#define BUZZER_CHANNEL 0
const int buzzer = 22;
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

int tempo = 150; //// change this to make the melody slower or faster
int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;

String msg = "Rick Astley";
String msg2 = "Never gonna";

void setup(){
    lcd.begin(16, 2);  //number of columns and row 
}

void setup_buz() {
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } 
    else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }

    tone(buzzer, melody[thisNote], noteDuration * 0.9,BUZZER_CHANNEL);
    delay(noteDuration);
    noTone(buzzer, BUZZER_CHANNEL);
  }
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print(msg);
  lcd.setCursor(0,1);
  lcd.print(msg2);
  setup_buz();
}
