#define BLYNK_TEMPLATE_ID "YOUR BLYNK_TEMPLATE_ID" 
#define BLYNK_TEMPLATE_NAME "Accident Detection System" 
#define BLYNK_AUTH_TOKEN "YOUR BLYNK_AUTH_TOKEN" 
#define BLYNK_PRINT Serial 
 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
 
char ssid[] = "mobile_hotspot_name"; 
char pass[] = "hotspot_password"; 

#include <TinyGPS++.h> 
#include <SoftwareSerial.h> 
TinyGPSPlus gps;  // The TinyGPS++ object 
SoftwareSerial ss(D3, D4); // The serial connection to the GPS device 
int inc; 
float latitude , longitude; 
String date_str , time_str , lat_str , lng_str; 

#define vib_sen D5 
#define sw1_sen D6 
void setup(){ 
  pinMode(vib_sen,INPUT_PULLUP); 
  pinMode(sw1_sen,INPUT_PULLUP); 
  Serial.begin(9600); 
  ss.begin(9600); 
  Serial.println(); 
  Serial.println("Connecting to Network."); 
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
} 
 
void loop(){ 
  Blynk.run(); 
  while (ss.available() > 0) 
    if (gps.encode(ss.read())) 
    { 
      if (gps.location.isValid()) 
      { 
        latitude = gps.location.lat(); 
        lat_str = String(latitude , 6); 
        longitude = gps.location.lng(); 
        lng_str = String(longitude , 6); 
        Serial.print(lat_str);Serial.println(","+lng_str); 
//        Blynk.virtualWrite(V1,lat_str); 
//        Blynk.virtualWrite(V2,lng_str); 
      } 
      } 
  //Serial.print("SensorIn: ");Serial.println(digitalRead(vib_sen)); 
  if(digitalRead(vib_sen)==0){     
    Blynk.virtualWrite(V0,"Vibration Detected"); 
    while(1){ 
      inc++;Serial.print(inc);delay(1000); 
      if((inc<10 && digitalRead(sw1_sen)==0)){ 
        Blynk.virtualWrite(V3,"Safety Switch Pressed."); 
        Blynk.virtualWrite(V1," "); 
        Blynk.virtualWrite(V2," "); 
        Serial.println(F("Switch Break, Do NoT Send Location")); 
        inc = 0 ; 
        break; 
      } 
      if(inc>10){ 
        Serial.print(F("No Switch Input, Send Location, ")); 
        Serial.print(lat_str);Serial.println(","+lng_str); 
        Blynk.virtualWrite(V1,lat_str); 
        Blynk.virtualWrite(V2,lng_str); 
        Blynk.virtualWrite(V3,"Safety Switch Not Pressed."); 
        inc = 0; 
        break; 
      } 
    } 
    //end while 
  } 
  // end vib condition 
  delay(500); 
}
