/*
Created by Puran Singh, July 5, 2019.
Released into the public domain.

This library implements one or more rotatry encoders using hardware interrupts (one for each)
The most helpful feature in this release is :
faster rotation  =>  higher increment  , low precesion
slower rotation  =>  smaller increment , high precesion

This is helpful where you need to set different large values with extreme precesion!
the interval vs increment graph is not linear, but optimised exponential, which gives more easy and natural control.
Try this program! and check yourself!
*/

#include <Knob.h>
Knob knob(2,3);

void interrupt(){
  knob.check();
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), interrupt, CHANGE);
}
void loop() {
  Serial.println(knob.value);
}
