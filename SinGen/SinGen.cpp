#include "SinGen.h"


SinGen::SinGen(uint8_t pinYuksekPWM = 3, uint8_t pinAlcakPWM = 5, double HzFrekans = 1  ){
  _pin[0] = pinYuksekPWM;
  _pin[1] = pinAlcakPWM;
  pinMode(_pin[0],OUTPUT);
  pinMode(_pin[1],OUTPUT);
  digitalWrite(_pin[0],0);
  digitalWrite(_pin[1],0);

  _zamanAraligi = 1000000 / HzFrekans; // frezkansımızı göre dalganın period zamanı hesaplandı 
  
}
void SinGen::run(){
  zaman = micros();// şu an ki zamanı aldık
  _sonZamanAraligi= (zaman-_ilkZaman) % _zamanAraligi;// bir period da gecen mevcut zaman ralığı
  alfa = modifeMap(_sonZamanAraligi,0,_zamanAraligi,0,2*PI);
  gen = sin(alfa)*255; // genliği hesaplanıyor -255 - +255 arasında bir değer geliyor

  if (alfa < PI){
    digitalWrite(_pin[1],0);
    analogWrite(_pin[0],gen);  
  }else{
    digitalWrite(_pin[0],0);
    analogWrite(_pin[1],-gen); // eksi gelen genliği artıya çevirildi
  }
  
  
}

void SinGen::init(){
  _ilkZaman=micros();
  _sonZamanAraligi=0;
  alfa=0;
}

double SinGen::modifeMap(double x, double in_min, double in_max, double out_min, double out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}



