#include<Servo.h>
Servo Sb;

void setup() {
  // put your setup code here, to run once:
Serial1.begin(9600);
Sb.attach(10);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
}
int base=0;    // 0 to 180

void loop() {
  // put your main code here, to run repeatedly:

Sb.write(base);

char a;
a=Serial1.read();

{
if(a=='1')           //Counter Clock Wise rotation
{
  Sb.write(base+5);
  base=base+5;
}
else if(a=='2')      //Clock Wise rotation
{
  Sb.write(base-5);
  base=base-5;
}
}
if(a=='3')           //UP
{
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
}
else if(a=='4')     //DOWN
{
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
}
else if(a=='5')     //STOP
{
digitalWrite(8,LOW);
digitalWrite(9,LOW);
}
}