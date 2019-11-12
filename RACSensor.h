#ifndef RACSensor_h
#define RACSensor_h


#include <Arduino.h>

const int BUFFER_SIZE = 10;

class RACSensor
{
  public:
    RACSensor(int pin, String sId);
    void addMetric();
    int* getMetrics();
    String sensorId;
  private:
    int _pin;
    int _values[BUFFER_SIZE];
};

#endif
