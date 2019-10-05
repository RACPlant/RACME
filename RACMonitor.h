#ifndef RACMonitor_h
#define RACMonitor_h

#include "RACSensor.h"
#include "RACProtocol.h"
#include <Arduino.h>


class RACMonitor
{
  public:
    RACMonitor(String aId, int n_max_sensors, RACProtocol* protocol);
    void addSensor(RACSensor* sensor);
    void sendMetrics();
  private:
    String createMessage(int i_sensor);
    String arduinoId;
    int i_sensors;
    int max_sensors;
    RACProtocol* protocol;
    RACSensor ** sensors;
};

#endif
