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
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define BLUE 1
#define TRUE 1
#define FALSE 0
#define GPIO_0 = 0
#define GPIO_1 = 1
#define GPIO_2 = 2


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "0d36c3ea2c0b4f5cb4eee84f4c71e98e";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ian's Hotspot";
char pass[] = "11111111112222222222333333";

int virt_pin = 0;

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);

  Blynk.begin(auth, ssid, pass);
  
}

// setup the virtual pin
  BLYNK_WRITE(V1) // V1 the virtual pin
    {
      virt_pin = param.asInt();
    }


void loop()
{
  int status = 0;

  
  // Get GPIO_0 status and send to phone
  
  Blynk.run();
  status = digitalRead(0);
  if (status == 1)
    {
    Blynk.virtualWrite(V0, 0); // Button released
    }
    else
    {
    Blynk.virtualWrite(V0, 255); // button pressed
    }

  
  // Check the status of the virtual pin  
      
    if (virt_pin == HIGH ) // High is button pressed 
    {
      flashLed();
    }
    else
    {
      digitalWrite(BLUE,HIGH);   //Pin HIGH is LED off
    }
    //===================
    
}

void flashLed()
  {
  digitalWrite(BLUE, LOW);   // turn the LED on
  delay(1000);                       // wait for a second
  digitalWrite(BLUE, HIGH);    // turn the LED off
  delay(1000); 
  }
