#pragma once

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define lowByte(w) ((unsigned char) ((w) & 0xff))
#define highByte(w) ((unsigned char) ((w) >> 8))

typedef unsigned char byte;
typedef unsigned short int word;

unsigned long millis();
void delay(unsigned long ms);
unsigned long millis();

// WMath.cpp
long map(long, long, long, long, long);

void initialize_mock_arduino(); 

#include "fake_serial.h"