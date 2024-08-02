// pio project init --board unh

// 
/**
 * -- THE TOOLBOX -- 
 *
 * What this project will be, I do not know.
 * But for now it will open a curtian in my toolbox.
 *
 */

// Project Creation: pio project init --board uno
// Project Upload: pio run --target upload

#include "Arduino.h"
#include <Servo.h>
#include "TinyIRReceiver.hpp"


#define IR_RECEIVE_PIN 2
#define SwitchPositionOnePin 4
#define SwitchPositionTwoPin 3
#define TEST_LED_1 8
#define TEST_LED_2 9

Servo myservo1;
Servo myservo2;
int servoPosition1;
int servoPosition2;

void setup()
{
  // Set button / switch input
  pinMode(IR_RECEIVE_PIN, INPUT);
  pinMode(SwitchPositionOnePin, INPUT);
  pinMode(SwitchPositionTwoPin, INPUT);
  pinMode(TEST_LED_1, OUTPUT);
  pinMode(TEST_LED_2, OUTPUT);

  // Set up servo #1
  pinMode(servoPosition1, OUTPUT);
  myservo1.attach(10);
  myservo1.write(90);

  // Setup servo #2
  pinMode(servoPosition2, OUTPUT);
  myservo2.attach(11);
  myservo2.write(95);

  // Initialize the IR receiver
  initPCIInterruptForTinyReceiver();
} 

void loop()
{
  // -- CURTAIN LOGICmmon as 
  if (TinyReceiverDecode()) {
    if (TinyIRReceiverData.Command == 0x34) {
      digitalWrite(TEST_LED_1, HIGH);
      servoPosition1 = 120;
      servoPosition2 = 65;
    } 
    if (TinyIRReceiverData.Command == 0x32) {
      digitalWrite(TEST_LED_2, HIGH);
      servoPosition1 = 60;
      servoPosition2 = 120;
    } 
  }
  myservo1.write(servoPosition1);
  myservo2.write(servoPosition2);

  // Delay and reset
  delay(80);
  digitalWrite(TEST_LED_1, LOW);
  digitalWrite(TEST_LED_2, LOW);
  servoPosition1 = 90;
  servoPosition2 = 95;
  myservo1.write(servoPosition1);
  myservo2.write(servoPosition2);
}

