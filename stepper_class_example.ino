#include "Stepper.h"

int orderSwitch = 36;

int noteArray[4] = { 68, 72, 75, 79 };

Stepper stepper1(4, 1000);

int tempoPot = { A13 };
int tempoPotValue = 0;
int mappedTempoPot = 0;


void setup() {
  Serial.begin(9600);
  stepper1.stepHandler(onStep);

  pinMode(orderSwitch, INPUT);
}

void loop() {
  tempoPotValue = analogRead(tempoPot);
  mappedTempoPot = map(tempoPotValue, 0, 1027, 100, 250);

  stepper1.process();
  stepper1.setTimePerStep(mappedTempoPot);
}

void onStep(int num) {

  if (digitalRead(orderSwitch) == HIGH) {
    usbMIDI.sendNoteOn(noteArray[num], 127, 1);
    Serial.println(num); }
  // } else if (digitalRead(orderSwitch) == LOW) {
  //   usbMIDI.sendNoteOn(noteArray[random(4)], 127, 1);
  //   Serial.println(num);
  // }
}
