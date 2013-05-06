Arduino Leonardo USB Digital Joystick
=====================================

This code runs on an Arduino Leonardo allowing it to act as a USB 
digital joystick

Uses modified HID.cpp and USBAPI.h provided by "That Guy" at 
http://www.imaginaryindustries.com/blog/?p=80
(see instructions there for installation and use)

Developed for use with an Arduino Leonardo as it is able to act directly 
as a USB HID controller so doesn't require the Arduino firmware to 
be modified as some of the other Arduinos (eg. Uno) would do.

Connections as follows:

Arduino Pin					Function
-----------					----------------------------
6								Button 1
7								Button 2
8								Joystick Left
9								Joystick Up
10								Joystick Right
11								Joystick Down
GND							Button 1/2 and Joystick GND

Copyright Kevin Peat 2013
kevin 'at' kevinpeat.com
