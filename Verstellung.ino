void verstellung() 
{
if (init1==0)
  {
  initcnt++;
  if (initcnt > 10)
    {
    Serial.println("Jetzt kopieren");
    a = Tgszeita;
    //a = (-18 * Zeit) + 343;
    Serial.println(a);
    Serial.println("fertig kopiert");
    init1 = 1;
    }
  }
else if (avgu > 8 || verstellung_counter > 0)
  {
  verstellung_counter++;
  if (verstellung_counter == 1)
    {
    digitalWrite(33, HIGH); // Servorelais an
    hoehe.attach(22); 
    breite.attach(23); 
    }

  else if (verstellung_counter == 4)
    {
    //breite
    if (((avg0 + avg2) * f) < (avg1 + avg3))
      {
      Serial.println("nach rechts drehen");
      if (a > 0) 
        {
        a--;
        breite.write(a);
        }
      }
    else if (((avg1 + avg3) * f) < (avg0 + avg2))
      {
      Serial.println("nach links drehen"); 
      if (a < 180) 
        {
        a++;
        breite.write(a);
        }
      }
    else
      {
      Serial.println("nichts"); 
      }

    //höhe
    if (((avg0 + avg1) * f) < (avg2 + avg3))
      {
      Serial.println("nach unten");
      if (b < 150) 
        {
        b++;
        hoehe.write(b);
        }
      else if (((avg2 + avg3) * f) < (avg0 + avg1))
        {
        Serial.println("nach oben"); 
        
        if (b > 60) 
          {
          b--;
          hoehe.write(b);
          }
        }
      else
        {
        Serial.println("nichts"); 
        }
      }
    Serial.println(a);
    Serial.println(b);
    } 
  else if (verstellung_counter == 7)
    {
    hoehe.detach();
    breite.detach();     
    verstellung_counter = 0;
    }

  }

}