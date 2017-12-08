 /* read a rotary encoder with interrupts
   Encoder hooked up with common to GROUND,
   encoder0PinA to pin 2, encoder0PinB to pin 4 (or pin 3 see below)
   it doesn't matter which encoder pin you use for A or B

   uses Arduino pull-ups on A & B channel outputs
   turning on the pull-ups saves having to hook up resistors
   to the A & B channel outputs

*/

#define encoder0PinA  3
#define encoder0PinB  4

volatile int encoder0PinALast = LOW;
volatile int n;
volatile unsigned int encoder0Pos = 0;
uint32_t t = millis();
uint32_t p = millis();

void setup() {
  pinMode(encoder0PinA, INPUT_PULLUP);
  //digitalWrite(encoder0PinA, HIGH);       // turn on pull-up resistor
  pinMode(encoder0PinB, INPUT_PULLUP);
  //digitalWrite(encoder0PinB, HIGH);       // turn on pull-up resistor

  attachInterrupt(3, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
  Serial.begin (9600);
  Serial.println("start");                // a personal quirk
}

void loop() {
  // do some stuff here - the joy of interrupts is that they take care of themselves
  if(millis()-p > 10){
    Serial.println (encoder0Pos, DEC);
    p = millis();
  }
}

void doEncoder() {
  /* If pinA and pinB are both high or both low, it is spinning
     forward. If they're different, it's going backward.

     For more information on speeding up this process, see
     [Reference/PortManipulation], specifically the PIND register.
  */
  if( millis() - t > 1){
    n = digitalRead(encoder0PinA);
    if ((encoder0PinALast == LOW) && (n == HIGH)) {
      if (digitalRead(encoder0PinB) == LOW) {
        //encoder0Pos--;
      } else {
        encoder0Pos++;
      }
    }
    encoder0PinALast = n;
    t = millis();
  }

  
}

/* See this expanded function to get a better understanding of the
   meanings of the four possible (pinA, pinB) value pairs:
*/
void doEncoder_Expanded() {
  if (digitalRead(encoder0PinA) == HIGH) {   // found a low-to-high on channel A
    if (digitalRead(encoder0PinB) == LOW) {  // check channel B to see which way
      // encoder is turning
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
    else {
      encoder0Pos = encoder0Pos + 1;         // CW
    }
  }
  else                                        // found a high-to-low on channel A
  {
    if (digitalRead(encoder0PinB) == LOW) {   // check channel B to see which way
      // encoder is turning
      encoder0Pos = encoder0Pos + 1;          // CW
    }
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }

  }
  Serial.println (encoder0Pos, DEC);          // debug - remember to comment out
  // before final program run
  // you don't want serial slowing down your program if not needed
}

/*  to read the other two transitions - just use another attachInterrupt()
  in the setup and duplicate the doEncoder function into say,
  doEncoderA and doEncoderB.
  You also need to move the other encoder wire over to pin 3 (interrupt 1).
*/
