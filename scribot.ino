#include <Servo.h>
#include <math.h>

Servo ser1;
Servo ser2;

double aDeg, eDeg, bDeg;

double radDeg(double x){
  return x*180/PI;
}

void inv(double x, double y){
  double bc = sqrt(x*x+y*y);
  double a = acos((61-bc*bc)/60);
  double e = atan(y/x);
  double b = asin((6*sin(a))/bc);
  aDeg = radDeg(a);
  eDeg = radDeg(e);
  bDeg = radDeg(b);
}

void invServo(double x, double y){
  inv(x,y);
  ser1.write(bDeg + eDeg);
  ser2.write(aDeg);
  delay(500);
}

void L(){
  invServo(7,8);
  delay(10000);
  invServo(7,7);
  invServo(7,6);
  invServo(8,6);
  invServo(9,6);
}

void N(){
  invServo(7,6);
  delay(10000);
  invServo(7,7);
  invServo(8,6);
  invServo(8,7);
}


void V(){
  invServo(6,7);
  delay(10000);
  invServo(7,6);
  invServo(8,7);
}

void setup() {
  // put your setup code here, to run once:
  ser1.attach(8);
  ser2.attach(7);
  Serial.begin(9600);
  L();
//ser1.write(0);
//ser2.write(0);
//  M();
//  N();
//V();
  delay(100);
  ser1.detach();
  ser2.detach();
}

void loop() {
}
