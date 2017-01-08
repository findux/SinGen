# SinGen
SinGen Arduino 3,5,6,9,10 ve 11. PWM çıkışlarını kullanarak sinüs sinyali üreten arduino kütüphanesidir.
Örneğin;

#include "SinGen.h"
SinGen faz1(3,5,0.2); // SinGen(pin0 , pin1 , frekans(Hz)); 
void setup() {


  faz1.init();
}

void loop() {
  faz1.run();
}
