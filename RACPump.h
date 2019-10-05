#ifndef RACPump_h
#define RACPump_h

#include <Arduino.h>
#include "RACProtocol.h"

class RACPump
{
private:
    int pumpPin;
public:
    String pumpId; 
    RACPump(int pin, String pump);
    void water(int timeSeconds);
};

#endif
