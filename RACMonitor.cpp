#include <Arduino.h>
#include "RACMonitor.h"


RACMonitor::RACMonitor(String arduinoId, int max_sensors){
    arduinoId = arduinoId;
    max_sensors = max_sensors;
    i_sensors = -1;
     sensors =  (RACSensor**) malloc (max_sensors*sizeof(RACSensor));
}

RACMonitor::~RACMonitor(){
 
 }

void RACMonitor::addSensor(RACSensor* sensor){
        i_sensors ++;
        sensors[i_sensors] = sensor;
    
}

String RACMonitor::createMessage(){
  String message = "";
  for(int i = 0; i <= i_sensors; i++){
    message = message + sensors[i]->sensorId+"="+sensors[i]->getMetric()+";";
    }
    return message;
}

void RACMonitor::sendMetrics(){
    String message = createMessage();
    Serial.print(message);
}
