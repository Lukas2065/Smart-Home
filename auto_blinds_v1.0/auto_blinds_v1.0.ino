#include <Stepper.h>

#define SWITCH_UPWARDS 2
#define SWITCH_DOWNWARDS 4 

Stepper myStepper(2048, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  
  pinMode(SWITCH_UPWARDS, INPUT_PULLUP);
  pinMode(SWITCH_DOWNWARDS, INPUT_PULLUP);
  
  myStepper.setSpeed(10);
}

void loop() {
  control_blinds();
}

void control_blinds() {
  blinds_up_with_switch();
  blinds_down_with_switch();
}

void blinds_up_with_switch() {
  if (digitalRead(SWITCH_UPWARDS) == HIGH)
  {
    Serial.println("UP");
    myStepper.step(50);
  }
}

void blinds_down_with_switch() {
  if (digitalRead(SWITCH_DOWNWARDS) == HIGH)
  {
    Serial.println("DOWN");
    myStepper.step(-50);
  }
}
