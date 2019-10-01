#include <Arduino.h>
#include "RACMonitor.h"


RACMonitor::RACMonitor(String aId, int max_sensors){
    arduinoId = aId;
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

String RACMonitor::createMessage(int i_sensor){
  String message = arduinoId+","+sensors[i_sensor]->sensorId+","+sensors[i_sensor]->getMetric();
    return message;
}

void RACMonitor::sendMetrics(){
  for(int i=0; i<= i_sensors; i++){
    String message = createMessage(i);
    Serial.println(message);
    }
    
}
