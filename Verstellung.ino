  void verstellung() {
hoehe.attach(10); 
breite.attach(11); 
/*breite*/
    if (((avg0 + avg2) * f) < (avg1 + avg3))
    {
   Serial.println("nach rechts drehen");
     if (a > 0) {
    a--;
    breite.write(a);
    }
    }
    else if (((avg1 + avg3) * f) < (avg0 + avg2))
    {
     Serial.println("nach links drehen"); 
   if (a < 180) {
    a++;
    breite.write(a);
    }
    }
   else
   Serial.println("nichts"); 


/*höhe*/
    if (((avg0 + avg1) * f) < (avg2 + avg3))
    {
   Serial.println("nach unten");
   
    if (b < 150) {
     b++;
    hoehe.write(b);}
    }
    
    else if (((avg2 + avg3) * f) < (avg0 + avg1))
    {
     Serial.println("nach oben"); 
    
     if (b > 60) {
    b--;
    hoehe.write(b);}
    
    }
    
    else
   Serial.println("nichts"); 

  Serial.println(a);
    Serial.println(b);

     delay(500);
hoehe.attach(7); 
breite.attach(8);
}
