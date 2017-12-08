/*
 Code based on shift register 74HC595 example
 by Tom Igoe

This code is basic test code for our 8 sensor contact image sensor
design. The pins of the shift register are scanned such that sensors
"turn on" from left to right. Each sensor consists of a 47K resistor and
a photoresistor. Each sensor is read for 1 second before the next
sensor is read. 
 */

//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 8;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 12;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 11;

int toggle = 0;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("reset");
}

void loop() {

  //Logic for toggling through pins
  scan();
  registerWrite(8, HIGH);
  registerWrite(8, HIGH);
  registerWrite(8, HIGH);
  registerWrite(8, HIGH);
  if(toggle%8 == 0){
    registerWrite(0, HIGH);
  }else if(toggle%8 == 1){
    registerWrite(1, HIGH);
  }else if(toggle%8 == 2){
    registerWrite(2, HIGH);
  }else if(toggle%8 == 3){
    registerWrite(3, HIGH);
  }else if(toggle%8 == 4){
    registerWrite(4, HIGH);
  }else if(toggle%8 == 5){
    registerWrite(5, HIGH);
  }else if(toggle%8 == 6){
    registerWrite(6, HIGH);
  }else if(toggle%8 == 7){
    registerWrite(7, HIGH);
  }
  //read the current pin for 1 second
  int t = millis();
  while(millis()-t < 1000){
   float val = analogRead(A0);
   Serial.println(val);
   delay(50);
  }

  //move on to the next pin
  toggle++;
}

// This method sends bits to the shift register:

void registerWrite(int whichPin, int whichState) {
// the bits you want to send
  byte bitsToSend = 0;

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchPin, LOW);

  // turn on the next highest bit in bitsToSend:
  bitWrite(bitsToSend, whichPin, whichState);

  // shift the bits out:
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);

    // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);

}
