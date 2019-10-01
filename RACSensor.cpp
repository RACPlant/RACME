#include <Arduino.h>
#include "RACSensor.h"


RACSensor::RACSensor(int pin, String sId){
    pinMode(pin, INPUT);
    _pin = pin;
    sensorId = sId;
    _value = -1;
}

void RACSensor::addMetric(){
    _value = analogRead(_pin);
}

float RACSensor::getMetric(){
    return _value;
}
