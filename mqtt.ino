void mqtt() {
 client.connect("SolarWifi", "Tricor", "urbanus");
 // Serial.println(a);
 // Serial.println(b);
 //  Serial.println("connect done");
    char stringBuffer1[6];
    dtostrf(avgu, 2, 2, stringBuffer1);
    client.publish("avgu",stringBuffer1);

    char stringBuffer2[6];
    dtostrf(a, 2, 2, stringBuffer2);
    client.publish("a",stringBuffer2);

    
    char stringBuffer3[6];
    dtostrf(b, 2, 2, stringBuffer3);
    client.publish("b",stringBuffer3);

    
    char stringBuffer4[6];
    dtostrf(avg0, 2, 2, stringBuffer4);
    client.publish("avg0",stringBuffer4);

    char stringBuffer5[6];
    dtostrf(avg1, 2, 2, stringBuffer5);
    client.publish("avg1",stringBuffer5);


    char stringBuffer6[6];
    dtostrf(avg2, 2, 2, stringBuffer6);
    client.publish("avg2",stringBuffer6);

    char stringBuffer7[6];
    dtostrf(avg3, 2, 2, stringBuffer7);
    client.publish("avg3",stringBuffer7);

  
}
