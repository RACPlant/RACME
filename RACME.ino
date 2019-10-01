#include"RACSensor.h"

RACSensor hs(3, "Humidade");

void setup() {
  Serial.begin(9600);

}

void loop() {
  hs.addMeasure();
  delay(100);
  

}
