#ifndef RACMonitor_h
#define RACMonitor_h

#include "RACSensor.h"
#include "RACProtocol.h"
#include <Arduino.h>

const int N_SENSORS=6;
const int DALAY_BETWEEN_MESSAGES=1000;


class RACMonitor
{
  public:
    RACMonitor(String aId, RACProtocol* protocol);
    void addSensor(RACSensor* sensor);
    void sendMetrics();
  private:
    String createMessage(int i_sensor, int i_metric);
    String arduinoId;
    int i_sensors;
    int max_sensors;
    RACProtocol* protocol;
    RACSensor * sensors[N_SENSORS];
};

#endif
