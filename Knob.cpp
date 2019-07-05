/*
  Knob.h - Library for rotary encoders.
  Created by Puran Singh, July 5, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Knob.h"

Knob::Knob(int pin1, int pin2)
{
	pinMode(pin1, INPUT_PULLUP);
	pinMode(pin2, INPUT_PULLUP);
	_pin1=pin1;
	_pin2=pin2;
	_times[0]=1000;
	_times[1]=1000;
	_times[2]=1000;
	_times[3]=1000;
	_times[4]=1000;
	debounce = 20;
	maxIncrement = 10;
	increment = 1;
}

void Knob::check()
{
	if(millis()-_t > debounce)
	{
		_updateArray(_times,millis()-_t);
		_t = millis();
		increment = int((maxIncrement*4/3)*exp(-_sum(_times)/500.0));
		if(increment==0)increment = 1;
		if(digitalRead(_pin1)!=digitalRead(_pin2)) value+=increment;
		else value-=increment;
	}
}
void Knob::_updateArray(int arr[5], int tim)
{
  arr[0]=arr[1];
  arr[1]=arr[2];
  arr[2]=arr[3];
  arr[3]=arr[4];
  arr[4]=tim;
}
int Knob::_sum(int arr[5])
{
  return arr[0]+arr[1]+arr[2]+arr[3]+arr[4];
}
void Knob::reset()
{
	value = 0;
}
