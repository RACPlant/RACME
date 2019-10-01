#include <Arduino.h>
#include "RACSensor.h"

RACSensor::RACSensor(int pin, String name){
    pinMode(pin, INPUT);
    _pin = pin;
    _i = -1;
    _name = name;
}

void RACSensor::addMeasure(){
    _i = _i == SENSOR_MEMORY - 1 ? 0 : _i+1;
    _values[_i] = analogRead(_pin);

    if(shouldSendValues()){
        Serial.println(mean());
    }
}

float RACSensor::mean(){
    float sum = 0.0;
    for(int i = 0; i<= _i; i++){
        sum = sum + _values[i];
    }
    return sum / (_i + 1);
}

bool RACSensor::shouldSendValues(){
    return  _i == SENSOR_MEMORY - 1 ? true:false;
}
