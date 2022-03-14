#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup(void) {
  tft.init();
  tft.setRotation(1);
}

void loop() {
  tft.fillScreen(TFT_BLACK); //background color
  tft.setCursor(0, 0, 2); //placement
  tft.setTextColor(TFT_RED);  tft.setTextSize(3); //font color and size
  tft.println("Capstone");
  tft.setTextColor(TFT_GREEN);  tft.setTextSize(2); //font color and size
  tft.println("First Test");
  tft.setTextColor(TFT_YELLOW);  tft.setTextSize(2); //font color and size
  tft.println("Geiger Counter");
  while(1) yield(); // We must yield() to stop a watchdog timeout.
}
