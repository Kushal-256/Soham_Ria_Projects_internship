
#include<Servo.h>
Servo myservo;
int pos = 0;
long time;

#define en1 5
#define en2 6
int M1_Speed = 100; // speed of motor 1
int M2_Speed = 100; // speed of motor 2

#define LEFT A0
#define RIGHT A1


const int in1 = 7;
const int in2 = 8;
const int in3 = 9;
const int in4 = 10;

const int trigPin = 11;
const int echoPin = 12;

long duration;
int min_distance = 10;
int distance;
const int max_distance = 25;

void setup() {

 myservo.attach(13);

for(pos = 90; pos <= 180; pos += 1){
myservo.write(pos);
delay(15);
}
 
for(pos = 180; pos >= 0; pos-= 1) {
myservo.write(pos);
delay(15);
}

for(pos = 0; pos<=90; pos += 1) {
myservo.write(pos);
delay(15);
}

//  pinMode(en1,OUTPUT);
//  pinMode(en2,OUTPUT);
  
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);

  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() {
 digitalWrite(trigPin,LOW);
 delay(2);

 digitalWrite(trigPin,HIGH);
 delay(10);
 digitalWrite(trigPin,LOW);

 duration = pulseIn(echoPin,HIGH);
 distance = (duration*0.034/2);
 Serial.print("Distance: ");
 Serial.println(distance);


 int Right_Value = digitalRead(RIGHT);
int Left_Value = digitalRead(LEFT);

Serial.print("RIGHT");
Serial.println(Right_Value);
Serial.print("LEFT");
Serial.println(Left_Value);

//Forward
if((Right_Value==1)&&(Left_Value==1)  && ((distance>=1) && (distance<=max_distance)))
 {
  if (distance < 10){
    digitalWrite(in1,LOW);
 digitalWrite(in2,LOW);
 digitalWrite(in3,LOW);
 digitalWrite(in4,LOW);
  }
  
  else {
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
  }
//      analogWrite(en1, M1_Speed);
//      analogWrite(en2, M2_Speed);
  }
  
//  Right Turn
else if((Right_Value==0) && (Left_Value==1)) 
{
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 
//      analogWrite(en1, M1_Speed);
//      analogWrite(en2, M2_Speed);
 }

// Left Turn
else if((Right_Value==1)&&(Left_Value==0)) 
{
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
// 
//      analogWrite(en1, M1_Speed);
//      analogWrite(en2, M2_Speed);
 }
 
// Stop
else if(((Right_Value==1)&&(Left_Value==1)) && ((distance > 25 && distance < 1000)))
{
 digitalWrite(in1,LOW);
 digitalWrite(in2,LOW);
 digitalWrite(in3,LOW);
 digitalWrite(in4,LOW);
}
//else{
//// else if(distance > 1 && distance < 10) {
// digitalWrite(in1,LOW);
// digitalWrite(in2,LOW);
// digitalWrite(in3,LOW);
// digitalWrite(in4,LOW);
// 
//}
 }
