#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Servo.h> 

Servo breite;
Servo hoehe;

IPAddress server(192, 168, 178, 66);
char ssid[] = "FRITZ!Box Fon WLAN 7270";          
char pass[] = "32548AE9ZQ234RS42";           
int status = WL_IDLE_STATUS;

int a = 110;
int b = 110;
float f = 1.2;
int avg0 = 0;
int avg1 = 0;
int avg2 = 0;
int avg3 = 0;
int k = 0;
float u = 0;
float avgu = 0;
int dn = 0;

int r = 0;
int uptime = 0;
int z = 0;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Nachricht eingetroffen [");
  Serial.print(topic);
  Serial.print("]: ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

WiFiClient espClient;
PubSubClient client(server, 1885, callback, espClient);


void reconnect() {
  // Solange wiederholen bis Verbindung wiederhergestellt ist
  while (!client.connected()) {
    Serial.print("Versuch des MQTT Verbindungsaufbaus...");
client.connect("SolarWifi", "Tricor", "urbanus");
      
    //Verbindungsversuch:
    if (client.connect("SolarWifi")) {
      Serial.println("Erfolgreich verbunden!");
      // Nun versendet der Arduino eine Nachricht in outTopic ...
      client.publish("Sol","Aufgewacht");


      // und meldet sich bei inTopic für eingehende Nachrichten an:
      client.subscribe("inTopic");
    } else { // Im Fehlerfall => Fehlermeldung und neuer Versuch
      Serial.print("Fehler, rc=");
      Serial.print(client.state());
      Serial.println(" Nächster Versuch in 5 Sekunden");
      // 5 Sekunden Pause vor dem nächsten Versuch
     // delay(5000);
    }}}



void setup() {
  Serial.begin(115200);



client.setServer(server, 1885); // Adresse des MQTT-Brokers
  client.setCallback(callback);   // Handler für eingehende Nachrichten



 
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  

  pinMode(36, INPUT);
  pinMode(39, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(17, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(33, OUTPUT);


  client.connect("SolarWifi", "Tricor", "urbanus");
  client.publish("Solstate","Aufgewacht");

 
}


void loop() {
 // if (!client.connected()) {
 //   reconnect();
 // }
  client.loop();

  mittelwertbildung();
  checkwifi();
  relais();
  mqtt();
  abend ();
  if (avgu > 8) {
  verstellung();}
  
  z=0;
  while (z < 50){
    delay(10);
    client.loop();
    z++;
  }
  

 wifirec();
  uptime++;
 //reconnect();*/
}



 
