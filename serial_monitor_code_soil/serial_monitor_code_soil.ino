#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define relayInput 4

int condition = 0 ;
void printText(String msg1 , String msg2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msg1);
  lcd.setCursor(0, 1);
  lcd.print(msg2);
  delay(100);
}
void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  pinMode(relayInput, OUTPUT);
  digitalWrite(relayInput, LOW);
  delay(500);
  printText("IRRIGATION", "SYSTEM IS ON ");
  delay(1000);
  pinMode(2, OUTPUT);
}

void loop() {
  int value = analogRead(36);
  Serial.println(value);
  if (value > 2000 && value < 4000 ) {
    Serial.print("Moisture : LOW ");
    Serial.println("Water Pump is ON ");
    digitalWrite(relayInput, HIGH);
    delay(100);
  }
  else {
    digitalWrite(relayInput, LOW);
    delay(100);
  }

  if (value < 1075) {
    Serial.print("Moisture : HIGH");
    Serial.print("Water Pump is OFF");
    if (condition != 1) {
      printText("Pump is OFF", "Moisture : HIGH");
      digitalWrite(2, LOW);
      condition = 1;
      delay(100);
    }
  } else if (value > 1075 && value < 2000) {
    Serial.print("Water Pump is OFF");
    Serial.print("Moisture : MID ");
    if (condition != 2 ) {
      printText("Pump is OFF", "Moisture : MID");
      digitalWrite(2, LOW);
      delay(100);
      condition = 2;
      delay(100);
    }
  } else if (value > 2000 && value < 4000 ) {
    Serial.print("Moisture : LOW ");
    Serial.println("Water Pump is ON ");
    //    digitalWrite(relayInput, LOW);
    if (condition != 3) {
      printText("Pump is ON", "Moisture :   LOW");
      digitalWrite(2, HIGH);
      condition = 3;
      delay(100);
    }
  }

  else if (value > 4000) {
    if (condition != 4) {
      lcd.clear();
      lcd.setCursor(0, 0);
      digitalWrite(2, LOW);
      printText("Sensor is in Air","");
      condition = 4;
      delay(100);
    }
  }
}
