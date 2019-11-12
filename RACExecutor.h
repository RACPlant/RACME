#ifndef RACExecutor_h
#define RACExecutor_h

#include <Arduino.h>
#include "SerialProtocol.h"
#include "RACPump.h"

const int N_EXECUTORS=4;

class RACExecutor
{
private:
    RACPump* pumps[N_EXECUTORS];
    int i_pumps;
    SerialProtocol* protocol;
    RACPump* findPumpById(String id);
    String arduinoId;
public:
    RACExecutor(String aId, SerialProtocol* p );
    void waterById(int timeSeconds, String pump);
    void addPump(RACPump *p);
    void processPlan(String plan);
    void listPumps();
};

#endif
