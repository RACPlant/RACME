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
  int* metrics = sensors[i_sensor]->getMetrics();
  String sensor_id = sensors[i_sensor]->sensorId;
//  String message = arduinoId+","+sensor_id+","+String(metrics[0])+";";
String message = "";

  for(int i =0;i<BUFFER_SIZE;i++){
    message = message+arduinoId+","+sensor_id+","+String(metrics[i])+";";
//      Serial.println(arduinoId);
//      Serial.println(sensor_id);
//      Serial.println(metrics[i]);
//      Serial.println("=============");
      

  }
//  Serial.println("SensorId: "+ String(sensor_id));
//  Serial.flush();
//  Serial.println(message);
//  Serial.flush();
    return message;
}
