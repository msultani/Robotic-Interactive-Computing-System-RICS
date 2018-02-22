#include "mock_arduino.h"
#include <cstdlib>

using namespace std;

void millis_test() {
  unsigned long start = millis();
  cout << "millis() test start: " << start << endl;
  while( millis() - start < 10000 ) {
    cout << millis() << endl;
    sleep(1);
  }
  unsigned long end = millis();
  cout << "End of test - duration: " << end - start << "ms" << endl;
}

void delay_test() {
  unsigned long start = millis();
  cout << "delay() test start: " << start << endl;
  while( millis() - start < 10000 ) {
    cout << millis() << endl;
    delay(250);
  }
  unsigned long end = millis();
  cout << "End of test - duration: " << end - start << "ms" << endl;
}

void run_tests() {
  millis_test();
  delay_test();
}

int main(int argc, char **argv){
  initialize_mock_arduino();
  run_tests();
}