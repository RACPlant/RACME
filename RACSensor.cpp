#include <Arduino.h>
#include "RACSensor.h"


RACSensor::RACSensor(int pin, String sId){
    pinMode(pin, INPUT);
    _pin = pin;
    sensorId = sId;

    for (int i=0;i<BUFFER_SIZE;i++){
      _values[i]=-1;
    }
    
}

void RACSensor::addMetric(){
    for (int i=0;i++;i<(BUFFER_SIZE - 1)){
      _values[i+1] = _values[i];
    }
    _values[0]=analogRead(_pin);
}

int* RACSensor::getMetrics(){
    return _values;
}
