#ifndef RACExecutor_h
#define RACExecutor_h

#include <Arduino.h>
#include "RACProtocol.h"
#include "RACPump.h"

const int N_EXECUTORS=4;

class RACExecutor
{
private:
    RACPump* pumps[N_EXECUTORS];
    int i_pumps;
    RACProtocol* protocol;
    RACPump* findPumpById(String id);
    String arduinoId;
public:
    RACExecutor(String aId, RACProtocol* p );
    void waterById(int timeSeconds, String pump);
    void addPump(RACPump *p);
    void processPlan(String plan);
    void listPumps();
};

#endif
