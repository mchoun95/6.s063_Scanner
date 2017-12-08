#include <Wifi_S08_v2.h>

#define SSID "ESPeezy"
#define PASSWD "MOMENTUM"
#define BLINKPERIOD 100
#define UPDATEPERIOD 100
#define DATAPERIOD 100

ESP8266 wifi = ESP8266(1,true);

String html = "<html>\n<title>It works!</title>\n<body>\n<h1>Congrats</h1>\n<p>You have successfully interneted.</p>\n</body>\n</html>";
char header[500];
int val = 0;

int lastupdate = millis();
int blinktime = millis();
int dataupdate = millis();

char html2[500];

void setup() {
  Serial.begin(115200);
  wifi.begin();
  Serial.println("startserver");
  wifi.startserver(SSID, PASSWD);
  Serial.println("setup complete");
  sprintf(header,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nAccept-Ranges: bytes\n\n", int(html.length()));

  wifi.setPage("/",String(header)+html);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println((millis()-lastupdate));
  int m = millis() - lastupdate;
  if(m > UPDATEPERIOD){
    val++;
    sprintf(html2,"<html>\n<title>It works!</title>\n<body>\n<h1>Congrats</h1>\n<p>You have successfully interneted %d times.</p>\n</body>\n</html>",val);
    sprintf(header,"HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %d\nAccept-Ranges: bytes\n\n", html.length());
    wifi.setPage("/",String(header)+String(html2));
    lastupdate = millis();
  }
  m = millis() - dataupdate;
  if(m > DATAPERIOD && wifi.hasData()){
     String data = wifi.getData();
     if (data != ""){
     Serial.print("data: ");
     Serial.println(data);
     
     }
  }
}
