#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define relayInput 4

int condition = 0 ; 
void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  pinMode(relayInput, OUTPUT);
  digitalWrite(relayInput, HIGH);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("IRRIGATION");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM IS ON ");
  lcd.print("");
 delay(2000);
 pinMode(2,OUTPUT);
  lcd.clear();
}
 
void loop() {
  int value = analogRead(A0);
  Serial.println(value);
   if (value > 2000 && value < 4000 ) {
    Serial.print("Moisture : LOW ");
    Serial.println("Water Pump is ON ");
    digitalWrite(relayInput, LOW);
    delay(50);
  }
  else{
     digitalWrite(relayInput, HIGH);
         delay(50);
  }


  
  if (value < 1075) {
     Serial.print("Moisture : HIGH");
     Serial.print("Water Pump is OFF");
    if (condition != 1){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pump is OFF");
    delay(100);
    lcd.setCursor(1, 1);
    lcd.print("Moisture : HIGH");
    delay(100);
//    digitalWrite(relayInput, HIGH);
    digitalWrite(2,LOW);
      delay(100);
      condition = 1;
    }
  } else if (value > 1075 && value < 2000) {
     Serial.print("Water Pump is OFF");
      Serial.print("Moisture : MID ");
     if (condition != 2 ){
     lcd.clear();
      lcd.setCursor(0, 0);
    lcd.print("Moisture : MID");
    delay(100);
    lcd.setCursor(1, 1);
    lcd.print("Pump is OFF");
    delay(100);
//   digitalWrite(relayInput, HIGH);
    digitalWrite(2,LOW);
     delay(100);
     condition = 2;
      }
  } else if (value > 2000 && value < 4000 ) {
    Serial.print("Moisture : LOW ");
    Serial.println("Water Pump is ON ");
//    digitalWrite(relayInput, LOW);
    if (condition != 3){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pump is ON ");
    delay(200);
    digitalWrite(2,HIGH);
    lcd.setCursor(1, 1);
    lcd.print("Moisture :LOW");
    delay(200);
    condition = 3;
    }
  }
  
  else if(value > 4000){
    if (condition != 4){
    lcd.clear();
    lcd.setCursor(0,0);
    digitalWrite(2,LOW);
    
    lcd.print("Sensor is in Air");
    delay(500);
    condition = 4; 
    }
  }
}
