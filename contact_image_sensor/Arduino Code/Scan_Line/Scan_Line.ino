/*
 6.s063 - Mark Chounlakone, Tianye Chen
 Contact Image Sensor Code

 This code uses a photosensor array to implement a contact image sensor.
 The purpose is to have this contact image sensor act as a proof of concept
 interactive scanner for our 6.s063 final project
 */
#include <Wifi_S08_v2.h>

#define SSID "ESPeezy"
#define PASSWD "MOMENTUM"
#define BLINKPERIOD 100
#define UPDATEPERIOD 100
#define DATAPERIOD 100
#define WIFI false
 
#define DEBUG false
#define NUM_SENSORS 40  
#define MIN_SCAN_TIME 3                       // milliseconds
#define SCAN_PERIOD NUM_SENSORS*MIN_SCAN_TIME    // milliseconds         

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 2

// Initialize LED strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// Encoder variables
int encoder0PinA = 3;
int encoder0PinB = 4;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n = LOW;

// Sensor Array Control pins
// A0 is connected to the ADC pin for reading
const int RCLK = 8;
const int SRCLK = 12;
const int IN = 11;

// Data buffer
float data[NUM_SENSORS]; 

// Declare helper functions
void scan_Line(float buff[], int buff_size, int scan_period);
void toggle_Sensor(int sensor_num);
void registerWrite(int whichPin, int whichState);
void send_Data();

// Wifi Code
ESP8266 wifi = ESP8266(1,false);

String html = "<html></html>";
char header[500];
int val = 0;

int lastupdate = millis();
int blinktime = millis();
int dataupdate = millis();

char html2[500];

bool new_data = true;

void setup() {
  // Set the control pins
  pinMode(RCLK, OUTPUT);
  pinMode(IN, OUTPUT);  
  pinMode(SRCLK, OUTPUT);

  //Setup Encoder pins
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);

  // Serial COM for Debugging
  Serial.begin(9600);
  
  strip.begin();
  strip.show();
  delay(500);
  stripOn();
  if(WIFI){ 
    wifi.begin();
    delay(10);
    wifi.startserver(SSID, PASSWD);
    sprintf(header,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nAccept-Ranges: bytes\n\n", int(html.length()));
  
    wifi.setPage("/",String(header)+html);
  }
}

void loop() {
  if(check_Encoders()){
    scan_Line(data, NUM_SENSORS, SCAN_PERIOD);
    send_Data1();
  }
 
  
}

void scan_Line(float buff[], int buff_size, int scan_period){
  // Scans from left to right 
  // Setup debugging code
  if(DEBUG){
    Serial.println("Scanning");
    Serial.println(1000);
  }

  // Calculate scan time for each sensor
  int min_scan_time = scan_period/buff_size;

  // Loop through all the sensors
  for(int i = 0;i < buff_size; i++){
    // Reset the buffer value
    buff[i] = 0;
    
    // Toggle which sensor is on
    toggle_Sensor(i, buff_size);
    
    // For every sensor, data will be read and averaged over 
    // the scan time
    int start_t = millis();
    int num_samps = 0;
    while(millis() - start_t < min_scan_time){
      buff[i] += analogRead(A0);
      num_samps++;
      delay(1);
    }
    buff[i] = buff[i]/float(num_samps);
    if(DEBUG){
        Serial.println(buff[i]); 
    }
  }
}

void toggle_Sensor(int sensor_num, int num_sensors){
  int num_reg = num_sensors/8;    // Number of registers
  int reg_num = (sensor_num)/8;     // The register that the sensor is controlled by
  int sensor_addr = sensor_num%8;    // The register pin that coresponds to the sensor
  if (reg_num < 0){
    reg_num = 0;
  }
  
  // Write LOW to all registers proceeding the desired one
  for(int i = 0;i < num_reg-1-reg_num;i++){
    registerWrite(0, LOW);
  }
  // Write HIGH to the senors on the desired register
  registerWrite(sensor_addr, HIGH);
  // Write LOW to all registers preceeding the desired one
  for(int i = 0;i < reg_num;i++){
    registerWrite(0, LOW);
  }
}

void registerWrite(int whichPin, int whichState) {
// the bits you want to send
  byte bitsToSend = 0;

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(RCLK, LOW);

  // turn on the next highest bit in bitsToSend:
  bitWrite(bitsToSend, whichPin, whichState);

  // shift the bits out:
  shiftOut(IN, SRCLK, MSBFIRST, bitsToSend);

    // turn on the output so the LEDs can light up:
  digitalWrite(RCLK, HIGH);

}

void send_Data(){
  int m = millis() - lastupdate;
  if(m > UPDATEPERIOD){
    val++;
    if(new_data){
      sprintf(html2,"<html>new\n%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d</html>",data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10],data[11],data[12],data[13],data[14],data[15],data[16],data[17],data[18],data[19],data[20],data[21],data[22],data[23],data[24],data[25],data[26],data[27],data[28],data[29],data[30],data[31],data[32],data[33],data[34],data[35],data[36],data[37],data[38],data[39]);
      new_data = false;
    }else{
      sprintf(html2,"<html>old</html>");
    }
    sprintf(header,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nAccept-Ranges: bytes\n\n", String(html2).length());
    wifi.setPage("/",String(header)+String(html2));
    lastupdate = millis();
  }
}
void send_Data1(){
  String str = "";
  for (int i =0; i < 40; i++){
    str += String(data[i]) + ",";
  }
  Serial.println(str);
  new_data = false;
 }

bool check_Encoders(){
  if(encoder0Pos == 2){
    encoder0Pos = 0;
    return true;
  }else{
    n = digitalRead(encoder0PinA);
    if ((encoder0PinALast == LOW) && (n == HIGH)) {
      if (digitalRead(encoder0PinB) == LOW) {
        //encoder0Pos--;
      } else {
        encoder0Pos++;
      }
    }
    encoder0PinALast = n;
    delay(1);
    return false;
  }
}

void stripOn(){
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i,strip.Color(255,255,255));
  }
  strip.show();
 }
