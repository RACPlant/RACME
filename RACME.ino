#include"RACSensor.h"

RACSensor hs(3, "H");

void setup() {
  Serial.begin(9600);

}

void loop() {
  hs.addMeasure();
  delay(10);
  

}
