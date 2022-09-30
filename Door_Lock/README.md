# Bluetooth Controlled Door Lock #

Things To Remember Before Working With This Activity

1) We have the use an external power supply of  12v power pin to the arduino or we can use the battery eliminator and connect to the relay and solenoid lock .
(Note: Solenoid lock doesn't work with less than 12v power ).
2) Pins
   - Bluetooth module:
    - Vcc  -  5v
    - Gnd - Gnd
    - Tx    -  Rx
    - Rx   -	 Tx
    
    - Relay 1 channel 5v
    *(Low power pins)
    - Vcc   -  5v
    - Gnd   -  Gnd
    - IN1(Signal_pin) - 13
    
     *(High power pins)
    -Gnd (Solenoid) - Gnd (Battery)
    -Positive (Solenoid) - C  (Relay)
    -Positive (Battery) -  NC (Relay)
