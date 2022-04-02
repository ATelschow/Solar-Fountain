void abend() {
  if (a < 20 && avgu < 5.5){
    
 hoehe.attach(22); 
breite.attach(23); 
delay(300);
    
    breite.write(180);
    hoehe.write(140);
    delay(5000);
  hoehe.detach();
 breite.detach();   
 delay (5000);
      client.connect("SolarWifi", "Tricor", "urbanus");
    client.publish("Solstate", "Abendroutine durchgeführt, gute Nacht!");
   while (dn < 9999){
   delay (5000);
   dn++;}
    
  }
}
