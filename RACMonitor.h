#ifndef RACMonitor_h
#define RACMonitor_h

#include "RACSensor.h"

class RACMonitor
{
  public:
    RACMonitor(String arduinoId, int n_max_sensors);
    ~RACMonitor();
    void addSensor(RACSensor* sensor);
    void sendMetrics();
  private:
    String createMessage();
    String arduinoId;
    int i_sensors;
    int max_sensors;
    RACSensor ** sensors;
};

#endif
