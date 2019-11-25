#include "RACMonitor.h"
#include "RACSensor.h"
#include "SerialProtocol.h"
#include "RACExecutor.h"
#include "RACPump.h"


//#include <DHT.h>
//
//#define DHTPIN 7
//#define DHTTYPE DHT22   // Sensor DHT 22  (AM2302)
//


DHT dht(7, DHT22);

RACSensor s1(0, "r1");
RACSensor s2(1, "h1");
//RACSensor s3(0, "h2");
//RACSensor s4(0, "h3");
//RACSensor s5(0, "h4");

RACPump pump1(2, "p1");
//RACPump pump2(3, "p2");
//RACPump pump3(3, "p3");
//RACPump pump4(3, "p4");


SerialProtocol* p = new SerialProtocol();

RACExecutor executor("0", p);
RACMonitor monit("0", p);

void setup() {
  Serial.begin(9600);
  monit.addSensor(&s1);
  monit.addSensor(&s2);
//  monit.addSensor(&s4);
//  monit.addSensor(&s5);

  executor.addPump(&pump1);
//  executor.addPump(&pump2);
//  executor.addPump(&pump3);
//  executor.addPump(&pump4);
  
   dht.begin();
   monit.addTemperatureSensor("t1", &dht);
}

void loop() {

  delay(2000);

  monit.monit();
  
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
