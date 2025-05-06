#include <Wire.h>    //Include wire library
#include <MPU6050_light.h>  //Include library for MPU communication
MPU6050 mpu(Wire);   //Create object mpu
#include "ThingSpeak.h"
#include <WiFi.h>
#include <WiFiClient.h>
unsigned long timer = 0;
#define FORCE_SENSOR_PIN 34
int a,f;
WiFiClient  client;  
unsigned long myChannelNumber = 2;

const char * myWriteAPIKey = "YOUR API KEY";
const char* ssid = "SSID";  // Enter SSID here
const char* password = "PASSWORD";  //Enter Password here

void setup() {

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);  
  ThingSpeak.begin(client);
  Serial.print("Initializing...");    //Start serial communication
  Wire.begin();    
  mpu.begin();    
  Serial.print(F("MPU6050 status: "));
  Serial.println(F("Calculating offsets, do not move MPU6050"));  
  delay(1000);
  mpu.calcGyroOffsets();     //Calibrate gyroscope
  Serial.println("Done!\n");
}
void loop() {
    mpu.update();
    Serial.println(int(mpu.getAngleZ()));
    int analogReading=analogRead(FORCE_SENSOR_PIN); //Print Z angle value on LCD
  // a=(int(mpu.getAngleZ()));
    //Serial.println(a);
   delay(500);
  if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password);
        delay(3000);    
      } }
       Serial.println("\nConnected.");

       
    //Get values from MPU
  f=analogRead(22);
  //f=(map(f,0,5090,0,1000));      
    delay(10);
   
    delay(10);


      ThingSpeak.setField(1,(int(mpu.getAngleZ())));
      ThingSpeak.setField(2, f);
      ThingSpeak.setField(3,analogReading);

    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    delay(1000);
   
   
 
}

