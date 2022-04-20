#include <LiquidCrystal.h>
 
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

String msg = "Rick Astley";
String text = "Never gonna give you up, Never gonna let you down, Never gonna run around and desert you";

void setup() {
  lcd.begin(16, 2);  //number of columns and row 
}

int lcdColumns=16;  //in lcd.begin first component is cols (columns) but program somehow did not understand it, so I had to create separate variable for columns

void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message; 
  } 
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}
 
void loop() {
  lcd.print(msg);
  scrollText(1, text, 250, lcdColumns); //by changing the third component, you can change the speed of scrolling
  
    //If you uncomment below, text will only be scrolled once, and then will disappear:
  //lcd.noDisplay();
}
