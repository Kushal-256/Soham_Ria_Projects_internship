#include <SoftwareSerial.h>
SoftwareSerial bt(0,1);
void setup() {
  bt.begin(9600);
  Serial.begin(115200);
  pinMode(13,OUTPUT);

}

void loop() {
  if(bt.available()>0)
  {
    char data = bt.read();
    if (data == 'a')
    {
      //unlock the door  
      digitalWrite(13,HIGH);
      Serial.println("The Door is Unlocked");
      Serial.println(data);
    }
    else if(data == 'b')
    {
      //Lock the door 
      Serial.println("The Door is locked");
      digitalWrite(13,LOW);
       Serial.println(data);
      
    }
  }


}
