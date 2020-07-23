#include "DHT.h"
#define DHTPIN_1 2 // подсоединение 1го датчика через 1й пин
#define DHTPIN_2 3 // подсоединение 2го датчика через 3й пин

DHT dht1(DHTPIN_1, DHT11); // инициация 2го датчика //
DHT dht2(DHTPIN_2, DHT11); // инициация 1го датчика

void setup() {
  Serial.begin(9600);
  Serial.println("Начало работы датчика DHT11");
  dht1.begin(); //
  dht2.begin();
}
void loop() {
  delay(2000); // 2 секунды задержки
  //снимаем показатели с 1го датчика
  float h1 = dht1.readHumidity(); //Измеряем влажность
  float t1 = dht1.readTemperature(); //Измеряем температуру
  //снимаем показатели со 2го датчика
  float h2 = dht2.readHumidity(); //Измеряем влажность
  float t2 = dht2.readTemperature(); //Измеряем температуру

  //ВЫВОДИМ ВСЕ НА ЭКРАН
  if (isnan(h1) || isnan(t1)) { 
    Serial.println("Ошибка считывания с 1го датчика");
    //return;
  }
  else 
  {
    Serial.println("**Показатели с 1го датчика**");
    Serial.print("Влажность: ");
    Serial.print(h1);
    Serial.print(" %\t");
    Serial.println("Температура: ");
    Serial.print(t1);
    Serial.println(" *C "); //Вывод показателей на экран
  }

  if (isnan(h2) || isnan(t2)) { 
    Serial.println("Ошибка считывания со 2го датчика");
    //return;
  }
  else 
  {
    Serial.println("**Показатели со 2го датчика**");
    Serial.print("Влажность: ");
    Serial.print(h2);
    Serial.print(" %\t");
    Serial.println("Температура: ");
    Serial.print(t2);
    Serial.println(" *C "); //Вывод показателей на экран
  }

  Serial.println("\n\n\n"); 

}
