#include <SendOnlySoftwareSerial.h>
#include <ArduinoInit.h>

int L0,L1,L2,L3,L4,L5 =0;

void forward();
void reverse();
void right();
void left();
void halt();

void setup() {
configArduino();
attachInterrupt(0,Int_D2_Right,LOW);
attachInterrupt(1,Int_D3_Left,LOW);

motors('1','O',50);
motors('2','O',50);
}

void loop() {
forward();
pause(4300);                                         
halt();
reverse();
pause(1075);
halt();
right();
pause(5000);
halt();
left();
pause(5000);
halt();
}

void forward(){
motors('1','A',40); //1 is right 2 is left
motors('2','A',44);
}

void reverse(){
  motors('1','B',40);
  motors('2','B',40);
  }
void right() {
  motors('1','B',40);
  motors('2','A',40);
  }
void left() {
  motors('1','A',40);
  motors('2','B',40);
  }
void halt() {
  motors('1','O',0);
  motors('2','O',0);
  pause(2000);
  }
 void Int_D2_Right(){
 pause(5);
 if((readInput(2)==1)&& (readInput(3)==1))
    return;
 motors('1','O',0);
 motors('2','O',0);
 pause(150);
 while (readInput(2)==0){
  reverse();
 }
 return;
 } 

void Int_D3_Left(){
  pause(5);
  if((readInput(2)==1)&& (readInput(3)==1))
    return;
  motors('1','O',0);
  motors('2','O',0);
  pause(150);
  while (readInput(2)==0||readInput(3)==0){
  reverse();
 }
 return;
 } 





