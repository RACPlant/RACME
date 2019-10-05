#include <Arduino.h>
#include "RACMonitor.h"


RACMonitor::RACMonitor(String aId, int n_max_sensors, RACProtocol* p){
    arduinoId = aId;
    max_sensors = max_sensors;
    i_sensors = -1;
    sensors =  (RACSensor**) malloc (max_sensors*sizeof(RACSensor));
    protocol = p;
}

void RACMonitor::sendMetrics(){
         String messages[i_sensors+1];
  for(int i=0; i<= i_sensors; i++){
    messages[i] = createMessage(i);
    }
  protocol->sendMessages(messages, i_sensors+1);
    
}

void RACMonitor::addSensor(RACSensor* sensor){
        i_sensors ++;
        sensors[i_sensors] = sensor;
    
}

String RACMonitor::createMessage(int i_sensor){
  String message = arduinoId+","+sensors[i_sensor]->sensorId+","+sensors[i_sensor]->getMetric();
    return message;
}
