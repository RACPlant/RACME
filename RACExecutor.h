#ifndef RACExecutor_h
#define RACExecutor_h

#include <Arduino.h>
#include "RACProtocol.h"
#include "RACPump.h"

class RACExecutor
{
private:
    RACPump** pumps;
    int max_pumps;
    int i_pumps;
    RACProtocol* protocol;
    RACPump* findPumpById(String id);
    String arduinoId;
public:
    RACExecutor(String aId, int n_max_pumps, RACProtocol* p );
    void waterById(int timeSeconds, String pump);
    void addPump(RACPump *p);
    void processPlan(String plan);
};

#endif
