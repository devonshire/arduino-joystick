/* 
* -------------------------------------------------------------------------
* Digital Joystick Code
* -------------------------------------------------------------------------
* Copyright Kevin Peat 2013
* kevin@kevinpeat.com
* This code module is licensed public domain
* -------------------------------------------------------------------------
* Uses modified HID.cpp and USBAPI.h provided by "That Guy"
* at http://www.imaginaryindustries.com/blog/?p=80
* -------------------------------------------------------------------------
*/

// Pin definitions
const int BUT1_PIN = 6;
const int BUT2_PIN = 7;
const int LEFT_PIN = 8;
const int UP_PIN = 9;
const int RIGHT_PIN = 10;
const int DOWN_PIN = 11;
const int LED_PIN = 13;

// Previous states
boolean button1State = false;
boolean button2State = false;
boolean stickUp = false;
boolean stickDown = false;
boolean stickLeft = false;
boolean stickRight = false;

// Hold joystick state
JoyState_t joySt;

void setup()
{
  // Pin definitions
  pinMode(BUT1_PIN, INPUT);
  pinMode(BUT2_PIN, INPUT);
  pinMode(LEFT_PIN, INPUT);
  pinMode(UP_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);
  pinMode(DOWN_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // Use pull-up resistors
  digitalWrite(BUT1_PIN, HIGH);
  digitalWrite(BUT2_PIN, HIGH);
  digitalWrite(LEFT_PIN, HIGH);
  digitalWrite(UP_PIN, HIGH);
  digitalWrite(RIGHT_PIN, HIGH);
  digitalWrite(DOWN_PIN, HIGH);

  // Set joystick initial state
  joySt.xAxis = 127;
  joySt.yAxis = 127;
  joySt.zAxis = 127;
  joySt.xRotAxis = 0;
  joySt.yRotAxis = 0;
  joySt.zRotAxis = 0;
  joySt.throttle = 0;
  joySt.rudder = 0;
  joySt.hatSw1 = 0;
  joySt.hatSw2 = 0;
  joySt.buttons = 0;
}

void loop()
{
  // Button 1 pressed
  if (!button1State && digitalRead(BUT1_PIN) == LOW)
  {
    button1State = true;
    joySt.buttons = joySt.buttons | 1;
  }

  // Button 1 released
  if (button1State && digitalRead(BUT1_PIN) == HIGH)
  {
    button1State = false;
    joySt.buttons = joySt.buttons & 254;
  }

  // Button 2 pressed
  if (!button2State && digitalRead(BUT2_PIN) == LOW)
  {
    button2State = true;
    joySt.buttons = joySt.buttons | 2;
  }    

  // Button 2 released
  if (button2State && digitalRead(BUT2_PIN) == HIGH)
  {
    button2State = false;
    joySt.buttons = joySt.buttons & 253;
  }

  // Joystick pressed up
  if (digitalRead(UP_PIN) == LOW)
  {
    stickUp = true;
    joySt.yAxis = 255;
  }

  // Joystick was up but no longer
  if (stickUp && digitalRead(UP_PIN) == HIGH)
  {
    stickUp = false;
    joySt.yAxis = 127;
  }

  // Joystick pressed right
  if (digitalRead(RIGHT_PIN) == LOW)
  {
    stickRight = true;    
    joySt.xAxis = 255;
  }

  // Joystick was right but no longer
  if (stickRight && digitalRead(RIGHT_PIN) == HIGH)
  {
    stickRight = false;
    joySt.xAxis = 127;
  }

  // Joystick pressed down
  if (digitalRead(DOWN_PIN) == LOW)
  {
    stickDown = true;
    joySt.yAxis = 0;
  }

  // Joystick was down but no longer
  if (stickDown && digitalRead(DOWN_PIN) == HIGH)
  {
    stickDown = false;
    joySt.yAxis = 127;
  }

  // Joystick pressed left
  if (digitalRead(LEFT_PIN) == LOW)
  {
    stickLeft = true;
    joySt.xAxis = 0;
  }

  // Joystick was left but no longer
  if (stickLeft && digitalRead(LEFT_PIN) == HIGH)
  {
    stickLeft = false;
    joySt.xAxis = 127;
  }

  // Send joystick state
  Joystick.setState(&joySt);
}

