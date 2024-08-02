// pio project init --board uno

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
#include "TinyIRSender.hpp"

#define IR_OUTUPT 10
#define BUTTON_INUPT_PIN_1 2
#define BUTTON_INUPT_PIN_2 3
#define TEST_LED 9

void setup() { 
  pinMode(TEST_LED, OUTPUT); 
  pinMode(BUTTON_INUPT_PIN_1, INPUT); 
  pinMode(BUTTON_INUPT_PIN_2, INPUT); 
}

uint8_t sAddress = 0x02;
uint8_t sCommand1 = 0x34;
uint8_t sCommand2 = 0x32;
uint8_t sRepeats = 0;

void loop() {
  int button1Pressed = digitalRead(BUTTON_INUPT_PIN_1);
  int button2Pressed = digitalRead(BUTTON_INUPT_PIN_2);

  if(button1Pressed == HIGH) {
    sendNEC(IR_OUTUPT, sAddress, sCommand1, sRepeats);
  }

  if(button2Pressed == HIGH) {
    sendNEC(IR_OUTUPT, sAddress, sCommand2, sRepeats);
  }
    
  delay(10);
}
