#ifndef RACSensor_h
#define RACSensor_h
#define SENSOR_MEMORY 100



class RACSensor
{
  public:
    RACSensor(int pin, String name);
    float mean();
    void addMeasure();
    bool shouldSendValues();
  private:
    String _name;
    int _pin;
    int _i;
    int _values[SENSOR_MEMORY];
};

#endif
