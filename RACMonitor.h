#ifndef RACMonitor_h
#define RACMonitor_h

#include "RACSensor.h"
#include "SerialProtocol.h"
#include <Arduino.h>
#include <DHT.h>

const int N_SENSORS=6;


class RACMonitor
{
  public:
    RACMonitor(String aId, SerialProtocol* protocol);
    void addSensor(RACSensor* sensor);
    void addTemperatureSensor(String tId, DHT* dht);
    void sendMetrics();
    void listSensors();
    void monit();
  private:
    String createMessage(int i_sensor, int i_metric);
    String arduinoId;
    int i_sensors;
    int max_sensors;
    SerialProtocol* protocol;
    RACSensor * sensors[N_SENSORS];
    DHT* dhtSensor;
    float temperatures[BUFFER_SIZE];
    String temperatureId;
};

#endif
