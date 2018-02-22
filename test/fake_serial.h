#pragma once
#include <string>
#include <iostream>

class FakeSerial {
public:
  void begin(unsigned long);
  void end();
  size_t write(const unsigned char*, size_t);
  std::string parseCommand();
};


extern FakeSerial Serial;