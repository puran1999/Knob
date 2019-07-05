/*
  Knob.h - Library for rotary encoders.
  Created by Puran Singh, July 5, 2019.
  Released into the public domain.
*/
#ifndef Knob_h
#define Knob_h

#include "Arduino.h"

class Knob
{
  public:
    Knob(int pin1, int pin2);
	int debounce;
	int value;
	int increment;
	int maxIncrement;
    void reset();
    void check();
  private:
    int _times[5] = {1000,1000,1000,1000,1000};
    void _updateArray(int arr[5], int tim);
    int _sum(int arr[5]);
	int _pin1;
	int _pin2;
	int _t;
};

#endif