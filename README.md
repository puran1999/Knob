# Knob
Arduino library for optimised control of a rotary encoder.

This library implements one or more rotatry encoders using hardware interrupts (one for each)
The most helpful feature in this release is :
faster rotation  =>  higher increment  , low precesion
slower rotation  =>  smaller increment , high precesion

This is helpful where you need to set different large values with extreme precesion!
the interval vs increment graph is not linear, but optimised exponential, which gives more easy and natural control.

Also provides control over interrupt debounce and maximum Increment.
