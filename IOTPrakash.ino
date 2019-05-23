/////////// **CODE TO DISPLAY TEMPERATURE AND HUMIDITY** ////////////

////including all required libraries//
#include <Adafruit_Sensor.h> //inncluding libarary for sensors
#include <DHT.h> //including library for DHT sensor
#include <DHT_U.h>

#define DHTTYPE DHT11

int buzzer = 12; ///arduino pin asign for buzzer
int ledBlue = 11; ///arduino pin asign for LED
//int temp; //variable to store final reading of temperature
int h; //variable to store final reading of humidity
int  DHTPIN=8 ;// Pin connected to DHT

DHT dht(DHTPIN, DHTTYPE); // Command to the DHT.h library


void setup() {
  
  // put your setup code here, to run once:
  dht.begin(); // Start the sensor  
  Serial.begin(9600); //Start the Serial Port at 9600 baud (default)
  pinMode(buzzer, OUTPUT);
  pinMode(ledBlue, OUTPUT);


}
void loop() {
  // put your main code here, to run repeatedly: 

  int h = dht.readHumidity(); //read humidity and store it to h variable
  
  int t = dht.readTemperature(); //read temperature and store it to t variable
  
//  temp = (t*9/5)+32; //converting degree celsius inti fahrenheit 

    ///condition to alert for high temperature and humidity /////
  if((t>=25) || (h>=60)){
    Serial.println("Temperature Or Humidity is high");
    Serial.println((String)"Temperature : " + t + (String)"°C");
    Serial.println((String)"Humidity : " + h + (String)"%");
    
    /////for loop for buzzer alert////   
    for(int i=0; i<3; i++){
    tone(buzzer,1000);
    delay(100);
    noTone(buzzer);
    delay(100); 
    }
    
    delay (5000);//time delay
    
  }
   ///condition to alert for low temperature and humidity /////
  else if((t<=20) || (h<=40)){
    Serial.println("Temperature Or Humidity is Low");
    Serial.println((String)"Temperature : " + t + (String)"°C");
    Serial.println((String)"Humidity : " + h + (String)"%");
    
    for(int i=0; i<3; i++){
    tone(buzzer,550);
    delay(100);
    noTone(buzzer);
    delay(100);
    }
    
    delay (5000);
    
  }
   ///condition to alert for normal temperature and humidity /////
  else{
    Serial.println("Temperature and Humidity is Normal");
    Serial.println((String)"Temperature : " + t + (String)"°C");
    Serial.println((String)"Humidity : " + h + (String)"%");
    /////for loop for LED blink//// 
    for(int i=0; i<2; i++){
    digitalWrite(ledBlue, HIGH);
    delay(60);
    digitalWrite(ledBlue, LOW);
    delay(60);
  }
    delay (5000);
  }

}
