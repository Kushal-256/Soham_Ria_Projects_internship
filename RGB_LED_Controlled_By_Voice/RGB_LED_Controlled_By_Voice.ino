//Coded By: Angelo Casimiro (4/27/14)
 //Voice Activated Arduino (Bluetooth + Android)
 //Feel free to modify it but remember to give credit

 String voice;
 int
 led1 = 13, //Connect LED 1 To Pin #13
 led2 = 12, //Connect LED 2 To Pin #12
 led3 = 11; //Connect LED 3 To Pin #11
 
 //--------------------------Call A Function-------------------------------// 
 void blue(){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      
 }
 void green(){
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      
 }
 void red(){
      digitalWrite(led3, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
 }    
 
 void yellow(){
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
 }    
 
 void black(){
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
 }    
 
 void dj(){
      digitalWrite(led3, HIGH);
      delay(1000);
      digitalWrite(led3, LOW);
      delay(1000);
      digitalWrite(led2, HIGH);
      delay(1000);
      digitalWrite(led2, LOW);
      delay(1000);
      digitalWrite(led1, HIGH);
      delay(1000);
      digitalWrite(led1, LOW);
      delay(1000);
      digitalWrite(led3, HIGH);
      delay(1000);
      digitalWrite(led3, LOW);
      delay(1000);
      digitalWrite(led2, HIGH);
      delay(1000);
      digitalWrite(led2, LOW);
      delay(1000);
      digitalWrite(led1, HIGH);
      delay(1000);
      digitalWrite(led1, LOW);
      delay(1000);
      digitalWrite(led3, HIGH);
      delay(1000);
      digitalWrite(led3, LOW);
      delay(1000);
      digitalWrite(led2, HIGH);
      delay(1000);
      digitalWrite(led2, LOW);
      delay(1000);
      digitalWrite(led1, HIGH);
      delay(1000);
      digitalWrite(led1, LOW);
      delay(1000);
      
 }
 //-----------------------------------------------------------------------// 
 void setup() {
   Serial.begin(9600);
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
 
 }
 //-----------------------------------------------------------------------// 
 void loop() {
   while (Serial.available()){  //Check if there is an available byte to read
   delay(10); //Delay added to make thing stable
   char c = Serial.read(); //Conduct a serial read
   if (c == '#') {break;} //Exit the loop when the # is detected after the word
   voice += c; //Shorthand for voice = voice + c
   } 
   if (voice.length() > 0) {
     Serial.println(voice);
 //-----------------------------------------------------------------------//   
   //----------Control Multiple Pins/ LEDs----------// 
        if(voice == "*blue") {blue();}  
   else if(voice == "*green"){green();} 
   else if(voice == "*red") {red();}
   else if(voice == "*yellow") {yellow();}
   else if(voice == "*black") {black();}
   else if(voice == "*DJ mix") {dj();}
  
 voice="";}} //Reset the variable after initiating
