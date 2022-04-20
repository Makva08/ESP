#include <LiquidCrystal.h>
 
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);
 
void setup() {
  lcd.begin(16, 2);  //number of columns and row
  lcd.print("HELLO WORLD");


  //Uncomment below, and you will get moving text
//  delay(1000);
//  lcd.clear();
//  lcd.setCursor(0,1);
//  lcd.print("Hello, World!");
//  delay(1000);
//  lcd.clear(); 

}
 
void loop() {
}

/*PIN01-VSS -> GND
PIN02-VDD -> 5V
PIN03 V0-> 10K Pot (Middle pin)
PIN04 RS->  GPIO19
PIN05 RW-> GND
PIN06  E  ->  GPIO23
PIN07 D0-> NOT USED
PIN08 D1-> NOT USED
PIN09 D2-> NOT USED
PIN10 D3-> NOT USED
PIN11 D4->  GPIO18
PIN12 D5->  GPIO17
PIN13 D6->  GPIO16
PIN14 D7->  GPIO15
PIN15 A-> 5V
PIN16 K-> GND */
