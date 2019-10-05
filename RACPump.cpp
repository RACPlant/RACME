#include "RACPump.h"

RACPump::RACPump(int pin, String pump){
    pumpPin = pin;
    pumpId = pump;
    pinMode(pin,OUTPUT);
}

void RACPump::water(int timeSeconds){
    digitalWrite(pumpPin,HIGH);
    delay(timeSeconds*1000);
    digitalWrite(pumpPin,LOW);
}
