# ESP-01-Initial-Tests
Initial test of Arduino loaded onto ESP-01 module

This is first working test of Arduino running on a ESP-01 After lots of experimentaion this now works.

Note: There are three methods of using the ESP-01, that I know of.

1)Generic out of the box, with a serial interface to an Arduino unit. E.G. Uno. Uses AT commands

2) Using the Arduino forum ESP8266 drivers. A go it along method. But all working on the ESP-01.

3) Using Blynk. This is the simplest.

My experiment uses (3).

Having modified a serial to USB driver board. Can now do direct downloads.

My ESP-01 board may not be an orginal  and therefore needed the extra pull up resisters.

This Sketch is very limited. Now need to look at power-down/interupts as a method to save power and make this battery powered.
