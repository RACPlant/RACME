#include <Arduino.h>
#include "RACMonitor.h"


RACMonitor::RACMonitor(String aId, SerialProtocol* p){
    arduinoId = aId;
    max_sensors = max_sensors;
    i_sensors = -1;
    protocol = p;
}

void RACMonitor::sendMetrics(){
  for(int i=0; i<= i_sensors; i++){
    String messages[BUFFER_SIZE];
    for (int j=0;j<BUFFER_SIZE;j++){
      messages[j] = createMessage(i,j);
    }
      protocol->sendMessages(messages, BUFFER_SIZE);
  }
    
}

void RACMonitor::addSensor(RACSensor* sensor){
        i_sensors ++;
        sensors[i_sensors] = sensor;
    
}

void RACMonitor::listSensors(){
  String messages[i_sensors+1];
  for(int i=0;i<=i_sensors;i++){
    messages[i]=  sensors[i]->sensorId;
  }
  protocol->sendMessages(messages,i_sensors+1);  
}

String RACMonitor::createMessage(int i_sensor, int i_metric){
  String message = arduinoId+","+sensors[i_sensor]->sensorId+","+String(sensors[i_sensor]->getMetrics()[i_metric]);
    return message;
}
