#include "RACMonitor.h"
#include "RACSensor.h"
#include "RACProtocol.h"
#include "RACExecutor.h"
#include "RACPump.h"


//ETo
RACSensor r_sensor(0, "e1");
RACSensor t_sensor(1, "e2");

//Plants
RACSensor p1(2, "h1");
RACSensor p2(3, "h2");
RACSensor p3(4, "h3");
RACSensor p4(5, "h4");

//Pumps
RACPump pump1(0, "p1");
RACPump pump2(1, "p2");
RACPump pump3(2, "p3");
RACPump pump4(3, "p4");

RACProtocol* p = new RACProtocol();

RACExecutor executor("arduino_1", 10, p);
RACMonitor monit("arduino_1", 10, p);

void setup() {

  Serial.begin(2400);
    Serial.println("B");

//  ETo
  monit.addSensor(&r_sensor);
  monit.addSensor(&t_sensor);

      Serial.println("C");


//Pants
  monit.addSensor(&p1);
  monit.addSensor(&p2);
  monit.addSensor(&p3);
  monit.addSensor(&p4);

        Serial.println("D");


//Pumps
  executor.addPump(&pump1);
  executor.addPump(&pump2);
  executor.addPump(&pump3);
  executor.addPump(&pump4);
        Serial.println("E");



}

void loop() {

  r_sensor.addMetric();
  t_sensor.addMetric();
  p1.addMetric();
  p2.addMetric();
  p3.addMetric();
  p4.addMetric();
  
  
  String msg = p->readInput();

  if(msg == "getMetrics"){
      monit.sendMetrics();
  }

  if(msg.startsWith("water:")){
    executor.processPlan(msg);
  }
    delay(1000);
  
}
