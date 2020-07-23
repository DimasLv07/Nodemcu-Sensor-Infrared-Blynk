#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 char auth[] = "AuthTokenmu";
 char ssid[] = "NamaWifiMu";
 char pass[] = "PasswordWifiMu";

 WidgetLED led(V1);

 int sensor = D1; //YOU CAN CHOOSE OTHER PIN

void setup() {
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
 pinMode(sensor, INPUT);
 while(Blynk.connected() == false){
    Serial.println("Tidak terkoneksi");
  }
}
void loop() {
  
  int sensorval = digitalRead(sensor);
  Serial.println(sensorval);
  delay(2000);
if(sensorval == 1){
    led.on();
  }
if(sensorval == 0){
    led.off();
  }
Blynk.run();
}
