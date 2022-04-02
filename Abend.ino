void abend() {
  if (uptime > 1500 && r == 0){
    
    hoehe.attach(10); 
    breite.attach(11); 
    
    breite.write(140);
    hoehe.write(140);
    delay(2000);
    hoehe.attach(7); 
    breite.attach(8);
    for(;;){}
    
  }
}
