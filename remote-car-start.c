/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  This example shows how value can be pushed from Arduino to
  the Blynk App.

  NOTE:
  BlynkTimer provides SimpleTimer functionality:
    http://playground.arduino.cc/Code/SimpleTimer

  App project setup:
    Value Display widget attached to Virtual Pin V5
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define kontak 2
#define mars 0
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "blynk-token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wireless-ssid";
char pass[] = "wireless-password";

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V4, millis() / 1000);
  
  
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
BLYNK_WRITE(V1) // Push Button in the App
{
  int fast_start = param.asInt();

  if(fast_start == 1)
  { 
    digitalWrite(kontak,0);
    delay(1500);
    digitalWrite(mars,0);
    delay(750);
    digitalWrite(mars,1);
    
  }
}
BLYNK_WRITE(V2) // Push Button in the App
{
  int cold_start = param.asInt();

  if(cold_start == 1)
  { 
    digitalWrite(kontak,0);
    delay(7000);
    digitalWrite(kontak,1);
    delay(150);
    digitalWrite(kontak,0);
    delay(7000);
    digitalWrite(kontak,1);
    delay(150);
    digitalWrite(kontak,0);
    delay(7000);
    digitalWrite(mars,0);
    delay(4000);
    digitalWrite(mars,1);
  }

}

BLYNK_WRITE(V3) // Push Button in the App
{
  int fake = param.asInt();

  if(fake == 1)
  { 
    delay(250);
    digitalWrite(mars,0);
    delay(350);
    digitalWrite(mars,1);
    delay(350);
    digitalWrite(mars,0);
    delay(350);
    digitalWrite(mars,1);
    delay(750);
    digitalWrite(mars,0);
    delay(350);
    digitalWrite(mars,1);
    delay(350);
    digitalWrite(mars,0);
    delay(350);
    digitalWrite(mars,1);
  }

}
