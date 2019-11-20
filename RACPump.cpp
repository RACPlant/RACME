#include "RACPump.h"

RACPump::RACPump(int pin, String pump){
    pumpPin = pin;
    pumpId = pump;
    pinMode(pin,OUTPUT);
    digitalWrite(pumpPin,HIGH);

}

void RACPump::water(int timeSeconds){
    digitalWrite(pumpPin,LOW);
    delay(timeSeconds*1000);
    digitalWrite(pumpPin,HIGH);
}
