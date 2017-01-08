

#include <stdlib.h>
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <wiring.h>
#endif
#include <math.h>

class SinGen {
  public:
    SinGen(uint8_t pinYuksekPWM = 3, uint8_t pinAlcakPWM = 5, double HzFrekans = 1  );
    void run();
    void init();

  private:
    double modifeMap(double x, double in_min, double in_max, double out_min, double out_max);
    uint8_t _pin[2];
    unsigned long _zamanAraligi;
    unsigned long _sonZamanAraligi;
    unsigned long _ilkZaman;
    double alfa;
    unsigned long zaman;
    long gen;
};


