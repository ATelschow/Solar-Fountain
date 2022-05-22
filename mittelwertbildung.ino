void mittelwertbildung(){
  avg0 = 0;
  avg1 = 0;
  avg2 = 0;
  avg3 = 0;
  avgu = 0;
  while (k < 30)
    {
    int value0 = analogRead(36);
    avg0 = avg0 + value0;
    int value1 = analogRead(39);
    avg1 = avg1 + value1;
    int value2 = analogRead(34);
    avg2 = avg2 + value2;
    int value3 = analogRead(35);
    avg3 = avg3 + value3;
    u = analogRead(32);
    avgu = avgu + u;
    k++;
    }
  k=0;
  avg0= avg0 / 30* 0.94;
  avg1= avg1 / 30*1.04;
  avg2= avg2 / 30*1;
  avg3= avg3 / 30 *1.17;
  avgu= avgu / 30 / 197.13 ;
 
  // Serial.println("Analog Value :");
  // Serial.println(avg0);
  // Serial.println(avg1);
  // Serial.println(avg2); 
  // Serial.println(avg3);
  // Serial.println(avgu);
  }
