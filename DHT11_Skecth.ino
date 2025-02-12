//Board support ESP32

#include <SimpleTimer.h>
#include "DHT.h"
SimpleTimer timer;

#define pinData 23 
#define DHTTYPE DHT11
DHT dht(pinData, DHTTYPE);

float temp, hum;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
timer.setInterval(1000L, sistemDht);
}

void sistemDht()
{
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  if(isnan(temp) || isnan(hum))
  {
    return;
  }
  Serial.print("H");
  Serial.println(hum);
  Serial.print("T");
  Serial.println(temp);
}

void loop() {
  // put your main code here, to run repeatedly:
timer.run();
}
