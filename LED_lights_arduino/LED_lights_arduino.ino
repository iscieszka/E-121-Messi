#include <SendOnlySoftwareSerial.h>
#include <ArduinoInit.h>

void setup() {
configArduino();
}

void loop() {
 outputHigh(10);
 outputHigh(11);
 pause(1000);
 outputLow(10);
 outputLow(11);
 pause(1000);

}
