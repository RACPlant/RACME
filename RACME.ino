#include "RACMonitor.h"
#include "RACSensor.h"

RACSensor s1(3, "H");
RACSensor s2(3, "T");
RACSensor s3(3, "B");
RACSensor s4(3, "J");

RACMonitor monit("arduino_1", 4);

void setup() {
  Serial.begin(9600);
  monit.addSensor(&s1);
  monit.addSensor(&s2);
  monit.addSensor(&s3);
  monit.addSensor(&s4);

  

}

void loop() {
  s1.addMetric();
  s2.addMetric();
  s3.addMetric();
  s4.addMetric();
  monit.sendMetrics();

  delay(10);
  

}
