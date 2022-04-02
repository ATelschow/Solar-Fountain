#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspUdp.h>
#include "SoftwareSerial.h"
#include <PubSubClient.h>
#include <Servo.h> 

Servo breite;
Servo hoehe;

IPAddress server(192, 168, 178, 66);
char ssid[] = "FRITZ!Box Fon WLAN 7270";          
char pass[] = "32548AE9ZQ234RS42";           
int status = WL_IDLE_STATUS;

int a = 140;
int b = 140;
float f = 1.3;
const int ldr0=A0;
const int ldr1=A1;
const int ldr2=A2;
const int ldr3=A3;
int avg0 = 0;
int avg1 = 0;
int avg2 = 0;
int avg3 = 0;
int k = 0;
float u = 0;
float avgu = 0;

int r = 0;
int uptime;


void callback(char* topic, byte* payload, unsigned int length) {}

WiFiEspClient espClient;
PubSubClient client(server, 1885, callback, espClient);
SoftwareSerial soft(2,3); // RX, TX

void setup() {
  Serial.begin(115200);
  soft.begin(9600);
  WiFi.init(&soft);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
  Serial.println("WiFi shield not present");
  }

  // attempt to connect to WiFi network
  if (WiFi.status() != WL_CONNECTED) {
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  pinMode(ldr0, INPUT);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(12, OUTPUT);
    hoehe.attach(10); 
    breite.attach(11); 
    
    breite.write(140);
    hoehe.write(140);
    delay(2000);
    hoehe.attach(7); 
    breite.attach(8);
  
}


void loop() {
  //checkwifi();
  mittelwertbildung();
  relais();
  verstellung();
  delay(200);
  mqtt();
  delay(5000);
  abend ();
  wifirec();
  uptime++; 
 // reconnect();




}



 
