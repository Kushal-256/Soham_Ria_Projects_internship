#include "LiquidCrystal_I2C.h"
// Global variables
byte switch_val      = 0;
byte prev_switch_val = 0;
byte reply           = 0; // varies from 0 to 7
const byte SWITCH_PIN = 6; 

LiquidCrystal_I2C Lcd(0x27,16,2);
void setup() {
    Lcd.begin();
    pinMode(SWITCH_PIN, INPUT);
    // intro message
    Lcd.setCursor(0, 0);
    Lcd.print("Ask the");
    Lcd.setCursor(0, 1);
    Lcd.print("Crystal Ball!");
}

void loop() {
    switch_val = digitalRead(SWITCH_PIN);

    if ((switch_val != prev_switch_val) && (switch_val == LOW)) {
        reply = random(8); // randomly choose 1 out of 8 anwers
        Lcd.clear();
        Lcd.setCursor(0, 0);
        Lcd.print("The ball says...");
        delay(3000);
        Lcd.setCursor(0, 1);

        switch (reply) {
            case 0:
                Lcd.print("Absolutely");
                break;
            case 1:
                Lcd.print("Probably");
                break;
            case 2:
                Lcd.print("Maybe");
                break;
            case 3:
                Lcd.print("Yep");
                break;
            case 4:
                Lcd.print("Unsure");
                break;
            case 5:
                Lcd.print("Repeat Again");
                break;
            case 6:
                Lcd.print("Who knows");
                break;
            case 7:
                Lcd.print("Impossible");
                break;
        }
    }
    prev_switch_val = switch_val;
}
