void relais() 
{
if (r == 0 && avgu > 11)
  {
  digitalWrite(17, HIGH);
  r = 1;
  Serial.println("Relais an");
  client.publish(MQTTstatus, "Relais an");
  }
if (r == 1 && avgu < 8){
  digitalWrite(17, LOW);
  r = 0;
  Serial.println("Relais aus");
  client.publish(MQTTstatus, "Relais aus");
  }

}
