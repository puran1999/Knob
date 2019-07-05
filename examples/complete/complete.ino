#include <Knob.h>
Knob knob(2,3);

void interrupt(){
  knob.check();
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), interrupt, CHANGE);
  knob.debounce=20;                  //milliseconds for debounce
  knob.maxIncrement=10;              //when You rotate too fast, maxIncrement is reached (nearly)
  pinMode(4,INPUT_PULLUP);           //any button to reset value
}

void loop() {
  Serial.print(knob.increment);
  Serial.print(',');
  Serial.println(knob.value);
  if(!digitalRead(4))knob.reset();
}
