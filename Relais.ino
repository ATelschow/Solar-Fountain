void relais() {
if (r == 0 && avgu > 13){
  digitalWrite(17, HIGH);
  r = 1;
  Serial.println("Relais an");
   client.connect("SolarWifi", "Tricor", "urbanus");
    client.publish("Solstate", "Relais an");
}
if (r == 1 && avgu < 8){
  digitalWrite(17, LOW);
  r = 0;
  Serial.println("Relais aus");
     client.connect("SolarWifi", "Tricor", "urbanus");
    client.publish("Solstate", "Relais aus");
  }
   Serial.print("r=");
   Serial.println(r);
}
