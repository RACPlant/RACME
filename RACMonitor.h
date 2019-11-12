#ifndef RACMonitor_h
#define RACMonitor_h

#include "RACSensor.h"
#include "SerialProtocol.h"
#include <Arduino.h>

const int N_SENSORS=6;


class RACMonitor
{
  public:
    RACMonitor(String aId, SerialProtocol* protocol);
    void addSensor(RACSensor* sensor);
    void sendMetrics();
    void listSensors();
  private:
    String createMessage(int i_sensor, int i_metric);
    String arduinoId;
    int i_sensors;
    int max_sensors;
    SerialProtocol* protocol;
    RACSensor * sensors[N_SENSORS];
};

#endif
