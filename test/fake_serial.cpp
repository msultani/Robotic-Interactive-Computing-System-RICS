#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

#include "fake_serial.h"

void FakeSerial::begin(unsigned long speed) {
  return;
}

void FakeSerial::end() {
  return;
}

size_t FakeSerial::write( const unsigned char buf[], size_t size ) {
  using namespace std;
  ios_base::fmtflags oldFlags = cout.flags();
  streamsize oldPrec = cout.precision();
  char oldFill = cout.fill();
  
  cout << "Serial::write: ";
  cout << internal << setfill('0');

  for( unsigned int i = 0; i < size; i++ ){
    cout << setw(2) << hex << (unsigned int)buf[i] << " ";
  }
  cout << endl;
  
  cout.flags(oldFlags);
  cout.precision(oldPrec);
  cout.fill(oldFill);

  return size;
}

bool commandHasErrors(std::string command) {
  for (int i = 1; i < command.length(); ++i) {
    if (std::isdigit(command[i])) {
      return false;
    }
  }
  return true;
}

std::string FakeSerial::parseCommand() {
    std::string command = "";
    bool serial_available = true;
  while (serial_available) {
    // Take in leading command character
    char input = 'h';
    std::cout << "Read in: " << input << "\n";

    if (input == 'X') {
      break;
    } else {
      command += input;
    }
    
    // Maximum command size: 4 characters (Command number + 3 digits of an angle)
    if (command.length() > 4) {
      return "";
    }
  }
  std::cout << "Complete Command: " << command << "\n";


  if (commandHasErrors(command)) {
    return "";
  } else {
    return command;
  }

}

FakeSerial Serial;