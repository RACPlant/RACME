#include "RACMonitor.h"
#include "RACSensor.h"
#include "RACProtocol.h"
#include "RACExecutor.h"
#include "RACPump.h"

RACSensor s1(0, "T");
RACSensor s2(1, "R");

RACSensor s3(0, "H1");
RACSensor s4(0, "H2");
RACSensor s5(0, "H3");
RACSensor s6(0, "H4");

RACPump pump1(2, "p1");
RACPump pump2(3, "p2");
RACPump pump3(3, "p3");
RACPump pump4(3, "p4");

RACProtocol* p = new RACProtocol();

RACExecutor executor("arduino_1", p);
RACMonitor monit("arduino_1", p);

void setup() {

  Serial.begin(9600);
  monit.addSensor(&s1);
  monit.addSensor(&s2);
  monit.addSensor(&s3);
  monit.addSensor(&s4);
  monit.addSensor(&s5);
  monit.addSensor(&s6);

  executor.addPump(&pump1);
  executor.addPump(&pump2);
  executor.addPump(&pump3);
  executor.addPump(&pump4);

}

void loop() {

  s1.addMetric();
  s2.addMetric();
  s3.addMetric();
  s4.addMetric();
  s5.addMetric();
  s6.addMetric();



  String msg = p->readInput();

  if(msg == "getMetrics"){
      monit.sendMetrics();
  }

  if(msg.startsWith("water:")){
    executor.processPlan(msg);
  }

  if(msg == "listResources"){
    executor.listPumps();
    monit.listSensors();  
  }

  

  
}
