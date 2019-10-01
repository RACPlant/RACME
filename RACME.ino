#include "RACMonitor.h"
#include "RACSensor.h"

RACSensor s1(0, "H");
RACSensor s2(1, "R");

RACMonitor monit("arduino_1", 6);

void setup() {
  Serial.begin(9600);
  monit.addSensor(&s1);
  monit.addSensor(&s2);

  

}

void loop() {
  s1.addMetric();
  s2.addMetric();
  monit.sendMetrics();

  delay(1000);
  

}
