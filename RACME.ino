#include "RACMonitor.h"
#include "RACSensor.h"
#include "RACProtocol.h"
#include "RACExecutor.h"
#include "RACPump.h"

RACSensor s1(0, "H");
RACSensor s2(1, "R");

RACPump pump1(2, "p1");
RACPump pump2(3, "p2");

RACProtocol* p = new RACProtocol();

RACExecutor executor("arduino_1", 6, p);
RACMonitor monit("arduino_1", 6, p);

void setup() {

  Serial.begin(9600);
  monit.addSensor(&s1);
  monit.addSensor(&s2);

  executor.addPump(&pump1);
  executor.addPump(&pump2);

}

void loop() {

  s1.addMetric();
  s2.addMetric();

  String msg = p->readInput();

  if(msg == "getMetrics"){
      monit.sendMetrics();
  }

  if(msg.startsWith("water:")){
    executor.processPlan(msg);
  }

  
}
