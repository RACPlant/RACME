#ifndef RACSensor_h
#define RACSensor_h



class RACSensor
{
  public:
    RACSensor(int pin, String sId);
    void addMetric();
    float getMetric();
    String sensorId;
  private:
    int _pin;
    int _value;
};

#endif
