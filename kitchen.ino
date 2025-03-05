#define BLYNK_TEMPLATE_ID "TMPL4VdliQyYR"
#define BLYNK_TEMPLATE_NAME "kuhinja"
#define BLYNK_AUTH_TOKEN "F7-60_IlPX7b4leHKEXTt-ziXMs7ASkV"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SPI.h>
#include <Wire.h>
#include "MQ135.h"
#include <Adafruit_MLX90614.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_GFX.h>

char auth[] = BLYNK_AUTH_TOKEN;    
char ssid[] = "Kuhinja";
char pass[] = "kuhinja123";

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#define relay_fan D5
#define relay_light D0
#define relay_fridge D7

 
#define buzzer_alarm D6
#define pir_human D3
//DHT dht(DHTPIN, DHTTYPE);
int alarm_status;
int pir_status = 0;
//double t;
//double h;
double temp_amb;
double temp_obj;
double calibration = 2.36;
void setup()
{
  Serial.begin(9600);
  //dht.begin(); 
  mlx.begin(); 
  Blynk.begin(auth, ssid, pass);
 
  pinMode(pir_human, INPUT);
  pinMode(buzzer_alarm, OUTPUT);
 
  pinMode(relay_fan, OUTPUT);
  pinMode(relay_light, OUTPUT);
  pinMode(relay_fridge, OUTPUT);
//  pinMode(relay_oven, OUTPUT);
 
  digitalWrite(buzzer_alarm, LOW);
 
  digitalWrite(relay_fan, HIGH);
  digitalWrite(relay_light, HIGH);
  digitalWrite(relay_fridge, HIGH);
//  digitalWrite(relay_oven, HIGH);
  delay(100);
}
BLYNK_WRITE(V0){
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(relay_fridge,LOW);  // Set digital pin 2 HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(relay_fridge,HIGH);  // Set digital pin 2 LOW    
  }
} 
 
void loop()
{
  Blynk.run();
  MQ135 gasSensor = MQ135(A0);
  float air_quality = gasSensor.getPPM();
  pir_status = digitalRead(pir_human);
  alarm_status = digitalRead(buzzer_alarm);
  temp_obj = mlx.readObjectTempC();
  temp_amb = mlx.readAmbientTempC();
  if (pir_status == 1)
  {
    Serial.println("Person Detected");
    digitalWrite(relay_light, LOW);
  }
  else if (pir_status == 0)
  {
    digitalWrite(relay_light, HIGH);
    Serial.println("No One in Room");
  }

  if (air_quality > 150)
  {
    digitalWrite(buzzer_alarm, HIGH);
    digitalWrite(relay_fan, LOW);
    Serial.println("Buzzer Status: ON");
    Serial.println("Exhaust Fan: ON");
  }
  else
  {
    digitalWrite(buzzer_alarm, LOW);
    digitalWrite(relay_fan, HIGH);
    Serial.println("Buzzer Status: OFF");
    Serial.println("Exhaust Fan: OFF");
  }
 
 
  Serial.print("Air Quality: ");
  Serial.print(air_quality);
  Serial.println(" PPM");
 
  Serial.print("Object temp = ");
  Serial.println(temp_obj);

  Serial.print("Room Temp = ");
  Serial.println(temp_amb);

  Serial.println();
  Serial.println("****************************");
  Serial.println();
 
  Blynk.virtualWrite(V1, temp_amb);     //Temperature
  Blynk.virtualWrite(V3, air_quality);   // For Gas
  Blynk.virtualWrite(V4, alarm_status);  // For Alarm & Exhaust Fan
  Blynk.virtualWrite(V5, pir_status);    // For Human Detection
 
  delay(1500);
}